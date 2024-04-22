#include "Globals.h"
#include <filesystem>

// GENERAL
sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
extern sf::RenderWindow window = sf::RenderWindow(desktopMode, "Dino The Game");

extern std::string projectPath = std::filesystem::current_path().parent_path().string();

// SYSTEM VARIABLES
extern double defaultAnimSF = 50; // default animator single frame interval value

extern const float gravity = 1.05;
extern const float dash = 1.7;

// STORED LOADED ASSETS
extern sf::Sound sound = sf::Sound();
extern sf::Texture textureDinoRun = sf::Texture();
extern sf::Texture textureDinoWalk = sf::Texture();