#pragma once

#include <iostream>

#include "Dino.h"
#include "../Globals.h"

Dino::Dino(float mass) : animator() {
    Dino::mass = mass;
    this->setState(IS_RUNNING);
}

auto Dino::setup() -> void {
    this->sprite = sf::Sprite();

    this->sprite.setTexture(textureDinoRun);
    this->sprite.setTextureRect(sf::IntRect(0,0,32,32));

    this->sprite.setScale(spriteScale, spriteScale);

    this->sprite.setPosition(dinoPosX * window.getSize().x, dinoPosY * window.getSize().y);

    auto *pointerSprite = &(this->sprite);
    this->animator = Animator(pointerSprite,ANIM_LOOP, defaultAnimSF);
    this->animator.start();
};

auto Dino::setState(dinoStates state) -> void {
    switch(state) {
        case IS_RUNNING:
            this->sprite.setTexture(textureDinoRun);
            break;
        case IS_JUMPING:
            this->sprite.setTexture(textureDinoJump);
            this->sprite.setTextureRect(sf::IntRect(0,0,32,32));
            break;
        case IS_DASHING:
            this->sprite.setTexture(textureDinoDash);
            this->sprite.setTextureRect(sf::IntRect(0,0,32,32));
            break;
    }
    dinoState = state;
}

auto Dino::getState() -> dinoStates {
    return dinoState;
}

void Dino::jump() {
    this->setState(IS_JUMPING);

    float v0 = 30.0;
    auto t1 = std::chrono::high_resolution_clock::now();
    float h = 0;
    while (h >= 0) {
        auto t2 = std::chrono::high_resolution_clock::now();
        auto t = v0 * std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
        t /= 1000;
        h = v0 * t - (0.5 * gravity * (this->mass/30) * t * t);
        this->sprite.setPosition(dinoPosX * window.getSize().x, dinoPosY * window.getSize().y - std::max(0.0f, h));
    }
    this->setState(IS_RUNNING);
}

void Dino::dash() {
    this->setState(IS_DASHING);
}