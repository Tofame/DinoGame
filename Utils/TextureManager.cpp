#include "TextureManager.h"

 void TextureManager::setupTextures() {
     if (!backgroundTexture.loadFromFile(projectPath + "\\Resources\\Graphics\\Backgrounds\\background1.png"))
         throw std::runtime_error("Couldnt load background image");

     if (!gameOverTexture.loadFromFile(projectPath + "\\Resources\\Graphics\\UI\\GameOver1.png"))
         throw std::runtime_error("Couldnt load game over image");

     if (!textureDinoRun.loadFromFile(projectPath+"\\Resources\\Graphics\\Characters\\dinoRun.png"))
         throw std::runtime_error("Couldn't load Dino texture (Running).");

     if (!textureDinoJump.loadFromFile(projectPath + "\\Resources\\Graphics\\Characters\\dinoJump.png"))
         throw std::runtime_error("Couldn't load Dino texture (Walking).");

     if (!textureDinoDash.loadFromFile(projectPath + "\\Resources\\Graphics\\Characters\\dinoDash.png"))
         throw std::runtime_error("Couldn't load Dino texture (Walking).");

     if (!textureSaw.loadFromFile(projectPath + "\\Resources\\Graphics\\Characters\\saw.png"))
         throw std::runtime_error("Couldn't load Saw texture.");
     if (!textureTrampoline_Idle.loadFromFile(projectPath + "\\Resources\\Graphics\\Characters\\trampoline_idle.png"))
         throw std::runtime_error("Couldn't load Idle Trampoline texture.");
     if (!textureTrampoline_Animation.loadFromFile(projectPath + "\\Resources\\Graphics\\Characters\\trampoline_animation.png"))
         throw std::runtime_error("Couldn't load Animation Trampoline texture.");
}