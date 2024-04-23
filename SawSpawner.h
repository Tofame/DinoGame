#pragma once

#include <queue>

#include "Creature/Saw.h"
#include "Globals.h"

class SawSpawner {
public:
    static std::deque<Saw*> saws;

    static void spawnSaw();
};