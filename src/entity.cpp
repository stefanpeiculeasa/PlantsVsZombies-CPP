#include "entity.h"
#include "utils.h"

Entity::Entity(int x, int y, int health, std::string name, int ticks, int damage, int scale) : x(x), y(y), health(health), ticks(ticks), maxTicks(ticks),damage(damage), name(move(name)) {
    hitbox.setSize(sf::Vector2f(static_cast<float>(GameUtils::keyCoords["hitboxSize"][0].first.x),static_cast<float>(GameUtils::keyCoords["hitboxSize"][0].first.y)));
    hitbox.setScale(static_cast<float>(scale),static_cast<float>(scale));
    hitbox.setPosition(static_cast<float>(x),static_cast<float>(y));
    }


void Entity::takeDamage(const int damage) {
    health -= damage;
    if (health <= 0) {
        setDeletionMark(true);
    }
}

void Entity::setCanMove(const bool canMove) {
    this->canMove = canMove;
}

void Entity::setDeletionMark(const bool deletionMark) {
    this->deletionMark = deletionMark;
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