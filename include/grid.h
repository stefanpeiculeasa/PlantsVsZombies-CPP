#ifndef GRID_H
#define GRID_H

#include "entity.h"
#include "plant.h"

class Grid {

    std::vector<std::unique_ptr<Entity>> entities;
    std::vector<std::unique_ptr<Entity>> toAdd;
    int sun = 20;
    int playerHp = 100;
    std::unordered_map<std::string, std::vector<std::pair<sf::Vector2i, bool>>> keyCoords;

public:
    void addEntity(std::unique_ptr<Entity> entity);

    void update(std::unordered_map<std::string, std::vector<std::pair<sf::Vector2i, bool>>>& keyCoords);

    std::vector<std::unique_ptr<Entity>>& getEntities();
    [[nodiscard]] int getSun() const;
    [[nodiscard]] int getPlayerHp() const;
    void takeDamage(int dmg);
    void decSun(int sun);
    void addSun(int sun);
    void updateCoords(std::unordered_map<std::string, std::vector<std::pair<sf::Vector2i, bool>>> keyCoords);
    std::unordered_map<std::string, std::vector<std::pair<sf::Vector2i, bool>>>& getCoords();
    void handleClick(sf::Vector2i mousePos);

    ~Grid() = default;
};


#endif //GRID_H
