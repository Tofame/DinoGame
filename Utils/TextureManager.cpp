#pragma once

#include "TextureManager.h"

#include <iostream>

 void TextureManager::setupTextures() {
    if (!backgroundTexture.loadFromFile(projectPath + "\\Resources\\Graphics\\Backgrounds\\background1.png")) {
        throw std::runtime_error("Couldnt load background image");
    }

    if (!textureDinoRun.loadFromFile(projectPath+"\\Resources\\Graphics\\Characters\\dinoRun.png"))
        std::cout << "Couldn't load Dino texture (Running).";

    if (!textureDinoJump.loadFromFile(projectPath + "\\Resources\\Graphics\\Characters\\dinoJump.png"))
        std::cout << "Couldn't load Dino texture (Walking).";

     if (!textureDinoDash.loadFromFile(projectPath + "\\Resources\\Graphics\\Characters\\dinoDash.png"))
         std::cout << "Couldn't load Dino texture (Walking).";

     if (!textureSaw.loadFromFile(projectPath + "\\Resources\\Graphics\\Characters\\saw.png"))
         std::cout << "Couldn't load Saw texture.";
     if (!textureTrampoline_Idle.loadFromFile(projectPath + "\\Resources\\Graphics\\Characters\\trampoline_idle.png"))
         std::cout << "Couldn't load Idle Trampoline texture.";
     if (!textureTrampoline_Animation.loadFromFile(projectPath + "\\Resources\\Graphics\\Characters\\trampoline_animation.png"))
         std::cout << "Couldn't load Animation Trampoline texture.";
}