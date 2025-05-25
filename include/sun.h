#ifndef SUN_H
#define SUN_H

#include "entity.h"
#include "utils.h"

class Sun final : public Entity{
    sf::Vector2i finalPos;
public:
    Sun(int x,int y,sf::Vector2i finalPos);

    void move();

    void update(Grid& grid) override ;

};

#endif
