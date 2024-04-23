#pragma once

#include "TextureManager.h"

#include <iostream>

 void textureManager::setupTextures() {
    if (!backgroundTexture.loadFromFile(projectPath + "\\Resources\\Graphics\\Backgrounds\\background2.png")) {
        throw std::runtime_error("Couldnt load background image");
    }

    if (!textureDinoRun.loadFromFile(projectPath+"\\Resources\\Graphics\\Characters\\dinoRun.png"))
        std::cout << "Couldn't load Dino texture (Running).";

    if (!textureDinoJump.loadFromFile(projectPath + "\\Resources\\Graphics\\Characters\\dinoJump.png"))
        std::cout << "Couldn't load Dino texture (Walking).";

     if (!textureDinoDash.loadFromFile(projectPath + "\\Resources\\Graphics\\Characters\\dinoDash.png"))
         std::cout << "Couldn't load Dino texture (Walking).";
}