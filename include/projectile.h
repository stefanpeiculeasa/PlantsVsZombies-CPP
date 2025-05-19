#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "entity.h"
#include "zombie.h"

class Projectile final : public Entity{
    int speed;
public:
    Projectile(const int x,const int y,const int damage,const int speed) : Entity(x,y,1,"projectile",1,damage), speed(speed) {}

    void move() {
        x+=speed;
        hitbox.setPosition(static_cast<float>(x),static_cast<float>(y));
    }

    void update(Grid& grid) override {
        move();
        for (auto& entity : grid.getEntities()) {
            if (dynamic_cast<Zombie*>(entity.get())) {
                sf::RectangleShape r1 = entity->getHitbox();
                if (sf::RectangleShape r2 = this->getHitbox(); r1.getGlobalBounds().intersects(r2.getGlobalBounds())) {
                    entity->takeDamage(damage);
                    this->setDeletionMark(true);
                }
            }
        }

    }

};


#endif //PROJECTILE_H
