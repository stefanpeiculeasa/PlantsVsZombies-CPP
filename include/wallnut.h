#ifndef WALLNUT_H
#define WALLNUT_H

#include "plant.h"

class Wallnut final : public Plant {
public:
    Wallnut(int x,int y);

    void action(Grid& grid) override;
};


#endif
