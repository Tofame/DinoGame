#pragma once

#include <sfml/Graphics.hpp>

class Dino {
public:
    sf::Sprite sprite;

    auto getSprite() -> sf::Sprite;

    auto setupSprite() -> void;
};