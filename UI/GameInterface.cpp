#pragma once

#include "../Globals.h"
#include "GameInterface.h"

float backgroundMoveSpeed = 0.2;

void GameInterface::drawGameOverScreen() {
    window.draw(gameOverSprite);

    window.display();
};

void GameInterface::drawPlayScreen() {
    window.clear();

    // DRAW DINO
    if(dino.dinoState == IS_RUNNING) { // If is running update sprite frame with animator
        dino.animator.updateSpriteFrame();
    }
    window.draw(dino.sprite);
    // DRAW BACKGROUND
    window.draw(backgroundSprite);
    if(-backgroundSprite.getPosition().x > backgroundSpriteWidth/2) {
        backgroundSprite.setPosition(0, backgroundSprite.getPosition().y);
    } else {
        backgroundSprite.setPosition(backgroundSprite.getPosition().x - backgroundMoveSpeed, backgroundSprite.getPosition().y);
    }

    window.display();

    // STATE HANDLING HERE
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        if(dino.getState() != IS_DASHING)
            dino.dash();
    } else {
        // ABOVE THE GROUND (IN THE AIR)
        if (dino.isInTheAir()) {
            if(dino.getState() != IS_JUMPING)
                dino.setState(IS_JUMPING);
        } else { // ON THE GROUND
            if(dino.getState() != IS_RUNNING)
                dino.setState(IS_RUNNING);
        }
    }
};

void GameInterface::setupBackgroundTexture() {
    auto *resultTexture = new sf::RenderTexture;

    if (!resultTexture->create(backgroundSpriteWidth, backgroundTexture.getSize().y))
        throw std::runtime_error("Couldnt create RenderTexture for setupBackgroundTexture()");

    auto tempSprite = sf::Sprite(backgroundTexture);
    // *2 because we want line to be 2x larger than screen
    for(auto i = 0; i < (window.getSize().x/backgroundTexture.getSize().x) * 2; i++) {
        tempSprite.setPosition(i * backgroundTexture.getSize().x, 0);
        resultTexture->draw(tempSprite);
    }

    resultTexture->display();

    backgroundSprite = sf::Sprite(resultTexture->getTexture());
    backgroundSprite.setPosition(0, dinoPosY * window.getSize().y + textureDinoRun.getSize().y * spriteScale);

    //backgroundSprite.setColor(sf::Color::Magenta);
};

void GameInterface::setupGameOverTexture() {
    gameOverSprite = sf::Sprite(gameOverTexture);
    gameOverSprite.setPosition(window.getSize().x/2 - gameOverTexture.getSize().x/2, window.getSize().y/2 - gameOverTexture.getSize().y/2 - 30);
};

void GameInterface::setupUI() {
    GameInterface::setupBackgroundTexture();
    GameInterface::setupGameOverTexture();
}
