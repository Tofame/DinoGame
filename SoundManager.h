#include <string>
#include <map>
#include "SFML/Audio.hpp"

class soundManager {
public:
    void addSound(const std::string& name);
    void playSound(const std::string& name);

private:
    std::map<std::string, sf::SoundBuffer> soundBuffers;
};