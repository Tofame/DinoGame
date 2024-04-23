#pragma once

#include "SawSpawner.h"

#include <thread>
#include <cstdlib>
#include <iostream>
#include <random>

std::deque<Saw*> SawSpawner::saws = std::deque<Saw*>();

int getRandomSleepDuration(int minMs, int maxMs) {
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(minMs, maxMs); // define the range
    return distr(gen); // generate the random sleep duration
}

auto SawSpawner::spawnSaw() -> void {
    Saw* saw = new Saw();
    (*saw).setup();
    SawSpawner::saws.push_back(saw);

    for (auto it = SawSpawner::saws.begin(); it != SawSpawner::saws.end(); ++it) {
        Saw* currentSaw = *it;
        if (currentSaw->sprite.getPosition().x < 0) {
            delete currentSaw; // Delete the pointer
            SawSpawner::saws.erase(it); // Remove the pointer from the queue
        }
    };

    std::this_thread::sleep_for(std::chrono::milliseconds(getRandomSleepDuration(500, 1200)));
}
