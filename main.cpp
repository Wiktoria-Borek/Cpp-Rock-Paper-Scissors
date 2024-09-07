#include <iostream>
#include <conio.h>  // For _getch()
#include <map>

int main() {
    char userChoice;
    std::map<char, std::string> choices = {
        {'r', "Rock"},
        {'p', "Paper"},
        {'s', "Scissors"}
    };

    std::cout << "Welcome to Rock, Paper, Scissors!" << std::endl;
    std::cout << "Press 'r' for Rock, 'p' for Paper, or 's' for Scissors: ";

    userChoice = _getch();  // Use _getch() to capture a single key press

    // Output the user's choice
    if (choices.find(userChoice) != choices.end()) {
        std::cout << "\nYou chose: " << choices[userChoice] << std::endl;
    } else {
        std::cout << "\nInvalid choice." << std::endl;
    }

    return 0;
}
