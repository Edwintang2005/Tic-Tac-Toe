/*
A short c++ program to help me learn c++

This will be a tic-tac-toe game that runs on the c++ framework.
*/

#include <iostream>

// Using the standard namespace (scope of the program)
using namespace std;

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
            cout << "Player number" << player << ",choose your plot!\n";
            cout << "Row (Enter from 1-3):";
            // cin is the standard input function in c++
            cin >> row;
            cout << "Column (Enter from 1 to 3):";
            cin >> col;
            if (checkplot(row, col, board)) {
                break;
            } else {
                cout << "Invalid plot!\n";
            }
        }
        

    }
}