#include "Globals.h"
#include <filesystem>

// GENERAL
sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
sf::RenderWindow window = sf::RenderWindow(desktopMode, "Dino The Game");

std::string projectPath = std::filesystem::current_path().parent_path().string();

// SYSTEM VARIABLES
double defaultAnimSF = 50; // default animator single frame interval value

const float spriteScale = 2.0;

const float gravity = 2.65; // the higher it is the smaller the jump (affects every jumping thing)
const float dinoPosX = 0.1; // window width * dinoPosX, places dino at this position.
const float dinoPosY = 0.7;

const float backgroundSpriteWidth = window.getSize().x * 2;

// STORED LOADED ASSETS
sf::Sound sound = sf::Sound();
sf::Texture textureDinoRun = sf::Texture();
sf::Texture textureDinoWalk = sf::Texture();
sf::Texture backgroundTexture = sf::Texture();
sf::Sprite backgroundSprite = sf::Sprite();