#include "entity.h"
#include <iostream>
#include <utility>
#include "utils.h"

Entity::Entity(const int x,const int y,const int health, std::string name,const int ticks,const int damage) : x(x),y(y),health(health),ticks(ticks),maxTicks(ticks),damage(damage),name(std::move(name)) {
    hitbox.setSize(sf::Vector2f(static_cast<float>(Settings::keyCoords["hitboxSize"][0].first.x),static_cast<float>(Settings::keyCoords["hitboxSize"][0].first.y)));
    hitbox.setScale(2.f,2.f);
    hitbox.setPosition(static_cast<float>(x),static_cast<float>(y));
    }

Entity::Entity(const Entity &other) : x(other.x), y(other.y),health(other.health), ticks(other.ticks), maxTicks(ticks), damage(other.damage), name(other.name), hitbox(other.hitbox) {}

Entity& Entity::operator=(const Entity& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
        health = other.health;
        ticks = other.ticks;
        damage = other.damage;
        name = other.name;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Entity& Entity) {
    os << "Zombie(name: " << Entity.name.get()
       << ", x: " << Entity.x.get()
       << ", y: " << Entity.y.get()
       << ", health: " << Entity.health.get()
       << ", ticks: " << Entity.ticks.get()
       << ", damage: " << Entity.damage.get()
       << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Entity& Entity) {
    int bufferI;
    std::string bufferS;
    std::cout << "Write entity name,x,y,health,ticks and damage:" << std::endl;
    is >> bufferS;
    Entity.name.set(bufferS);
    is >> bufferI;
    Entity.x.set(bufferI);
    is >> bufferI;
    Entity.y.set(bufferI);
    is >> bufferI;
    Entity.health.set(bufferI);
    is >> bufferI;
    Entity.ticks.set(bufferI);
    is >> bufferI;
    Entity.damage.set(bufferI);

    return is;
}

void Entity::takeDamage(const int dmg) {
    health.modify(-dmg);
    if (health.get() <= 0) {
        setDeletionMark(true);
    }
}

void Entity::setCanMove(const bool canmove) {
    this->canMove = canmove;
}

void Entity::setDeletionMark(const bool mark) {
    this->deletionMark = mark;
}

std::string Entity::getName() {
    return name.get();
}

bool Entity::getDeletionMark() const {
    return deletionMark.get();
}

std::pair<int, int> Entity::getPosition() {
    return std::make_pair(x.get(), y.get());
}

sf::RectangleShape& Entity::getHitbox() {
    return hitbox;
}

int Entity::getDamage() const {
    return damage.get();
}