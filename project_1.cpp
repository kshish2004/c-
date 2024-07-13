#include <iostream>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));
    
    int secretNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;
    
    cout << "Welcome to the Number Guessing Game!\n";
    
    do {
        // Ask the user to guess the number
        cout << "Enter your guess (between 1 and 100): ";
        
        // Ensure input is a valid integer
        while (!(cin >> guess)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(); // Clear the input buffer
        }
        
        // Increment attempts only if a valid number is entered
        attempts++;
        
        // Check if the guess is correct, too high, or too low
        if (guess == secretNumber) {
            cout << "Congratulations! You guessed the number in " << attempts << " attempts.\n";
        } else if (guess < secretNumber) {
            cout << "Too low! Try guessing higher.\n";
        } else {
            cout << "Too high! Try guessing lower.\n";
        }
        
    } while (guess != secretNumber);
    
    return 0;
}
