#pragma once

#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"

class GameInterface {
public:
    static void setupBackgroundTexture();

    static void drawPlayScreen();
    static void drawGameOverScreen();
};