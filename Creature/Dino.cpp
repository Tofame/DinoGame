#include <iostream>

#include "Dino.h"
#include "../Globals.h"

Dino::Dino(float mass) : animator() {
    Dino::mass = mass;
    this->setState(IS_RUNNING);
    this->sprite = sf::Sprite();
}

auto Dino::setup() -> void {
    this->sprite.setTexture(textureDinoRun);

    auto spriteHeight = this->sprite.getTexture()->getSize().y;
    auto spriteWidth = spriteHeight;

    this->sprite.setTextureRect(sf::IntRect(0,0,spriteWidth,spriteHeight));
    this->sprite.setScale(spriteScale, spriteScale);
    this->sprite.setPosition(dinoPosX * window.getSize().x, dinoPosY * window.getSize().y);

    // if you change -8 -4 or anything here then do it also in jump/dash as it is hitbox's offset
    this->hitbox = sf::RectangleShape(sf::Vector2f(spriteWidth - 8, spriteHeight - 8));
    hitbox.setFillColor(sf::Color::Transparent);
    hitbox.setOutlineColor(sf::Color::Yellow);
    hitbox.setOutlineThickness(1.0f);
    hitbox.setPosition(this->sprite.getPosition());
    hitbox.move(spriteWidth/2 + defaultHitboxOffsetY,spriteHeight/2 + defaultHitboxOffsetY);
    defaultHitboxPos = hitbox.getPosition();

    auto *pointerSprite = &(this->sprite);
    this->animator = Animator(pointerSprite,ANIM_LOOP, defaultAnimSF);
    this->animator.start();
};

auto Dino::reset() -> void {
    this->sprite.setTexture(textureDinoRun);
    auto spriteHeight = this->sprite.getTexture()->getSize().y;
    auto spriteWidth = spriteHeight;
    this->sprite.setTextureRect(sf::IntRect(0,0,spriteWidth,spriteHeight));

    this->sprite.setPosition(dinoPosX * window.getSize().x, dinoPosY * window.getSize().y);
    hitbox.setPosition(this->sprite.getPosition());
    hitbox.move(spriteWidth/2 + defaultHitboxOffsetY,spriteHeight/2 + defaultHitboxOffsetY);

    this->setState(IS_RUNNING);

    this->animator.state = ANIM_LOOP;
    this->animator.start();
}

auto Dino::draw() -> void {
    if(this->dinoState == IS_RUNNING) { // If is running update sprite frame with animator
        this->animator.updateSpriteFrame();
    }

    this->handleStates();
    window.draw(this->sprite);

    // DRAW HITBOX
    if(drawCollisions)
        window.draw(this->hitbox);
}

auto Dino::handleStates() -> void {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        if(this->getState() != IS_DASHING) {
            this->dash();
        }
    } else {
        // ABOVE THE GROUND (IN THE AIR)
        if (this->isInTheAir()) {
            if(this->getState() != IS_JUMPING)
                this->setState(IS_JUMPING);
        } else { // ON THE GROUND
            if(this->getState() != IS_RUNNING)
                this->setState(IS_RUNNING);
        }
    }
}


auto Dino::setState(dinoStates state) -> void {
    switch(state) {
        case IS_RUNNING:
            this->hitbox.setPosition(this->defaultHitboxPos);
            this->sprite.setTexture(textureDinoRun);
            break;
        case IS_JUMPING:
            this->sprite.setTexture(textureDinoJump);
            this->sprite.setTextureRect(sf::IntRect(0,0,sprite.getTexture()->getSize().y,sprite.getTexture()->getSize().y));
            break;
        case IS_DASHING:
            this->sprite.setTexture(textureDinoDash);
            this->sprite.setTextureRect(sf::IntRect(0,0,sprite.getTexture()->getSize().y,sprite.getTexture()->getSize().y));
            break;
    }
    dinoState = state;
}

auto Dino::getState() -> dinoStates {
    return dinoState;
}

void Dino::jump() {
    if(this->getState() == IS_DASHING) {
        this->hitbox.setPosition(this->defaultHitboxPos);
        this->hitbox.move(0, 20.0); // when going from dashing to jumping the hitbox was going up by A LOT
        // so this is meant to "balance it out"
    }
    this->setState(IS_JUMPING);

    float v0 = 30.0;
    auto t1 = std::chrono::high_resolution_clock::now();
    float h = 0;
    float hLast = 0;
    while (h >= 0 && gameState != STATE_GAMEOVER) {
        auto t2 = std::chrono::high_resolution_clock::now();
        auto t = (v0 * std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count()) / 1000;
        h = v0 * t - (0.5 * gravity * (this->mass/30) * t * t);
        this->sprite.move(0, (hLast - h));
        this->hitbox.move(0, (hLast -h));
        if((hLast - h > 0) && !isInTheAir(hLast-h)) break;
        hLast = h;

        //this->sprite.setPosition(dinoPosX * window.getSize().x, dinoPosY * window.getSize().y - std::max(0.0f, h));
        //this->hitbox.setPosition(hitbox.getPosition().x, dinoPosY * window.getSize().y - std::max(0.0f, h) + (hitbox.getSize().y/2 + 8));
    }
    // We do this as there will be an edge case (very rare) where last setPos call in while wouldnt have h = 0
    this->sprite.setPosition(dinoPosX * window.getSize().x, dinoPosY * window.getSize().y);
    this->setState(IS_RUNNING);
}

auto Dino::isInTheAir() -> bool {
    return (this->isInTheAir(0));
}

auto Dino::isInTheAir(float offsetYtoApply) -> bool {
    return ((this->sprite.getPosition().y + offsetYtoApply) < dinoPosY * window.getSize().y);
}

void Dino::dash() {
    if(getState() != IS_JUMPING)
        dino.hitbox.move(0, dashHitboxOffsetY);
    this->setState(IS_DASHING);
}