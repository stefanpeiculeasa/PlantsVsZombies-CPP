#include "peashooter.h"
#include "grid.h"
#include "zombie.h"
#include "projectile.h"

Peashooter::Peashooter(const int x,const int y) : Plant(x, y, 100, 4, "peashooter",120,30) {}

void Peashooter::attack(Grid &grid) {
    {
        for (auto& entity : grid.getEntities()) {
            if (dynamic_cast<Zombie*>(entity.get()) and entity->getPosition().second == y) {
                auto proj = std::make_unique<Projectile>(x+40,y,damage,2);
                grid.addEntity(std::move(proj));
                break;
            }
        }
    }
}
