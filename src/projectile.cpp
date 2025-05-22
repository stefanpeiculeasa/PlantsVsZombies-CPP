#include "projectile.h"
#include "grid.h"
#include "zombie.h"

Projectile::Projectile(int x, int y, int damage, int speed)
    : Entity(x, y, 1, "projectile", 1, damage), speed(speed) {}

void Projectile::move() {
    x.modify(speed);
    hitbox.setPosition(static_cast<float>(x.get()), static_cast<float>(y.get()));
}

void Projectile::update(Grid& grid) {
    move();
    for (auto& entity : grid.getEntities()) {
        if (dynamic_cast<Zombie*>(entity.get())) {
            sf::RectangleShape r1 = entity->getHitbox();
            if (sf::RectangleShape r2 = this->getHitbox(); r1.getGlobalBounds().intersects(r2.getGlobalBounds())) {
                entity->takeDamage(damage.get());
                this->setDeletionMark(true);
            }
        }
    }
}
