#pragma once

#include <iostream>
#include <thread>
#include <SFML/Graphics.hpp>

#include "Globals.h"

#include "Creature/Dino.h"
#include "Utils/SoundManager.h"
#include "Utils/TextureManager.h"
#include "UI/GameInterface.h"

int main() {
    // Setup the textures
    TextureManager::setupTextures();

    SoundManager::addSound("die");
    SoundManager::playSound("die");

    GameInterface::setupBackgroundTexture();

    // The gameloop etc.
    gameState = STATE_PLAY;

    auto dino = Dino(42.5);
    dino.setup();

    auto event = sf::Event();

    while (window.isOpen()){
        window.clear();

        // DRAW DINO
        if(dino.dinoState == IS_RUNNING) { // If is running update sprite frame with animator
            dino.animator.updateSpriteFrame();
        }
        window.draw(dino.sprite);
        // DRAW BACKGROUND
        window.draw(backgroundSprite);
        if(-backgroundSprite.getPosition().x > backgroundSpriteWidth/2) {
            backgroundSprite.setPosition(0, backgroundSprite.getPosition().y);
        } else {
            backgroundSprite.setPosition(backgroundSprite.getPosition().x - 2.0, backgroundSprite.getPosition().y);
        }

        window.display();

        // STATE HANDLING HERE
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            if(dino.getState() != IS_DASHING)
                dino.dash();
        } else {
            // ABOVE THE GROUND (IN THE AIR)
            if (dino.isInTheAir()) {
                if(dino.getState() != IS_JUMPING)
                    dino.setState(IS_JUMPING);
            } else { // ON THE GROUND
                if(dino.getState() != IS_RUNNING)
                    dino.setState(IS_RUNNING);
            }
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
                    switch(event.key.code) {
                        case sf::Keyboard::Up:
                        case sf::Keyboard::Space: {
                            if (dino.isInTheAir()) continue;
                            std::thread jumpThread(&Dino::jump, &dino);
                            jumpThread.detach();
                            break;
                        }
                        case sf::Keyboard::Down:
                        {
                            if (dino.isInTheAir(15.0)) {
                                dino.sprite.move(0, 15.0);
                            }

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
