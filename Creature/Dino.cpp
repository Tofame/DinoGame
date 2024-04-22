#pragma once

#include <iostream>

#include "Dino.h"
#include "../Globals.h"

Dino::Dino() : animator() {}

auto Dino::setup() -> void {
    if (!textureDinoRun.loadFromFile(projectPath+"\\Resources\\Graphics\\Characters\\raptor-run.png"))
        std::cout << "Couldn't load Dino texture (Running).";

    if (!textureDinoWalk.loadFromFile(projectPath+"\\Resources\\Graphics\\Characters\\raptor-walk.png"))
        std::cout << "Couldn't load Dino texture (Walking).";

    this->sprite = sf::Sprite();

    this->sprite.setTexture(textureDinoRun);
    this->sprite.setTextureRect(sf::IntRect(0,0,32,32));

    this->sprite.setScale(2.0f, 2.0f);

    this->sprite.setPosition(0.1 * window.getSize().x, 0.5 * window.getSize().y);

    this->setState(IS_RUNNING);

    auto *pointerSprite = &(this->sprite);
    this->animator = Animator(pointerSprite,ANIM_LOOP, defaultAnimSF);
    this->animator.start();
};

auto Dino::setState(dinoStates state) -> void {
    dinoState = state;
}

auto Dino::getState() -> dinoStates {
    return dinoState;
}

void Dino::jump() {
    float v0 = 30.0;
    auto t1 = std::chrono::high_resolution_clock::now();
    float h = 0;
    while (h >= 0) {
        auto t2 = std::chrono::high_resolution_clock::now();
        auto t = v0 * std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
        t /= 1000;
        h = v0 * t - (0.5 * (gravity + dash * 1.25) * t * t);
        this->sprite.setPosition(0.1 * window.getSize().x, 0.5 * window.getSize().y - std::max(0.0f, h));
    }
    this->setState(IS_RUNNING);
}