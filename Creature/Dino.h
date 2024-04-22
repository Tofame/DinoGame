#pragma once

#include <sfml/Graphics.hpp>
#include "../Utils/Animator.h"

class Dino {
public:
    Dino(); // Declare default constructor

    sf::Sprite sprite;

    auto getSprite() -> void;

    Animator animator;

    auto setup() -> void;
};