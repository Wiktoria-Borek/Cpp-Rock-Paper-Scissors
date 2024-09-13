#pragma once
#include <string>

class GameLogic {
public:
    enum class Choice { Rock, Paper, Scissors, None };
    enum class Result { Win, Lose, Tie };

    GameLogic();
    void SetPlayerChoice(Choice choice);
    void GenerateComputerChoice();
    Result GetResult() const;
    std::string GetResultString() const;
    std::string GetPlayerChoiceString() const;
    std::string GetComputerChoiceString() const;

private:
    Choice playerChoice;
    Choice computerChoice;
};
