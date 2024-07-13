#include <iostream>
#include <vector>
using namespace std;

// Function prototypes
void initializeBoard(vector<vector<char>>& board);
void displayBoard(const vector<vector<char>>& board);
bool isMoveValid(const vector<vector<char>>& board, int row, int col);
bool checkWin(const vector<vector<char>>& board, char player);
bool checkDraw(const vector<vector<char>>& board);
void switchPlayer(char& currentPlayer);

int main() {
    char playAgain;
    do {
        vector<vector<char>> board(3, vector<char>(3, ' ')); // Initialize 3x3 board
        char currentPlayer = 'X'; // Player X starts first
        bool gameWon = false;
        bool gameDraw = false;
        int row, col;

        initializeBoard(board);

        // Game loop
        while (!gameWon && !gameDraw) {
            // Display current board
            displayBoard(board);

            // Prompt current player for their move
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;

            // Validate the move
            while (!isMoveValid(board, row, col)) {
                cout << "Invalid move. Please try again: ";
                cin >> row >> col;
            }

            // Make the move
            board[row][col] = currentPlayer;

            // Check if current player wins
            if (checkWin(board, currentPlayer)) {
                gameWon = true;
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins! Congratulations!\n";
                break;
            }

            // Check for draw
            if (checkDraw(board)) {
                gameDraw = true;
                displayBoard(board);
                cout << "It's a draw!\n";
                break;
            }

            // Switch to the other player
            switchPlayer(currentPlayer);
        }

        // Ask if players want to play again
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing Tic-Tac-Toe!\n";

    return 0;
}

// Function definitions

void initializeBoard(vector<vector<char>>& board) {
    // Initialize the board with empty spaces
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(const vector<vector<char>>& board) {
    // Display the current state of the board
    cout << "-------------\n";
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

bool isMoveValid(const vector<vector<char>>& board, int row, int col) {
    // Check if the move is within bounds and the cell is empty
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
}

bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; ++i) {
        // Check rows
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        // Check columns
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

bool checkDraw(const vector<vector<char>>& board) {
    // Check if the board is full (no empty spaces left)
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ')
                return false; // Found an empty space, game is not draw
        }
    }
    return true; // Board is full, game is a draw
}

void switchPlayer(char& currentPlayer) {
    // Switch players between 'X' and 'O'
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}
