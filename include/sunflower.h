#ifndef SUNFLOWER_H
#define SUNFLOWER_H

#include "plant.h"


class Sunflower final : public Plant {
public:
    Sunflower(int x, int y);

    void attack(Grid& grid) override;

};

#endif //SUNFLOWER_H
