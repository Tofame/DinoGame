#pragma once

#include <queue>

#include "Creature/Trap.h"
#include "Globals.h"

class TrapSpawner {
public:
    static std::deque<Trap*> traps;

    static void create();
};