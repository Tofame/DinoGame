#pragma once

#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"

#include "Creature/Dino.h"

// GENERAL
extern sf::RenderWindow window;
extern const sf::Vector2u originalSize;

extern std::string projectPath;

extern Dino dino;

// SYSTEM VARIABLES
extern double defaultAnimSF;
extern float obstaclesSpeed;
extern float backgroundSpeed;

extern const float spriteScale;

extern const bool drawCollisions;

enum gameStates {
    STATE_PLAY = 0,
    STATE_PAUSE = 1,
    STATE_GAMEOVER = 2
};
extern gameStates gameState;


extern const float gravity;
extern const float dinoPosX;
extern const float dinoPosY;

extern const float dashHitboxOffsetY;
extern const float dashFallingValue;
extern const float defaultHitboxOffsetX;
extern const float defaultHitboxOffsetY;

extern const float backgroundSpriteWidth;

// GAME VARIABLES
extern int game_scoreTop;
extern int game_scoreNow;

// STORED LOADED ASSETS
extern sf::Sound sound;

extern sf::Texture textureDinoRun;
extern sf::Texture textureDinoJump;
extern sf::Texture textureDinoDash;

extern sf::Texture textureSaw;
extern sf::Texture textureFlyingBird;
extern sf::Texture textureTrampoline_Idle;
extern sf::Texture textureTrampoline_Animation;

extern sf::Texture backgroundTexture;
extern sf::Sprite backgroundSprite;
extern sf::Texture gameOverTexture;
extern sf::Sprite gameOverSprite;

extern sf::Font font_KaphItalic;
extern sf::Font font_KaphRegular;

extern sf::Text text_scoreTop;
extern sf::Text text_scoreNow;

// METHODS
extern void setGameState(gameStates state);
extern void increaseGameScore();
extern std::string formatHighScore(int& scoreValue);