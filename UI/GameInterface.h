#pragma once

#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"

class GameInterface {
public:
    static void setupBackgroundTexture();

    void drawBackground();
};