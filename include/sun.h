#ifndef SUN_H
#define SUN_H

#include "entity.h"
#include "utils.h"

class Sun final : public Entity{
    int speed;
    sf::Vector2i finalPos;
public:
    Sun(int x,int y,int damage,int speed,sf::Vector2i finalPos);

    void move();

    void update(Grid& grid) override ;

};

#endif
