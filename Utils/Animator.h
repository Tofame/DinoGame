#pragma once

#include <chrono>

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"

enum states {
    ANIM_STOP = 0,
    ANIM_LOOP = 1,
    ANIM_ONCE = 2
};

class Animator {
private:
    sf::Sprite& sprite;
    int frameCount;
    int frameIndex;
    std::chrono::system_clock::time_point startTime;
    double singleFrameInterval;

public:
    Animator(sf::Sprite& sprite, states state, double singleFrameInterval);

    Animator();

    states state;

    void start();

    auto updateSpriteFrame() -> void;
};