#pragma once

#include <iostream>
#include <thread>
#include <SFML/Graphics.hpp>
#include <atomic>

#include "Globals.h"
#include "TrapSpawner.h"

#include "Utils/SoundManager.h"
#include "Utils/TextureManager.h"
#include "UI/GameInterface.h"

auto resetGame() -> void;

std::atomic<bool> isSpawningThreadActive(false);

int main() {
    // Setup the textures
    TextureManager::setupTextures();
    GameInterface::setupUI();
    SoundManager::setupSounds();

    // The gameloop etc.
    gameState = STATE_PLAY;
    dino.setup();


    auto event = sf::Event();

    while (window.isOpen()){
        if(gameState == STATE_PLAY) {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                if (dino.isInTheAir(0.05)) {
                    dino.sprite.move(0, 0.05);
                }
            }

            GameInterface::drawPlayScreen();
            if(!isSpawningThreadActive.load()) {
                isSpawningThreadActive.store(true);
                std::thread spawnThread([&]() {
                    TrapSpawner::create();
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
                        gameState = STATE_PLAY;
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

    return 0;
}

auto resetGame() -> void {
    dino.setup();
}