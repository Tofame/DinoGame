#include <chrono>

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"

class Animator {
private:
    sf::Sprite *sheet;
    int frameCount;
    int frameIndex;
    std::chrono::system_clock::time_point startTime;
    double singleFrameInterval;

public:
    Animator();
    Animator(sf::Sprite* sheet, double singleFrameInterval);

    void start();

    auto updateSpriteFrame() -> void;
};