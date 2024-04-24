#pragma once

#include "Obstacle.h"

class Saw : public Obstacle {
public:
    Saw();

    sf::Sprite sprite;

    sf::RectangleShape hitbox;
    sf::Vector2f defaultHitboxPos;

    Animator animator;

    auto setup() -> void;
    auto draw() -> void;
};
