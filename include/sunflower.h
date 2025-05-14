#ifndef SUNFLOWER_H
#define SUNFLOWER_H

#include "plant.h"
#include <random>


class Sunflower final : public Plant {
public:
    Sunflower(const int x,const int y,const int scale) : Plant(x, y, 100, 5, "sunflower",600,0,scale) {}

    void attack(Grid& grid) override;

};

#endif //SUNFLOWER_H
