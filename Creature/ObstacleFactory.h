#pragma once
#include "Obstacle.h"
#include "Saw.h"

class ObstacleFactory {
public:
    static Saw* createSaw();
};
