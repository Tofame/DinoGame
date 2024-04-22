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

    auto window = sf::RenderWindow(sf::VideoMode(windowWidth,windowHeight),"Dino The Game");
    auto event = sf::Event();

    while (window.isOpen()){
        window.clear();

        window.draw(dino.getSprite());

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