#pragma once

#include <filesystem>

#include "soundManager.h"
#include "../Globals.h"

std::map<std::string, sf::SoundBuffer> SoundManager::soundBuffers = std::map<std::string, sf::SoundBuffer>();

void SoundManager::addSound(const std::string &name) {
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile(std::filesystem::current_path().parent_path().string()+"\\Resources\\Sounds\\" + name + ".wav"))
        throw std::runtime_error("Failed to load file.");
    SoundManager::soundBuffers[name] = buffer;
}

void SoundManager::playSound(const std::string &name) {
    auto it = SoundManager::soundBuffers.find(name);
    if (it != SoundManager::soundBuffers.end()) {
        sound.setBuffer(it->second);
        sound.play();
    } else {
        throw std::runtime_error("Sound not found.");
    }
}