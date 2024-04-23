#pragma once

#include "TextureManager.h"

#include <iostream>

 void textureManager::setupTextures() {
    if (!backgroundTexture.loadFromFile(projectPath + "\\Resources\\Graphics\\Backgrounds\\background2.png")) {
        throw std::runtime_error("Couldnt load background image");
    }

    if (!textureDinoRun.loadFromFile(projectPath+"\\Resources\\Graphics\\Characters\\raptor-run.png"))
        std::cout << "Couldn't load Dino texture (Running).";

    if (!textureDinoWalk.loadFromFile(projectPath+"\\Resources\\Graphics\\Characters\\raptor-walk.png"))
        std::cout << "Couldn't load Dino texture (Walking).";
}