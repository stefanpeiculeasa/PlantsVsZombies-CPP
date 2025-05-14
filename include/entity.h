//
// Created by alfredo on 4/24/25.
//

#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "utils.h"
#include <cstdlib>
#include <ctime>

class Grid;

class Entity {
protected:
    int x, y;
    int health;
    int ticks;
    int maxTicks;
    int damage;
    bool deletionMark = false;
    bool canMove = true;
    std::string name;
    std::vector<std::unique_ptr<Entity>> childEntities;
    sf::RectangleShape hitbox;
public:
    Entity(int x,int y,int health,std::string name,int ticks,int damage,int scale);

    virtual void update(Grid& grid) = 0;

    virtual void takeDamage(int damage);

    [[nodiscard]] std::string getName();
    [[nodiscard]] bool getDeletionMark() const;
    [[nodiscard]] std::pair<int, int> getPosition();
    [[nodiscard]] sf::RectangleShape& getHitbox();
    [[nodiscard]] int getDamage() const;

    void setCanMove(bool canMove);
    void setDeletionMark(bool deletionMark);

    virtual void die() {}

    virtual ~Entity() = default;
};

#endif //ENTITY_H
