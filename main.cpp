#pragma once

#include <iostream>
#include <filesystem>

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
        
        dino.animator.updateSpriteFrame();
        //dino.sprite.setPosition(0.1 * window.getSize().x,dino.sprite.getPosition().y - 0.01);
        window.draw(dino.sprite);

        window.display();

        while (window.pollEvent(event)){
            if(event.type==sf::Event::Closed){
                window.close();
            }
        }
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}