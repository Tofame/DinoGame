#pragma once

#include <sfml/Graphics.hpp>
#include "../Utils/Animator.h"

enum dinoStates {
    IS_RUNNING = 0,
    IS_JUMPING = 1,
    IS_DASHING = 2
};

class Dino {
public:
    Dino(float mass); // Declare default constructor

    sf::Sprite sprite;

    float mass;
    dinoStates dinoState;
    sf::RectangleShape hitbox;
    sf::Vector2f defaultHitboxPos;

    Animator animator;

    auto setup() -> void;
    auto draw() -> void;
    auto handleStates() -> void;

    auto jump() -> void;
    auto isInTheAir() -> bool;
    auto isInTheAir(float offsetYtoApply) -> bool;
    auto dash() -> void;
    auto setState(dinoStates state) -> void;
    auto getState() -> dinoStates;
};