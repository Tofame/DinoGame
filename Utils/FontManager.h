#pragma once

#include "../Globals.h"

class FontManager {
public:
    static void setupFonts();
    static void setupTexts();
    static void setupText(sf::Text& text, sf::Font& font, unsigned int size);
};