#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H

#include "memory"
#include "entity.h"

class EntityFactory {
    public:
    enum class EntityType {
        Peashooter,
        Wallnut,
        Sunflower,
        BasicZombie
    };

    static std::unique_ptr<Entity> createEntity(EntityType type,int x, int y);
};

#endif
