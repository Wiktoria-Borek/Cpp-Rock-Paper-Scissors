#include "GameLogic.h"
#include <cstdlib>
#include <ctime>

GameLogic::GameLogic() : playerChoice(Choice::None), computerChoice(Choice::None) {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

void GameLogic::SetPlayerChoice(Choice choice) {
    playerChoice = choice;
}

void GameLogic::GenerateComputerChoice() {
    computerChoice = static_cast<Choice>(std::rand() % 3);
}

GameLogic::Result GameLogic::GetResult() const {
    if (playerChoice == computerChoice) return Result::Tie;
    if ((playerChoice == Choice::Rock && computerChoice == Choice::Scissors) ||
        (playerChoice == Choice::Paper && computerChoice == Choice::Rock) ||
        (playerChoice == Choice::Scissors && computerChoice == Choice::Paper))
        return Result::Win;
    return Result::Lose;
}

std::string GameLogic::GetResultString() const {
    switch (GetResult()) {
        case Result::Win: return "You win!";
        case Result::Lose: return "You lose!";
        case Result::Tie: return "It's a tie!";
        default: return "";
    }
}

std::string GameLogic::GetPlayerChoiceString() const {
    switch (playerChoice) {
        case Choice::Rock: return "Rock";
        case Choice::Paper: return "Paper";
        case Choice::Scissors: return "Scissors";
        default: return "";
    }
}

std::string GameLogic::GetComputerChoiceString() const {
    switch (computerChoice) {
        case Choice::Rock: return "Rock";
        case Choice::Paper: return "Paper";
        case Choice::Scissors: return "Scissors";
        default: return "";
    }
}
