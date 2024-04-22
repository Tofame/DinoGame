#pragma once

#include <iostream>
#include <thread>
#include <SFML/Graphics.hpp>

#include "Creature/Dino.h"
#include "Utils/SoundManager.h"
#include "Globals.h"

auto setupBackgroundTexture() -> void;

int main() {
    auto SM = soundManager();
    // SM.addSound("die");
    // SM.playSound("die");

    auto dino = Dino();
    dino.setup();

    setupBackgroundTexture();

    auto event = sf::Event();

    while (window.isOpen()){
        window.clear();

        // DRAW DINO
        if(dino.dinoState == IS_RUNNING)
            dino.animator.updateSpriteFrame();
        window.draw(dino.sprite);
        // DRAW BACKGROUND
        window.draw(backgroundSprite);
        backgroundSprite.setPosition(backgroundSprite.getPosition().x - 0.01, backgroundSprite.getPosition().y);
        // TESTS
        //window.draw(sf::Sprite(backgroundTexture));

        window.display();

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
                    if(event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Space) {
                        if(dino.getState() == IS_JUMPING) continue;
                        dino.setState(IS_JUMPING);
                        std::thread jumpThread(&Dino::jump, &dino);
                        jumpThread.detach();
                    }
                default:
                    std::cout << "Unknown event type \n";
            }
        }
    }

    return 0;
}

auto setupBackgroundTexture() -> void {
    if (!backgroundTexture.loadFromFile(projectPath + "\\Resources\\Graphics\\Backgrounds\\background2.png")) {
        throw std::runtime_error("Couldnt load background image");
    }

    sf::RenderTexture *resultTexture = new sf::RenderTexture;

    if (!resultTexture->create(window.getSize().x * 2, backgroundTexture.getSize().y))
        throw std::runtime_error("Couldnt create RenderTexture for setupBackgroundTexture()");

    auto tempSprite = sf::Sprite(backgroundTexture);
    for(auto i = 0; i < (window.getSize().x/backgroundTexture.getSize().x) * 2; i++) {
        tempSprite.setPosition(i * backgroundTexture.getSize().x, 0);
        resultTexture->draw(tempSprite);
    }

    resultTexture->display();

    backgroundSprite = sf::Sprite(resultTexture->getTexture());
    backgroundSprite.setPosition(0, dinoPosY * window.getSize().y + textureDinoRun.getSize().y * spriteScale);

    //backgroundSprite.setColor(sf::Color::Magenta);
};