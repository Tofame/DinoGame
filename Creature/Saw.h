#pragma once

#include "Obstacle.h"

class Saw : public Obstacle {
public:
    Saw();

    auto setup() -> void;
    auto draw() -> void;
};
