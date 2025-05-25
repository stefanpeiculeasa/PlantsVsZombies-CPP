#include "sunflower.h"

#include "game.h"
#include "sun.h"
#include "grid.h"
#include "utils.h"

Sunflower::Sunflower(const int x,const int y) : Plant(x, y, 100, 5, "sunflower",600,0) {}

void Sunflower::attack(Grid &grid) {

    int sunx = Settings::random(-150,150);
    int suny = Settings::random(-150,150);
    auto finalPos = sf::Vector2i(sunx + x.get(), suny + y.get());

    auto sun = std::make_unique<Sun>(x.get(), y.get(),finalPos);
    grid.addEntity(std::move(sun));
}
