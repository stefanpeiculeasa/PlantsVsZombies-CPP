#include "entityfactory.h"
#include "entity.h"
#include "peashooter.h"
#include "memory"
#include "wallnut.h"
#include "sunflower.h"
#include "basiczombie.h"

std::unique_ptr<Entity> EntityFactory::createPeashooter(const int x,const int y) {
    return std::make_unique<Peashooter>(x,y);
}

std::unique_ptr<Entity> EntityFactory::createWallnut(const int x,const int y) {
    return std::make_unique<Wallnut>(x,y);
}

std::unique_ptr<Entity> EntityFactory::createSunflower(const int x,const int y) {
    return std::make_unique<Sunflower>(x,y);
}

std::unique_ptr<Entity> EntityFactory::createBasicZombie(const int x,const int y) {
    return std::make_unique<BasicZombie>(x,y);
}