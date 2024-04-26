#pragma once

#include "ObstacleFactory.h"

#include "Obstacle.h"
#include "Saw.h"

Saw* ObstacleFactory::createSaw() {
    Saw* saw = new Saw();
    saw->setup();
    return saw;
}