#include "Saw.h"
#include "../Globals.h"

Saw::Saw() {
    this->animator = Animator();
};

auto Saw::setup() -> void {
    this->sprite = sf::Sprite();

    this->sprite.setTexture(textureSaw);

    auto spriteHeight = this->sprite.getTexture()->getSize().y;
    auto spriteWidth = spriteHeight;

    this->sprite.setTextureRect(sf::IntRect(0,0,spriteWidth,spriteHeight));
    this->sprite.setScale(spriteScale, spriteScale);
    this->sprite.setPosition((window.getSize().x * 1.2) + spriteWidth, dinoPosY * window.getSize().y + 10);

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

auto Saw::draw() -> void {
    this->animator.updateSpriteFrame();
    window.draw(this->sprite);

    // DRAW HITBOX
    if(drawCollisions)
        window.draw(this->hitbox);
}