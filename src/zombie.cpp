#include "zombie.h"
#include "plant.h"
#include "grid.h"

Zombie::Zombie(const int x, const int y, const int health, const int speed, std::string name, const int ticks, const int damage, const int scale)
    : Entity(x,y, health,move(name),ticks,damage,scale), speed(speed) {}

void Zombie::moveForward() {
    if (canMove) {
        x-=speed;
        hitbox.setPosition(x,y);
    }
}

void Zombie::attack(std::unique_ptr<Entity>& plant) {
    ticks -= 1;
    if (ticks == 0){
        std::cout << "attacked" << std::endl;
        plant->takeDamage(damage);
        ticks = maxTicks;
    }
}

void Zombie::update(Grid &grid) {
    if (health <= 0) {
        this->setDeletionMark(true);
        return;
    }

    moveForward();

    const auto& coords = grid.getCoords();
    if (coords.contains("zombieHit")) {
        for (const auto& coord : coords.at("zombieHit")) {
            sf::FloatRect hitbox = this->getHitbox().getGlobalBounds();
            if (hitbox.contains(static_cast<sf::Vector2f>(coord.first))) {
                grid.takeDamage(this->getDamage());
                this->setDeletionMark(true);
            }
            else setCanMove(true);
        }
    }

    for (auto& entity : grid.getEntities()) {
        if (dynamic_cast<Plant*>(entity.get())) {
            sf::FloatRect hitbox = this->getHitbox().getGlobalBounds();
            if (hitbox.contains(entity->getHitbox().getPosition())) {
                this->setCanMove(false);
                attack(entity);
            }
        }
    }
}
