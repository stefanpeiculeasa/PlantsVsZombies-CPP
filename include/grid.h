#ifndef GRID_H
#define GRID_H

#include "entity.h"
#include "unordered_map"
#include "entityfactory.h"
#include "utils.h"

class Grid {

    std::vector<std::unique_ptr<Entity>> entities;
    std::vector<std::unique_ptr<Entity>> toAdd;
    int sun = Settings::startingSun;
    int playerHp = Settings::playerHealth ;
    int zombiesAmount = Settings::random(Settings::spawnAmount.first,Settings::spawnAmount.second);
    int zombieSpawnTicks = Settings::random(Settings::spawnInterval.first * Settings::fps, Settings::spawnInterval.second * Settings::fps);
    std::unordered_map<std::string, std::vector<std::pair<sf::Vector2i, bool>>> keyCoords = Settings::keyCoords;
    std::string selectedPlant = Settings::defaultPlant;

public:
    explicit Grid(const int sun = Settings::startingSun,const int hp = Settings::playerHealth,const int zombies = Settings::random(15,30)) : sun(sun), playerHp(hp), zombiesAmount(zombies) {}

    void addEntity(std::unique_ptr<Entity> entity);

    void update();

    std::vector<std::unique_ptr<Entity>>& getEntities();
    std::unordered_map<std::string, std::vector<std::pair<sf::Vector2i, bool>>>& getCoords();
    [[nodiscard]] int getSun() const;
    [[nodiscard]] int getPlayerHp() const;
    [[nodiscard]] int getZombiesAmount() const;
    [[nodiscard]] std::string getSelectedPlant() const;
    void takeDamage(int dmg);
    void decSun(int Sun);
    void addSun(int Sun);
    void updateCoords(const std::unordered_map<std::string, std::vector<std::pair<sf::Vector2i, bool>>> &coords);
    void handleClick(sf::Vector2f mousePos);
    void handleKeyPress(sf::Keyboard::Key Key);

    ~Grid() = default;
};


#endif //GRID_H
