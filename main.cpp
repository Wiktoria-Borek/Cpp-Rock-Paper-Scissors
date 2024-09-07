#include <iostream>
#include <conio.h>  // For _getch()
#include <map>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

int main() {
    char userChoice;
    char computerChoice;
    int userScore = 0;
    int computerScore = 0;
    int ties = 0;
    std::map<char, std::string> choices = {
        {'r', "Rock"},
        {'p', "Paper"},
        {'s', "Scissors"}
    };

    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    std::cout << "Welcome to Rock, Paper, Scissors!" << std::endl;
    while (true) {
        std::cout << "Press 'r' for Rock, 'p' for Paper, or 's' for Scissors (or 'q' to quit): ";

        userChoice = _getch();  // Use _getch() to capture a single key press

        if (userChoice == 'q') {
            break;  // Exit the loop and end the game
        }

        // Output the user's choice
        if (choices.find(userChoice) != choices.end()) {
            std::cout << "\n\nYou chose: " << choices[userChoice] << std::endl;

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
                std::cout << std::endl << "It's a tie!" << std::endl;
                ties++;
            } else if ((userChoice == 'r' && computerChoice == 's') ||
                       (userChoice == 'p' && computerChoice == 'r') ||
                       (userChoice == 's' && computerChoice == 'p')) {
                std::cout << std::endl << "You win!" << std::endl;
                userScore++;
            } else {
                std::cout << std::endl << "Computer wins!" << std::endl;
                computerScore++;
            }

            // Display the current scores
            std::cout << "\nScores: You - " << userScore 
                      << ", Computer - " << computerScore 
                      << ", Ties - " << ties << "\n";

        } else {
            // Display the prompt again for invalid choice
            std::cout << "\nInvalid choice. ";
        }
    }

    std::cout << "\nThanks for playing! Press any key to close this application.";

    _getch();  // Wait for a key press

    return 0;
}
