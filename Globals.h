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

extern const float spriteScale;

enum gameStates {
    STATE_PLAY = 0,
    STATE_PAUSE = 1,
    STATE_GAMEOVER = 2
};
extern gameStates gameState;


extern const float gravity;
extern const float dinoPosX;
extern const float dinoPosY;

extern const float backgroundSpriteWidth;

// STORED LOADED ASSETS
extern sf::Sound sound;

extern sf::Texture textureDinoRun;
extern sf::Texture textureDinoJump;
extern sf::Texture textureDinoDash;

extern sf::Texture textureSaw;
extern sf::Texture textureTrampoline_Idle;
extern sf::Texture textureTrampoline_Animation;

extern sf::Texture backgroundTexture;

extern sf::Sprite backgroundSprite;