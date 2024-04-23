#pragma once

#include "Globals.h"
#include <filesystem>

// GENERAL
sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
sf::RenderWindow window = sf::RenderWindow(desktopMode, "Dino The Game");
const sf::Vector2u originalSize = window.getSize();

std::string projectPath = std::filesystem::current_path().parent_path().string();

Dino dino =  Dino(42.5);

// SYSTEM VARIABLES
double defaultAnimSF = 50; // default animator single frame interval value

const float spriteScale = 2.0;

gameStates gameState = STATE_PLAY;

const float gravity = 2.65; // the higher it is the smaller the jump (affects every jumping thing)
const float dinoPosX = 0.1; // window width * dinoPosX, places dino at this position.
const float dinoPosY = 0.7;

const float backgroundSpriteWidth = window.getSize().x * 2;

// STORED LOADED ASSETS
sf::Sound sound = sf::Sound();

sf::Texture textureDinoRun = sf::Texture();
sf::Texture textureDinoJump = sf::Texture();
sf::Texture textureDinoDash = sf::Texture();

sf::Texture textureSaw = sf::Texture();
sf::Texture textureTrampoline_Idle = sf::Texture();
sf::Texture textureTrampoline_Animation = sf::Texture();

sf::Texture backgroundTexture = sf::Texture();

sf::Sprite backgroundSprite = sf::Sprite();