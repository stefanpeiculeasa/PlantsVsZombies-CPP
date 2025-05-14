#include "plant.h"
#include "zombie.h"
#include "sunflower.h"

Plant::Plant(const int x,const int y,const int health,const int cost, std::string name,const int ticks,const int damage,const int scale) : Entity(x, y, health,std::move(name),ticks,damage,scale), cost(cost) {}

void Plant::update(Grid &grid) {
    ticks-=1;
    if (ticks == 0) {
        ticks = maxTicks;
        attack(grid);
    }
}

int Plant::getCost() const {
    return cost;
}
