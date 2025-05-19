#include "entityfactory.h"
#include "entity.h"
#include "peashooter.h"
#include "memory"
#include "wallnut.h"
#include "sunflower.h"
#include "basiczombie.h"

std::unique_ptr<Entity> EntityFactory::createEntity(const EntityType type, int x, int y) {
    {
        switch (type) {
            case EntityType::Peashooter:
                return std::make_unique<Peashooter>(x,y);
            case EntityType::Wallnut:
                return std::make_unique<Wallnut>(x,y);
            case EntityType::Sunflower:
                return std::make_unique<Sunflower>(x,y);
            case EntityType::BasicZombie:
                return std::make_unique<BasicZombie>(x,y);
            default: return nullptr;
        }
    }
}
