#pragma once

#include <iostream>
#include <thread>
#include <SFML/Graphics.hpp>

#include "Creature/Dino.h"
#include "Utils/SoundManager.h"
#include "Utils/TextureManager.h"
#include "Globals.h"

auto setupBackgroundTexture() -> void;

int main() {
    // Setup the textures
    textureManager::setupTextures();

    auto SM = soundManager();
    // SM.addSound("die");
    // SM.playSound("die");

    auto dino = Dino(42.5);
    dino.setup();

    setupBackgroundTexture();

    auto event = sf::Event();

    while (window.isOpen()){
        window.clear();

        // DRAW DINO
        if(dino.dinoState == IS_RUNNING) {
            dino.sprite.setTexture(textureDinoRun);
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
        // TESTS
        //window.draw(sf::Sprite(backgroundTexture));

        window.display();

        // STATE HANDLING HERE
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            if(dino.getState() != IS_DASHING)
                dino.dash();
        } else {
            // ABOVE THE GROUND (IN THE AIR)
            if (dino.sprite.getPosition().y > dinoPosY * window.getSize().y) {
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
                    //window.setSize(originalSize);
                case sf::Event::LostFocus:
                    // something
                case sf::Event::KeyPressed:
                    switch(event.key.code) {
                        case sf::Keyboard::Up:
                        case sf::Keyboard::Space:
                        {
                            if (dino.getState() != IS_RUNNING) continue;
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

auto setupBackgroundTexture() -> void {
    sf::RenderTexture *resultTexture = new sf::RenderTexture;

    if (!resultTexture->create(backgroundSpriteWidth, backgroundTexture.getSize().y))
        throw std::runtime_error("Couldnt create RenderTexture for setupBackgroundTexture()");

    auto tempSprite = sf::Sprite(backgroundTexture);
    // *2 because we want line to be 2x larger than screen
    for(auto i = 0; i < (window.getSize().x/backgroundTexture.getSize().x) * 2; i++) {
        tempSprite.setPosition(i * backgroundTexture.getSize().x, 0);
        resultTexture->draw(tempSprite);
    }

    resultTexture->display();

    backgroundSprite = sf::Sprite(resultTexture->getTexture());
    backgroundSprite.setPosition(0, dinoPosY * window.getSize().y + textureDinoRun.getSize().y * spriteScale);

    //backgroundSprite.setColor(sf::Color::Magenta);
};