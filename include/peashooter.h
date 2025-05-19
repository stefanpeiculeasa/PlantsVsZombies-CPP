#ifndef PEASHOOTER_H
#define PEASHOOTER_H

#include "plant.h"

class Peashooter final : public Plant {
public:
    Peashooter(int x,int y);

    void attack(Grid& grid) override;
};


#endif
