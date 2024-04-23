#pragma once

#include <string>
#include <map>
#include "SFML/Audio.hpp"

class SoundManager {
public:
    static void addSound(const std::string& name);
    static void playSound(const std::string& name);

    static std::map<std::string, sf::SoundBuffer> soundBuffers;
};