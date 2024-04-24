#pragma once

#include "ObstacleThread.h"

#include <thread>
#include <random>

std::deque<Obstacle*> ObstacleThread::obstacles = std::deque<Obstacle*>();

int getRandomSleepDuration(int minMs, int maxMs) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(minMs, maxMs);
    return distr(gen);
}

auto ObstacleThread::create() -> void {
    Obstacle* saw = new Obstacle();
    saw->setup();
    ObstacleThread::obstacles.push_back(saw);

    std::this_thread::sleep_for(std::chrono::milliseconds(getRandomSleepDuration(500, 1200)));
}
