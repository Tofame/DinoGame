#pragma once

#include "Saw.h"
#include "FlyingBird.h"

class ObstacleFactory {
public:
    static Saw* createSaw();
    static FlyingBird* createFlyingBird();
};
