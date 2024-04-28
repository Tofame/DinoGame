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
    Obstacle* obstacle = ObstacleFactory::createSaw();
    ObstacleThread::obstacles.push_back(obstacle);

    Obstacle* obstacle1 = ObstacleFactory::createFlyingBird();
    ObstacleThread::obstacles.push_back(obstacle1);

    std::this_thread::sleep_for(std::chrono::milliseconds(300 + getRandomSleepDuration(300, 900)));
}
