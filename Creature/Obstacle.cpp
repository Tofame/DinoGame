#pragma once

#include <iostream>

#include "Obstacle.h"
#include "../Globals.h"

Obstacle::Obstacle() : animator() {};

auto Obstacle::setup() -> void {
    this->sprite = sf::Sprite();
    this->sprite.setTexture(textureSaw);

    auto spriteHeight = this->sprite.getTexture()->getSize().y;
    auto spriteWidth = spriteHeight;

    this->sprite.setTextureRect(sf::IntRect(0,0,spriteWidth,spriteHeight));

    this->sprite.setScale(spriteScale, spriteScale);

    this->sprite.setPosition(window.getSize().x + spriteWidth, dinoPosY * window.getSize().y + 10);

    auto *pointerSprite = &(this->sprite);
    this->animator = Animator(pointerSprite,ANIM_LOOP, defaultAnimSF);
    this->animator.start();
};

auto Obstacle::draw() -> void {
    this->animator.updateSpriteFrame();
    window.draw(this->sprite);

    // DRAW HITBOX
    window.draw(this->hitbox);
}