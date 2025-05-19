#include "entity.h"
#include "utils.h"

Entity::Entity(int x, int y, int health, std::string name, int ticks, int damage) : x(x), y(y), health(health), ticks(ticks), maxTicks(ticks),damage(damage), name(std::move(name)) {
    hitbox.setSize(sf::Vector2f(static_cast<float>(GameUtils::keyCoords["hitboxSize"][0].first.x),static_cast<float>(GameUtils::keyCoords["hitboxSize"][0].first.y)));
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
    os << "Zombie(name: " << Entity.name
       << ", x: " << Entity.x
       << ", y: " << Entity.y
       << ", health: " << Entity.health
       << ", ticks: " << Entity.ticks
       << ", damage: " << Entity.damage
       << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Entity& Entity) {
    is >> Entity.name;
    return is;
}

void Entity::takeDamage(const int dmg) {
    health -= dmg;
    if (health <= 0) {
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
    return name;
}

bool Entity::getDeletionMark() const {
    return deletionMark;
}

std::pair<int, int> Entity::getPosition() {
    return std::make_pair(x, y);
}

sf::RectangleShape& Entity::getHitbox() {
    return hitbox;
}

int Entity::getDamage() const {
    return damage;
}