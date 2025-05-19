#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "entity.h"
#include "utils.h"

class Zombie : public Entity {
protected:
    int speed;

public:
    Zombie(int x,int y,int health,int speed, std::string name,int ticks,int damage);

    void moveForward();

    void attack(const std::unique_ptr<Entity>& plant);

    void update(Grid& grid) override;
};


#endif //ZOMBIE_H
