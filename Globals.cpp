#include "Globals.h"
#include <filesystem>

#include "Utils/SoundManager.h"

// GENERAL
sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
sf::RenderWindow window = sf::RenderWindow(desktopMode, "Dino The Game");
const sf::Vector2u originalSize = window.getSize();

std::string projectPath = std::filesystem::current_path().parent_path().string();

Dino dino = Dino(42.5);

// SYSTEM VARIABLES
double defaultAnimSF = 50; // default animator single frame interval value
float obstaclesSpeed = 8.90;
float backgroundSpeed = 4.70;

const float spriteScale = 2.0;

const bool drawCollisions = true;

gameStates gameState = STATE_PLAY;

const float gravity = 2.65; // the higher it is the smaller the jump (affects every jumping thing)
const float dinoPosX = 0.1; // window width * dinoPosX, places dino at this position. (ground)
const float dinoPosY = 0.7; // window width * dinoPosX, places dino at this position. (ground)

const float dashHitboxOffsetY = 15;
const float dashFallingValue = 2.05; // a value which quickens the fall when holding dash
const float defaultHitboxOffsetX = 8; // where we want relatively to dino place the hitbox
const float defaultHitboxOffsetY = 8; // where we want relatively to dino place the hitbox

const float backgroundSpriteWidth = window.getSize().x * 2;

// STORED LOADED ASSETS
sf::Sound sound = sf::Sound();

sf::Texture textureDinoRun = sf::Texture();
sf::Texture textureDinoJump = sf::Texture();
sf::Texture textureDinoDash = sf::Texture();

sf::Texture textureSaw = sf::Texture();
sf::Texture textureFlyingBird = sf::Texture();
sf::Texture textureTrampoline_Idle = sf::Texture();
sf::Texture textureTrampoline_Animation = sf::Texture();

sf::Texture backgroundTexture = sf::Texture();
sf::Sprite backgroundSprite = sf::Sprite();
sf::Texture gameOverTexture = sf::Texture();
sf::Sprite gameOverSprite = sf::Sprite();

// METHODS
void setGameState(gameStates state) {
    switch(state) {
        case STATE_PLAY: {
            gameState = state;
            break;
        }
        case STATE_PAUSE: {
            throw std::runtime_error("STATE_PAUSE GameState is not implemented yet and shouldn't be used.");
        }
        case STATE_GAMEOVER: {
            SoundManager::playSound("die");
            gameState = state;
            break;
        }
        default:
            throw std::runtime_error("An unknown gameState in Globals.cpp: " + state);
    }
}