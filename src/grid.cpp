#include "grid.h"
#include "plant.h"

void Grid::addEntity(std::unique_ptr<Entity> entity) {
    if (const auto* pPtr = dynamic_cast<Plant*>(entity.get())) {
        if (sun >= pPtr->getCost()) {
            sun -= pPtr->getCost();
        }
        else return;
    }
    toAdd.push_back(move(entity));
}

void Grid::update(std::unordered_map<std::string, std::vector<std::pair<sf::Vector2i, bool>>> &keyCoords) {
    for (auto it = entities.begin(); it != entities.end();) {
        
        (*it)->update(*this);

        if ((*it)->getDeletionMark()) {
            it = entities.erase(it);
        } else ++it;
    }

    entities.insert(entities.end(),std::make_move_iterator(toAdd.begin()),std::make_move_iterator(toAdd.end()));
    toAdd.clear();
}

std::vector<std::unique_ptr<Entity>>& Grid::getEntities() {
    return entities;
}

int Grid::getSun() const {
    return sun;
}

int Grid::getPlayerHp() const {
    return playerHp;
}

void Grid::takeDamage(int dmg) {
    playerHp -= dmg;
}

void Grid::decSun(int sun) {
    this->sun -= sun;
}

void Grid::addSun(int sun) {
    this->sun += sun;
}

void Grid::updateCoords(const std::unordered_map<std::string, std::vector<std::pair<sf::Vector2i, bool>>> &keyCoords) {
    this->keyCoords = keyCoords;
}

std::unordered_map<std::string, std::vector<std::pair<sf::Vector2i, bool>>>& Grid::getCoords() {
    return keyCoords;
}

// void Grid::handleClick(sf::Vector2i mousePos) {
//
// }
