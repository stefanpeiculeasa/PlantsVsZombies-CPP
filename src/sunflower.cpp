#include "sunflower.h"
#include "sun.h"
#include "grid.h"
#include "random"

Sunflower::Sunflower(const int x,const int y) : Plant(x, y, 100, 5, "sunflower",600,0) {}

void Sunflower::attack(Grid &grid) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dist(-150, 150);

    int sunx = dist(gen);
    int suny = dist(gen);
    auto finalPos = sf::Vector2i(sunx + x, suny + y);

    auto sun = std::make_unique<Sun>(x, y, 0, 1, finalPos);
    grid.addEntity(std::move(sun));
}
