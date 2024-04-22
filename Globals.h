#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"

#include <thread>

// GENERAL
extern sf::RenderWindow window;

extern std::string projectPath;

// SYSTEM VARIABLES
extern double defaultAnimSF;

extern const float gravity;
extern const float dash;

// STORED LOADED ASSETS
extern sf::Sound sound;
extern sf::Texture textureDinoRun;
extern sf::Texture textureDinoWalk;