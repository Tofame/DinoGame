#pragma once

#include <iostream>

#include "Dino.h"
#include "../Globals.h"

Dino::Dino() : animator() {}

auto Dino::getSprite() -> void {
    this->animator.getCurrentFrame();
};

auto Dino::setup() -> void {
    if (!textureDinoRun.loadFromFile(projectPath+"\\Resources\\Graphics\\Characters\\raptor-run.png"))
        std::cout << "Couldn't load Dino texture (Running).";

    if (!textureDinoWalk.loadFromFile(projectPath+"\\Resources\\Graphics\\Characters\\raptor-walk.png"))
        std::cout << "Couldn't load Dino texture (Walking).";

    this->sprite = sf::Sprite();

    this->sprite.setTexture(textureDinoRun);
    this->sprite.setTextureRect(sf::IntRect(0,0,32,32));

    this->sprite.setPosition(0.1 * window.getSize().x, 0.5 * window.getSize().y);

    auto *x = &(this->sprite);
    this->animator = Animator(x, defaultAnimSF);
    this->animator.start();
};