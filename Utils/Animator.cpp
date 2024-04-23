#pragma once

#include "Animator.h"
#include <iostream>

Animator::Animator(sf::Sprite* sprite, states state, double singleFrameInterval) {
    this->sprite = sprite;
    this->frameCount = static_cast<int>((*sprite).getTexture()->getSize().x/(*sprite).getTexture()->getSize().y);
    this->frameIndex = 0;
    this->singleFrameInterval = singleFrameInterval;
    this->state = state;
};

Animator::Animator() {};

void Animator::start() {
    startTime =  std::chrono::high_resolution_clock::now();
}

auto Animator::updateSpriteFrame() -> void {
    if(state == ANIM_STOP) return;

    std::chrono::system_clock::time_point currentTime = std::chrono::high_resolution_clock::now();
    auto elapsedTime = currentTime - startTime;

    double elapsedTimeMilliseconds = std::chrono::duration<double, std::milli>(elapsedTime).count();

    auto frameComponent = static_cast<int>((elapsedTimeMilliseconds / singleFrameInterval));
    this->frameIndex = frameComponent % frameCount;
    if((frameComponent >  frameCount) && (state == ANIM_ONCE))
        this->state = ANIM_STOP;


    int frameHeight = (*sprite).getTexture()->getSize().y;

    (*sprite).setTextureRect(sf::IntRect(0,0,frameHeight,frameHeight));

    (*sprite).setTextureRect(sf::IntRect(frameIndex * frameHeight, 0, frameHeight, frameHeight));
}