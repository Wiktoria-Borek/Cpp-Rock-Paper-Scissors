#pragma once
#include <SFML/Graphics.hpp>
#include "GameLogic.h"

class GameGUI {
public:
    GameGUI();
    void Run();

private:
    void ProcessEvents();
    void Update();
    void Render();
    void DrawText(const std::string& text, float x, float y);

    sf::RenderWindow window;
    sf::Font font;
    sf::Text textDisplay;
    GameLogic gameLogic;
    bool playerMadeChoice;
};
