#pragma once

#include <sfml/Graphics.hpp>
#include "../Utils/Animator.h"

enum dinoStates {
    IS_RUNNING = 0,
    IS_JUMPING = 1,
};

class Dino {
public:
    Dino(); // Declare default constructor

    sf::Sprite sprite;

    Animator animator;

    dinoStates dinoState;

    auto setup() -> void;
    auto jump() -> void;
    auto setState(dinoStates state) -> void;
    auto getState() -> dinoStates;
};