#include "ObstacleFactory.h"

#include "Saw.h"
#include "FlyingBird.h"

Saw* ObstacleFactory::createSaw() {
    auto* obstacle = new Saw();
    obstacle->setup();
    return obstacle;
}

FlyingBird* ObstacleFactory::createFlyingBird() {
    auto* obstacle = new FlyingBird();
    obstacle->setup();
    return obstacle;
}