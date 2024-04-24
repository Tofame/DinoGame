#pragma once

#include "TrapSpawner.h"

#include <thread>
#include <cstdlib>
#include <iostream>
#include <random>

std::deque<Trap*> TrapSpawner::traps = std::deque<Trap*>();

int getRandomSleepDuration(int minMs, int maxMs) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(minMs, maxMs);
    return distr(gen);
}

auto TrapSpawner::create() -> void {
    Trap* saw = new Trap();
    (*saw).setup();
    TrapSpawner::traps.push_back(saw);

    std::this_thread::sleep_for(std::chrono::milliseconds(getRandomSleepDuration(500, 1200)));
}
