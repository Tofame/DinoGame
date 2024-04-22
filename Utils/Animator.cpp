#include "Animator.h"
#include <iostream>

Animator::Animator(sf::Sprite* sheet, double singleFrameInterval) {
    this->sheet = sheet;
    this->frameCount = static_cast<int>((*sheet).getTexture()->getSize().x/(*sheet).getTexture()->getSize().y);
    this->frameIndex = 0;
    this->singleFrameInterval = singleFrameInterval;
};

Animator::Animator() {};

void Animator::start() {
    startTime =  std::chrono::high_resolution_clock::now();
}

auto Animator::updateSpriteFrame() -> void {
    std::chrono::system_clock::time_point currentTime = std::chrono::high_resolution_clock::now();
    auto elapsedTime = currentTime - startTime;

    double elapsedTimeMilliseconds = std::chrono::duration<double, std::milli>(elapsedTime).count();
    this->frameIndex = static_cast<int>((elapsedTimeMilliseconds / singleFrameInterval)) % frameCount;

    int frameHeight = (*sheet).getTexture()->getSize().y;

    (*sheet).setTextureRect(sf::IntRect(0,0,frameHeight,frameHeight));

    (*sheet).setTextureRect(sf::IntRect(frameIndex * frameHeight, 0, frameHeight, frameHeight));
    //sheet.setPosition(0.1,sheet.getPosition().y - 0.1);
    //return sheet;
}