#include "FontManager.h"

void FontManager::setupFonts() {
    if (!font_KaphRegular.loadFromFile(projectPath + "\\Resources\\Fonts\\Kaph-Regular.ttf")) {
        throw std::runtime_error("Couldnt load font Kaph-Regular");
    }

    if (!font_KaphItalic.loadFromFile(projectPath + "\\Resources\\Fonts\\Kaph-Italic.ttf")) {
        throw std::runtime_error("Couldnt load font Kaph-Italic");
    }
}

void FontManager::setupTexts() {
    setupText(text_scoreTop, font_KaphRegular, 30);
    text_scoreTop.setPosition(window.getSize().x * 0.75, window.getSize().y * 0.04);
    text_scoreTop.setString("H " + formatHighScore(game_scoreTop));

    setupText(text_scoreNow, font_KaphItalic, 30);
    text_scoreNow.setPosition(window.getSize().x * 0.90, window.getSize().y * 0.04);
}

void FontManager::setupText(sf::Text& text, sf::Font& font, unsigned int size) {
    text.setFont(font);
    text.setCharacterSize(size);
    text.setFillColor(sf::Color::White);
    text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(2);
    text.setStyle(sf::Text::Regular); // text style
}