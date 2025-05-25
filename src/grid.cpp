#include "grid.h"
#include <iostream>
#include "plant.h"
#include "sun.h"
#include "entityfactory.h"
#include "exceptions.h"

void Grid::addEntity(std::unique_ptr<Entity> entity) {
    if (const auto* pPtr = dynamic_cast<Plant*>(entity.get())) {
        if (sun >= pPtr->getCost()) {
            sun -= pPtr->getCost();
        }
        else return;
    }
    toAdd.push_back(std::move(entity));
}

void Grid::update() {
    zombieSpawnTicks -= 1;
    if (zombieSpawnTicks == 0) {
        entities.push_back(EntityFactory::createBasicZombie(1500,Settings::rows[Settings::random(0,static_cast<int>(Settings::rows.size()-1))]));
        zombiesAmount -= 1;
        zombieSpawnTicks = Settings::random(Settings::spawnInterval.first * Settings::fps, Settings::spawnInterval.second * Settings::fps);
    }

    for (auto it = entities.begin(); it != entities.end();) {
        
        (*it)->update(*this);

        if ((*it)->getDeletionMark()) {
            if (dynamic_cast<Plant*>(it->get())) {
                for (auto& center : keyCoords["tileCenters"]) {
                    if (center.first.x == (*it)->getPosition().first && center.first.y == (*it)->getPosition().second) {
                        center.second = false;
                    }
                }
            }
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

int Grid::getZombiesAmount() const {
    return zombiesAmount;
}


std::string Grid::getSelectedPlant() const {
    return selectedPlant;
}

void Grid::takeDamage(const int dmg) {
    playerHp -= dmg;
}

void Grid::decSun(const int Sun) {
    this->sun -= Sun;
}

void Grid::addSun(const int Sun) {
    this->sun += Sun;
}

void Grid::updateCoords(const std::unordered_map<std::string, std::vector<std::pair<sf::Vector2i, bool>>> &coords) {
    this->keyCoords = coords;
}

std::unordered_map<std::string, std::vector<std::pair<sf::Vector2i, bool>>>& Grid::getCoords() {
    return keyCoords;
}

void Grid::handleClick(const sf::Vector2f mousePos) {
    bool clicked = false;
    const float clickBoxSize = static_cast<float>(keyCoords["hitboxSize"][0].first.x);
    // sun check
    for (auto& entity : entities) {
        if (dynamic_cast<Sun*>(entity.get())) {
            const sf::Vector2f sunPos = entity->getHitbox().getPosition();

            sf::FloatRect clickBox(
                sunPos.x - clickBoxSize / 2.f,
                sunPos.y - clickBoxSize / 2.f,
                clickBoxSize,
                clickBoxSize
            );

            if (clickBox.contains(mousePos)) {
                entity->setDeletionMark(true);
                addSun(Settings::sunValue);
                clicked = true;
                break;
            }
        }
    }

    for (auto& center : keyCoords["tileCenters"]) {
        const sf::Vector2f scaledCenter(static_cast<float>(center.first.x), static_cast<float>(center.first.y));

        if (sf::FloatRect clickBox(scaledCenter.x - clickBoxSize / 2,scaledCenter.y - clickBoxSize / 2,clickBoxSize,clickBoxSize); clickBox.contains(mousePos)) {
            if (center.second) break;
            clicked = true;
            if (selectedPlant == "peashooter") {
                addEntity(EntityFactory::createPeashooter(center.first.x,center.first.y));
            } else if (selectedPlant == "wallnut") {
                addEntity(EntityFactory::createWallnut(center.first.x,center.first.y));
            } else if (selectedPlant == "sunflower") {
                addEntity(EntityFactory::createSunflower(center.first.x,center.first.y));
            } else break;
            center.second = true;
            break;
        }
    }
    try {
        if (!clicked) {
            throw InvalidClickPosition();
        }
    } catch (const InvalidClickPosition& e) {
        std::cout << e.what() << std::endl;
    }
}

void Grid::handleKeyPress(const sf::Keyboard::Key Key) {
    switch (Key) {
        case sf::Keyboard::Num1:
            selectedPlant = "peashooter";
            break;
        case sf::Keyboard::Num2:
            selectedPlant = "wallnut";
            break;
        case sf::Keyboard::Num3:
            selectedPlant = "sunflower";
            break;
        default: break;
    }
}
