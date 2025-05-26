//
// Created by alfredo on 4/24/25.
//

#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "stat.h"

class Grid;

class Entity {
protected:
    Stat<int> x, y;
    Stat<int> health;
    Stat<int> ticks;
    Stat<int> maxTicks;
    Stat<int> damage;
    Stat<bool> deletionMark = false;
    Stat<bool> canMove = true;
    Stat<std::string> name;
    std::vector<std::unique_ptr<Entity>> childEntities;
    sf::RectangleShape hitbox;
public:
    Entity(int x,int y,int health,std::string name,int ticks,int damage);

    Entity(int x,int y,std::string name);

    Entity(const Entity& other);

    Entity& operator=(const Entity& other);

    friend std::ostream& operator<<(std::ostream& os, const Entity& Entity);
    friend std::istream& operator>>(std::istream& is, Entity& Entity);

    virtual void update(Grid& grid) = 0;

    virtual void takeDamage(int dmg);

    [[nodiscard]] std::string getName() const;
    [[nodiscard]] bool getDeletionMark() const;
    [[nodiscard]] std::pair<int, int> getPosition() const;
    [[nodiscard]] sf::RectangleShape& getHitbox();
    [[nodiscard]] int getDamage() const;

    void setCanMove(bool canmove);
    void setDeletionMark(bool mark);

    virtual void die() {}

    virtual ~Entity() = default;
};

#endif //ENTITY_H
