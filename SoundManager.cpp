#include "SoundManager.h"

std::map<std::string, sf::Sound> SoundManager::soundBuffers = std::map<std::string, sf::SoundBuffer>();

auto SoundManager::createSound(const std::string& filename) -> void {
    sf::SoundBuffer buffer;

    auto projectPath=std::filesystem::current_path().parent_path();
    if (!buffer.loadFromFile(projectPath.string()+"\\" + filename + ".wav"))
        throw std::runtime_error("No sound file");

    SoundManager::soundBuffers[filename] = buffer;
}

auto SoundManager::playSound(const std::string& soundName) -> void {
    auto it = soundBuffers.find(soundName);
    if(it != soundBuffers.end()) {
        sf::Sound sound(it->second);
        sound.play();
    }
}