#pragma once

#include <iostream>
#include <thread>
#include <SFML/Graphics.hpp>
#include <atomic>

#include "Globals.h"
#include "Creature/ObstacleThread.h"

#include "Utils/SoundManager.h"
#include "Utils/TextureManager.h"
#include "UI/GameInterface.h"

auto run() -> void;
auto resetGame() -> void;

std::atomic<bool> isSpawningThreadActive(false);
static sf::Event event;

int main() {
    // Setup the textures
    TextureManager::setupTextures();
    GameInterface::setupUI();
    SoundManager::setupSounds();

    // The gameloop etc.
    gameState = STATE_PLAY;
    dino.setup();
    event = sf::Event();

    // Variables for delta time
    // I learned how to do that from "RyiSnow", video: https://youtu.be/VpH33Uw-_0E?list=PL_QPQmz5C6WUF-pOQDsbsKbaBZqXj4qSq&t=1072
    // 1000000000 is 1 second (billion nanoseconds)
    double drawInterval = 1000000000 / 90; // ≈ 0.0167 seconds ( for 1 / 60 )
    double delta = 0;
    long long lastTime = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    long long currentTime;
    long long timer = 0;

    while (window.isOpen()){
        // Implement delta time (game loop)
        // Its REQUIRED when you want app to work the same on different devices
        // ...that have different frame rates <-> are faster
        currentTime = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        delta += (currentTime - lastTime) / drawInterval;
        timer += currentTime - lastTime;
        lastTime = currentTime;

        if (delta >= 1) {
            run();
            delta--;
        }

        if (timer >= 1000000000) { // runs every second
            timer = 0;
        }
    }

    return 0;
}

auto run() -> void {
    if(gameState == STATE_PLAY) {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            if (dino.isInTheAir(dashFallingValue)) {
                dino.sprite.move(0, dashFallingValue);
                dino.hitbox.move(0, dashFallingValue);
            }
        }

        GameInterface::drawPlayScreen();
        if(!isSpawningThreadActive.load()) {
            isSpawningThreadActive.store(true);
            std::thread spawnThread([&]() {
                ObstacleThread::create();
                isSpawningThreadActive.store(false); // Reset the flag when the thread finishes
            });
            spawnThread.detach();
        }
    } else if(gameState == STATE_GAMEOVER) {
        GameInterface::drawGameOverScreen();
    }

    while (window.pollEvent(event)){
        switch(event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
                window.setSize(originalSize);
            case sf::Event::LostFocus:
                // something
            case sf::Event::KeyPressed:
                // Restart the game when gameover
                if(gameState == STATE_GAMEOVER) {
                    resetGame();
                    continue;
                }

                switch(event.key.code) {
                    case sf::Keyboard::Up:
                    case sf::Keyboard::Space: {
                        if (dino.isInTheAir()) continue;
                        SoundManager::playSound("jump");
                        std::thread jumpThread(&Dino::jump, &dino);
                        jumpThread.detach();
                        break;
                    }
                    case sf::Keyboard::Down:
                    {
                        if (dino.getState() == IS_DASHING) continue;
                        dino.dash();
                        break;
                    }
                    default:
                        break;
                }
            default:
                break;
                //std::cout << "Unknown event type \n";
        }
    }
}

auto resetGame() -> void {
    ObstacleThread::obstacles.clear();
    dino.reset();
    gameState = STATE_PLAY;
}