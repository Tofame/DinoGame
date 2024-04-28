#include "ObstacleThread.h"

#include <thread>
#include <random>

#include "ObstacleFactory.h"

std::deque<Obstacle*> ObstacleThread::obstacles = std::deque<Obstacle*>();

int getRandomValue(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(min, max);
    return distr(gen);
}

auto ObstacleThread::create() -> void {
    Obstacle* saw = ObstacleFactory::createSaw();
    ObstacleThread::obstacles.push_back(saw);

    if(getRandomValue(1, 5) == 1) {
        Obstacle* flyingBird = ObstacleFactory::createFlyingBird();
        auto rX = -getRandomValue(10, 50);
        auto rPosVariant = getRandomValue(1,3);
        switch(rPosVariant) {
            case 1: // U need to dash
                flyingBird->sprite.move(rX,20);
                flyingBird->hitbox.move(rX,20);
                break;
            case 2: // No need to dash
                flyingBird->sprite.move(rX,-5);
                flyingBird->hitbox.move(rX,-5);
                break;
            case 3: // High in the air
                flyingBird->sprite.move(rX,-30);
                flyingBird->hitbox.move(rX,-30);
                break;
        }
        ObstacleThread::obstacles.push_back(flyingBird);
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(550 + getRandomValue(300, 800)));
}
