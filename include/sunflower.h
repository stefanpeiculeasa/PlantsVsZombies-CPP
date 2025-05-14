#ifndef SUNFLOWER_H
#define SUNFLOWER_H

#include "sun.h"


class Sunflower final : public Plant {
public:
    Sunflower(const int x,const int y,const int scale) : Plant(x, y, 100, 5, "sunflower",600,0,scale) {}

    void attack(Grid& grid) override {
        int sunx = (std::rand() % (2 * 150 + 1)) - 150;
        int suny = (std::rand() % (2 * 150 + 1)) - 150;
        auto finalPos = sf::Vector2i(sunx + x,suny + y);
        std::cout << finalPos.x << " " << finalPos.y << std::endl;
        auto sun = std::make_unique<Sun>(x,y,2,0,1,finalPos);
        grid.addEntity(std::move(sun));
    }
};

#endif //SUNFLOWER_H
