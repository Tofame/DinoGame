#pragma once

#include <sfml/Graphics.hpp>
#include "../Utils/Animator.h"

class Saw {
public:
    Saw(); // Declare default constructor

    sf::Sprite sprite;

    sf::RectangleShape hitbox;
    sf::Vector2f defaultHitboxPos;

    Animator animator;

    auto setup() -> void;
    auto draw() -> void;
};