#include <iostream>
#include <conio.h>  // For _getch()
#include <map>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

int main() {
    char userChoice;
    char computerChoice;
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

        // Seed the random number generator
        srand(static_cast<unsigned int>(time(0)));

        // Generate a random choice for the computer
        int randomChoice = rand() % 3;  // Generates 0, 1, or 2
        switch (randomChoice) {
            case 0: computerChoice = 'r'; break;
            case 1: computerChoice = 'p'; break;
            case 2: computerChoice = 's'; break;
        }
        std::cout << "Computer chose: " << choices[computerChoice] << std::endl;

        // Determine the winner
        if (userChoice == computerChoice) {
            std::cout << "It's a tie!" << std::endl;
        } else if ((userChoice == 'r' && computerChoice == 's') ||
                   (userChoice == 'p' && computerChoice == 'r') ||
                   (userChoice == 's' && computerChoice == 'p')) {
            std::cout << "You win!" << std::endl;
        } else {
            std::cout << "Computer wins!" << std::endl;
        }

    } else {
        std::cout << "\nInvalid choice." << std::endl;
    }

    return 0;
}
