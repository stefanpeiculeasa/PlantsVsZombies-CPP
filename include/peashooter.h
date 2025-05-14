#ifndef PEASHOOTER_H
#define PEASHOOTER_H

#include "projectile.h"


class Peashooter final : public Plant {
public:
    Peashooter(const int x,const int y,const int scale) : Plant(x, y, 100, 4, "peashooter",120,30,scale) {}

    void attack(Grid& grid) override {
        for (auto& entity : grid.getEntities()) {
            if (dynamic_cast<Zombie*>(entity.get()) and entity->getPosition().second == y) {
                auto proj = std::make_unique<Projectile>(x+40,y,2,damage,2);
                grid.addEntity(std::move(proj));
                break;
            }
        }
    }
};


#endif
