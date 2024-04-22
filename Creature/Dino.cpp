#pragma once

#include <iostream>

#include "Dino.h"
#include "../Globals.h"

auto Dino::getSprite() -> sf::Sprite {
    return sprite;
};

auto Dino::setupSprite() -> void {
    if (!textureDino.loadFromFile(projectPath+"\\Resources\\Graphics\\Characters\\raptor.png"))
        std::cout << "Couldn't load Dino texture.";

    this->sprite = sf::Sprite();

    this->sprite.setTexture(textureDino);
    this->sprite.setTextureRect(sf::IntRect(0,0,128,64));
};