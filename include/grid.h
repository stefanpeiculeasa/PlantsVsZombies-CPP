#ifndef GRID_H
#define GRID_H

#include "entity.h"
#include "unordered_map"
#include "entityfactory.h"
#include "utils.h"

class Grid {

    std::vector<std::unique_ptr<Entity>> entities;
    std::vector<std::unique_ptr<Entity>> toAdd;
    int sun = 20;
    int playerHp = 100;
    std::unordered_map<std::string, std::vector<std::pair<sf::Vector2i, bool>>> keyCoords = GameUtils::keyCoords;
    std::string selectedPlant = "peashooter";
    //EntityFactory entityFactory;

public:
    void addEntity(std::unique_ptr<Entity> entity);

    void update();

    std::vector<std::unique_ptr<Entity>>& getEntities();
    [[nodiscard]] int getSun() const;
    [[nodiscard]] int getPlayerHp() const;
    [[nodiscard]] std::string getSelectedPlant() const;
    void takeDamage(int dmg);
    void decSun(int Sun);
    void addSun(int Sun);
    void updateCoords(const std::unordered_map<std::string, std::vector<std::pair<sf::Vector2i, bool>>> &coords);
    std::unordered_map<std::string, std::vector<std::pair<sf::Vector2i, bool>>>& getCoords();
    void handleClick(sf::Vector2f mousePos);
    void handleKeyPress(sf::Keyboard::Key Key);

    ~Grid() = default;
};


#endif //GRID_H
