#pragma once

#include <iostream>

#include "Saw.h"
#include "../Globals.h"

Saw::Saw() : animator() {};

auto Saw::setup() -> void {
    this->sprite = sf::Sprite();

    this->sprite.setTexture(textureSaw);
    this->sprite.setTextureRect(sf::IntRect(0,0,32,32));

    this->sprite.setScale(spriteScale, spriteScale);

    this->sprite.setPosition(dinoPosX * window.getSize().x, dinoPosY * window.getSize().y);

    auto *pointerSprite = &(this->sprite);
    this->animator = Animator(pointerSprite,ANIM_LOOP, defaultAnimSF);
    this->animator.start();
};