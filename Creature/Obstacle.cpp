#pragma once

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

    // if you change -8 -4 or anything here then do it also in jump/dash as it is hitbox's offset
    this->hitbox = sf::RectangleShape(sf::Vector2f(spriteWidth, spriteHeight));
    hitbox.setFillColor(sf::Color::Transparent);
    hitbox.setOutlineColor(sf::Color::Green);
    hitbox.setOutlineThickness(3.0f);
    hitbox.setPosition(this->sprite.getPosition());
    hitbox.move(spriteWidth/2,spriteHeight/2);
    defaultHitboxPos = hitbox.getPosition();

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