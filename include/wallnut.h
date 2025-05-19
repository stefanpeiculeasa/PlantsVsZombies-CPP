#ifndef WALLNUT_H
#define WALLNUT_H

#include "plant.h"

class Wallnut final : public Plant {
public:
    Wallnut(int x,int y);

    void attack(Grid& grid) override;
};


#endif
