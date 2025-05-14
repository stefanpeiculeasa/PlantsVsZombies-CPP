#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "entity.h"
#include "zombie.h"
#include "utils.h"

class Projectile final : public Entity{
    int speed;
public:
    Projectile(const int x,const int y,const int scale,const int damage,const int speed) : Entity(x,y,1,"projectile",1,damage,scale), speed(speed) {}

    void move() {
        x+=speed;
        hitbox.setPosition(x,y);
    }

    void update(Grid& grid) override {
        move();
        for (auto& entity : grid.getEntities()) {
            if (auto* zPtr = dynamic_cast<Zombie*>(entity.get())) {
                sf::RectangleShape r1 = entity->getHitbox();
                sf::RectangleShape r2 = this->getHitbox();
                if (r1.getGlobalBounds().intersects(r2.getGlobalBounds())) {
                    entity->takeDamage(damage);
                    this->setDeletionMark(true);
                    std::cout << "hit" << std::endl;
                }
            }
        }

    }

};


#endif //PROJECTILE_H
