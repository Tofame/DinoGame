#pragma once

#include "SFML/Graphics/RectangleShape.hpp"

class CollisionChecker {
public:
    static bool checkCollision(sf::RectangleShape& rect1, sf::RectangleShape& rect2);
};
