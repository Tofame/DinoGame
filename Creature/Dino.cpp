#pragma once

#include <iostream>

#include "Dino.h"
#include "../Globals.h"

auto Dino::getSprite() -> sf::Sprite {
    return sprite;
};

auto Dino::setupSprites() -> void {
    if (!textureDinoRun.loadFromFile(projectPath+"\\Resources\\Graphics\\Characters\\raptor-run.png"))
        std::cout << "Couldn't load Dino texture (Running).";

    if (!textureDinoWalk.loadFromFile(projectPath+"\\Resources\\Graphics\\Characters\\raptor-walk.png"))
        std::cout << "Couldn't load Dino texture (Walking).";

    this->sprite = sf::Sprite();

    this->sprite.setTexture(textureDinoRun);
    this->sprite.setTextureRect(sf::IntRect(0,0,128,64));
};