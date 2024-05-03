#include "../Globals.h"
#include "GameInterface.h"

#include <iostream>

#include "../Creature/ObstacleThread.h"
#include "../GameSystems/CollisionChecker.h"

void GameInterface::drawGameOverScreen() {
    window.clear();

    window.draw(dino.sprite);
    for (auto it = ObstacleThread::obstacles.begin(); it != ObstacleThread::obstacles.end(); ++it) {
        auto obstacle = *it;
        window.draw(obstacle->sprite);
    }

    window.draw(backgroundSprite);

    GameInterface::drawScore();

    window.draw(gameOverSprite);

    window.display();
};

void GameInterface::drawPlayScreen() {
    window.clear();

    // DRAW DINO
    dino.draw();
    // DRAW OBSTACLES
    GameInterface::drawObstacles();
    // DRAW BACKGROUND
    GameInterface::drawBackgroundImage();
    // DRAW SCORE
    GameInterface::drawScore();

    window.display();
};

void GameInterface::drawObstacles() {
    if(!ObstacleThread::obstacles.empty()) {
        for (auto it = ObstacleThread::obstacles.begin(); it != ObstacleThread::obstacles.end(); ++it) {
            auto obstacle = *it;
            // its not < 0, because texture can still be on screen even if its pos is negative and it would look weird.
            if (obstacle->sprite.getPosition().x < -64) {
                delete obstacle; // Delete the pointer
                ObstacleThread::obstacles.erase(it); // Remove the pointer from the queue
            } else {
                obstacle->draw();
                obstacle->sprite.move(-obstaclesSpeed, 0);
                obstacle->hitbox.move(-obstaclesSpeed, 0);
                if(CollisionChecker::checkCollision(obstacle->hitbox, dino.hitbox)) {
                    setGameState(STATE_GAMEOVER);
                    return;
                }
            }
        };
    }
}

void GameInterface::drawBackgroundImage() {
    window.draw(backgroundSprite);
    if(-backgroundSprite.getPosition().x > backgroundSpriteWidth/2) {
        backgroundSprite.setPosition(0, backgroundSprite.getPosition().y);
    } else {
        backgroundSprite.setPosition(backgroundSprite.getPosition().x - backgroundSpeed, backgroundSprite.getPosition().y);
    }
}

void GameInterface::drawScore() {
    text_scoreNow.setString(formatHighScore(game_scoreNow));

    window.draw(text_scoreNow);
    window.draw(text_scoreTop);
}

// SETUP METHODS

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
