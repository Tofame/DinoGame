#pragma once

#include <queue>

#include "Obstacle.h"

class ObstacleThread {
public:
    static std::deque<Obstacle*> obstacles;

    static void create();
};