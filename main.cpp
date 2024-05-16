/*
A short c++ program to help me learn c++

This will be a tic-tac-toe game that runs on the c++ framework.
*/

#include <iostream>

// Using the standard namespace (scope of the program)
using namespace std;



// Function prototype for all functions
void playAgain();
bool checkplot(int row, int col, char board[3][3]);
bool checkwin(char board[3][3], int player);
void printBoard(char board[3][3]);

int main() {
    // Initialising the board for the game
    char board[3][3] = {{' ', ' ', ' '},
                        {' ', ' ', ' '},
                        {' ', ' ', ' '}};
    int player = 1;
    int row, col;
    int turn;
    
    for (turn = 0; turn < 9; turn++) {
        // Setting up input for each turn
        while (1) {
            // cout is the standard output function in c++
            cout << "Player number " << player << ", choose your plot!\n";
            cout << "Row (Enter from 1-3): ";
            // cin is the standard input function in c++
            cin >> row;
            cout << "Column (Enter from 1 to 3): ";
            cin >> col;
            if (checkplot(row, col, board)) {
                break;
            } else {
                cout << "Invalid plot!\n";
            }
        }
        // Updating the board with the player's character
        board[row - 1][col - 1] = (char) player;
        
        printBoard(board);

        // Checking if a player has won
        if (checkwin(board, player)) {
            cout << "Player " << player << " Wins this game!\n";
            playAgain();
            return 0;
        }
        // Statement to switch player to 2 if equal to 1, 1 if equal to 2
        player = (player == 1) ? 2:1;
    }
    cout << "Draw, no one wins!\n";
    playAgain();
    return 0;
}

// A function that checks to make sure that the plot inputted is valid
bool checkplot(int row, int col, char board[3][3]) {
    if (row <= 0 || row > 3) {
        return false;
    } else if (col <= 0 || col > 3) {
        return false;
    } else if (board[row - 1][col - 1] != ' ') {
        return false;
    }
    return true;
}

// A function that checks all three in a rows to determine if player has won
bool checkwin(char board[3][3], int player) {
    // Checking rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == (char) player && board[i][1] == (char) player && board[i][2] == (char) player) {
            return true;
        } else if (board[0][i] == (char) player && board[1][i] == (char) player && board[2][i] == (char) player) {
            return true;
        }
    }
    // Checking diagonals
    if (board[0][0] == (char) player && board[1][1] == (char) player && board[2][2] == (char) player) {
        return true;
    }
    if (board[0][2] == (char) player && board[1][1] == (char) player && board[3][0] == (char) player) {
        return true;
    }
    return false;
}

// A function that prints out the game board
void printBoard(char board[3][3]) {
    cout << "-------\n";
    for (int i = 0; i < 3; i++) {
        cout << "|";
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == (char)1) {
                cout << "X|";
            } else if (board[i][j] == (char)2) {
                cout << "O|";
            } else {
                cout << " |";
            }
        }
        cout << "\n-------\n";
    }
}

// A function that allows player to play again by recalling the main function
void playAgain() {
    char cont = 'M';
    cout << "Play again? (Y/N)\n";
    cin >> cont;
    if (cont != 'Y' && cont != 'N') {
        cout << "Invalid input, terminaing!\n";
    } else if (cont == 'Y') {
        main();
    }
    return;
}