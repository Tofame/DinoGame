#pragma once

#include "soundManager.h"
#include <filesystem>
#include "../Globals.h"

void soundManager::addSound(const std::string &name) {
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile(std::filesystem::current_path().parent_path().string()+"\\Resources\\Sounds\\" + name + ".wav"))
        throw std::runtime_error("Failed to load file.");
    soundBuffers[name] = buffer;
}

void soundManager::playSound(const std::string &name) {
    auto it = soundBuffers.find(name);
    if (it != soundBuffers.end()) {
        sound.setBuffer(it->second);
        sound.play();
    } else {
        throw std::runtime_error("Sound not found.");
    }
}