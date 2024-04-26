#pragma once

#include "ObstacleThread.h"

#include <thread>
#include <random>

#include "ObstacleFactory.h"

std::deque<Obstacle*> ObstacleThread::obstacles = std::deque<Obstacle*>();

int getRandomSleepDuration(int minMs, int maxMs) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(minMs, maxMs);
    return distr(gen);
}

auto ObstacleThread::create() -> void {
    //Saw* obstaclePtr = ObstacleFactory::createSaw();
    //ObstacleThread::obstacles.push_back(obstaclePtr);
    Saw* obstacle = new Saw();
    obstacle->setup();
    ObstacleThread::obstacles.push_back(obstacle);

    std::this_thread::sleep_for(std::chrono::milliseconds(getRandomSleepDuration(500, 1200)));
}
