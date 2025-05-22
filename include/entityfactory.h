#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H

#include <memory>
#include "entity.h"

class EntityFactory {
    public:
    static std::unique_ptr<Entity> createPeashooter(int x, int y);
    static std::unique_ptr<Entity> createWallnut(int x, int y);
    static std::unique_ptr<Entity> createSunflower(int x, int y);
    static std::unique_ptr<Entity> createBasicZombie(int x, int y);
};

#endif
