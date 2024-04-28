#pragma once

#include "Obstacle.h"

class FlyingBird : public Obstacle {
public:
    FlyingBird();

    auto setup() -> void;
    auto draw() -> void;
};
