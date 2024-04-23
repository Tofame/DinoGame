#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"

#include <thread>

// GENERAL
extern sf::RenderWindow window;

extern std::string projectPath;

// SYSTEM VARIABLES
extern double defaultAnimSF;

extern const float spriteScale;

extern const float gravity;
extern const float dash;
extern const float dinoPosX;
extern const float dinoPosY;

extern const float backgroundSpriteWidth;

// STORED LOADED ASSETS
extern sf::Sound sound;
extern sf::Texture textureDinoRun;
extern sf::Texture textureDinoWalk;
extern sf::Texture backgroundTexture;
extern sf::Sprite backgroundSprite;