#include <iostream>
#include <sfml/Graphics.hpp>
#include <filesystem>

#include "Dino.h"
#include "SoundManager.h"

int main() {
    auto projectpath=std::filesystem::current_path().parent_path();

    SoundManager::createSound("die");
    SoundManager::playSound("die");

    auto d = Dino();
    auto window = sf::RenderWindow(
            sf::VideoMode(800,600),"test");

    auto event = sf::Event();
    auto shape = sf::CircleShape(80);
    auto sprite = sf::Sprite();

    auto texture = sf::Texture();
    texture.loadFromFile(projectpath.string()+"\\Graphics\\Characters\\mario.png");
    sprite.setTexture(texture);
    shape.setTexture(&texture);
    sprite.setColor(sf::Color::Red);
//    sprite.setScale(0.5,0.5);
    sprite.setTextureRect(sf::IntRect(10,10,100,100));
    while (window.isOpen()){
        window.clear();
        window.draw(sprite);
       // window.draw(shape);
        window.display();

        while (window.pollEvent(event)){
            if(event.type==sf::Event::Closed){
                window.close();
            }
        }
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
