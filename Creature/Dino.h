#pragma once

#include <sfml/Graphics.hpp>
#include "../Utils/Animator.h"

class Dino {
public:
    Dino(); // Declare default constructor

    sf::Sprite sprite;

    auto getSprite() -> sf::Sprite;

    Animator animator;

    auto setupSprites() -> void;
};