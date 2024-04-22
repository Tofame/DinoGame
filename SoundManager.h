#include <map>
#include <string>
#include <iostream>
#include <sfml/Audio.hpp>
#include <filesystem>

class SoundManager {
public:
    static std::map<std::string, sf::SoundBuffer> soundBuffers;

    static auto createSound(const std::string& filename) -> void;

    static auto playSound(const std::string &soundName) -> void;
};
