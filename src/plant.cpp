#include "plant.h"
#include "zombie.h"

Plant::Plant(const int x,const int y,const int health,const int cost, std::string name,const int ticks,const int damage) : Entity(x, y, health,std::move(name),ticks,damage), cost(cost) {}

void Plant::update(Grid &grid) {
    ticks.modify(-1);
    if (ticks.get() == 0) {
        ticks = maxTicks;
        action(grid);
    }
}

int Plant::getCost() const {
    return cost;
}
