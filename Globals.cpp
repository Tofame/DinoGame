#include "Globals.h"
#include <filesystem>

extern std::string projectPath = std::filesystem::current_path().parent_path().string();

extern sf::Sound sound = sf::Sound();
extern sf::Texture textureDinoRun = sf::Texture();
extern sf::Texture textureDinoWalk = sf::Texture();

extern double defaultAnimSF = 50; // default animator single frame interval value

sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
extern sf::RenderWindow window = sf::RenderWindow(desktopMode, "Dino The Game");