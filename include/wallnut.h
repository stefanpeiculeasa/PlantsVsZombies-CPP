#ifndef WALLNUT_H
#define WALLNUT_H

#include "plant.h"
#include <iostream>


class Wallnut final : public Plant {
public:
    Wallnut(const int x,const int y,const int scale) : Plant(x, y, 400, 5, "wallnut",120,30,scale) {}

    void attack(Grid& grid) override {std::cout << grid.getSun();}
};


#endif
