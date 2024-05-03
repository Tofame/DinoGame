#include "ObstacleThread.h"

#include <thread>
#include <random>

#include "ObstacleFactory.h"
#include "../Globals.h"

std::deque<Obstacle*> ObstacleThread::obstacles = std::deque<Obstacle*>();

int getRandomValue(int min, int max);
void handleSawCreation();
void handleBirdCreation();

// Main method here, that calls all the other ones
auto ObstacleThread::create() -> void {
    handleSawCreation();
    handleBirdCreation();

    std::this_thread::sleep_for(std::chrono::milliseconds(550 + getRandomValue(300, 800)));
}




// Method bodies
void handleSawCreation() {
    Obstacle* saw = ObstacleFactory::createSaw();
    ObstacleThread::obstacles.push_back(saw);

    // 2nd saw so its more variety
    if(game_scoreNow > 200 && getRandomValue(1, 3) == 1) {
        saw = ObstacleFactory::createSaw();
        auto rPosVariant = getRandomValue(1,3);
        switch(rPosVariant) {
            case 1: // High
                saw->sprite.move(0,-24);
                saw->hitbox.move(0,-24);
                break;
            case 2: // Higher
                saw->sprite.move(0,-36);
                saw->hitbox.move(0,-36);
                break;
            case 3: // Highest while still can be jumped over
                saw->sprite.move(0,-52);
                saw->hitbox.move(0,-52);
                break;
            default:
                saw->sprite.move(0,-10);
                saw->hitbox.move(0,-10);
                break;
        }

        ObstacleThread::obstacles.push_back(saw);
    }
}

void handleBirdCreation() {
    // Birds appear only when score is above 100 and have 25% chance to appear
    if(game_scoreNow > 100 && getRandomValue(1, 4) == 1) {
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
            default:
                flyingBird->sprite.move(rX,20);
                flyingBird->hitbox.move(rX,20);
                break;
        }
        ObstacleThread::obstacles.push_back(flyingBird);
    }
}

int getRandomValue(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(min, max);
    return distr(gen);
}