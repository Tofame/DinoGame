#pragma once

#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"

class GameInterface {
public:
    static void drawPlayScreen();
    static void drawGameOverScreen();

    static void drawObstacles();
    static void drawBackgroundImage();
    static void drawScore();

    static void setupBackgroundTexture();
    static void setupGameOverTexture();
    static void setupUI();
};