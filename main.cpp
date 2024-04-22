#pragma once

#include <iostream>
#include <thread>

#include "Creature/Dino.h"
#include "Utils/SoundManager.h"
#include "Globals.h"

int main() {
    auto SM = soundManager();
    // SM.addSound("die");
    // SM.playSound("die");

    auto dino = Dino();
    dino.setup();

    auto event = sf::Event();

    while (window.isOpen()){
        window.clear();

        if(dino.dinoState == IS_RUNNING)
            dino.animator.updateSpriteFrame();
        window.draw(dino.sprite);

        window.display();

        while (window.pollEvent(event)){
            switch(event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::Resized:
                    //window.setSize(originalSize);
                case sf::Event::KeyPressed:
                    if(event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Space) {
                        if(dino.getState() == IS_JUMPING) continue;
                        dino.setState(IS_JUMPING);
                        std::thread jumpThread(&Dino::jump, &dino);
                        jumpThread.detach();
                    }
                default:
                    std::cout << "Nieobslugiwany event type";
            }
        }
    }

    return 0;
}