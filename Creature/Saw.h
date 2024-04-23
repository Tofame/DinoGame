#pragma once

#include <sfml/Graphics.hpp>
#include "../Utils/Animator.h"

class Saw {
public:
    Saw(); // Declare default constructor

    sf::Sprite sprite;

    Animator animator;

    auto setup() -> void;
};