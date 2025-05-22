#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "entity.h"

class Projectile final : public Entity {
    int speed;

public:
    Projectile(int x, int y, int damage, int speed);

    void move();
    void update(Grid& grid) override;
};

#endif // PROJECTILE_H
