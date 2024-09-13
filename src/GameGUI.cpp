#include "GameGUI.h"
#include <SFML/Graphics.hpp>
#include <iostream>

GameGUI::GameGUI() : window(sf::VideoMode(800, 600), "Rock Paper Scissors"), playerMadeChoice(false) {
    if (!font.loadFromFile("arial.ttf")) { // Make sure you have Arial font or replace with a valid font
        std::cerr << "Error loading font!" << std::endl;
    }
    textDisplay.setFont(font);
    textDisplay.setCharacterSize(24);
    textDisplay.setFillColor(sf::Color::White);
}

void GameGUI::Run() {
    while (window.isOpen()) {
        ProcessEvents();
        if (playerMadeChoice) {
            gameLogic.GenerateComputerChoice();
            playerMadeChoice = false;
        }
        Update();
        Render();
    }
}

void GameGUI::ProcessEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {
                case sf::Keyboard::R:
                    gameLogic.SetPlayerChoice(GameLogic::Choice::Rock);
                    playerMadeChoice = true;
                    break;
                case sf::Keyboard::P:
                    gameLogic.SetPlayerChoice(GameLogic::Choice::Paper);
                    playerMadeChoice = true;
                    break;
                case sf::Keyboard::S:
                    gameLogic.SetPlayerChoice(GameLogic::Choice::Scissors);
                    playerMadeChoice = true;
                    break;
                default:
                    break;
            }
        }
    }
}

void GameGUI::Update() {
    // Optionally, add code here to update game state
}

void GameGUI::Render() {
    window.clear();

    std::string resultText = "Your choice: " + gameLogic.GetPlayerChoiceString() + "\n" +
                             "Computer's choice: " + gameLogic.GetComputerChoiceString() + "\n" +
                             gameLogic.GetResultString();
    DrawText(resultText, 10, 10);

    window.display();
}

void GameGUI::DrawText(const std::string& text, float x, float y) {
    textDisplay.setString(text);
    textDisplay.setPosition(x, y);
    window.draw(textDisplay);
}
