#include <iostream>
using std::cout, std::cin;

class TicTac {
    char board[3][3] = {
        {'.','.','.'},
        {'.','.','.'},
        {'.','.','.'},
    }; 

    
    bool winCheck(char player) {
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {

                if (board[row][col] != 0) {
                    // * Row Check
                    if (board[row][0] == player && board[row][1] == player && board[row][2] == player) { 
                        return true;
                    } 
                    // * Col Check
                    if (board[0][col] == player && board[1][col] == player && board[2][col] == player) {
                        return true;
                    }

                    //* diagonal Check
                    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
                        return true;
                    }
                    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
                        return true;
                    }
                }
            }
        
        return false;
        
        }
    }

    public: bool outputWinner() {
        //* outputs winner
        if (winCheck('X')) {
            cout << "Player 1 wins!" << "\n";
            return true;
        }
        else if (winCheck('O'))
        {
            cout << "Player 2 wins" << "\n";
            return true;
        }
    }

    // player controller  
    
    public: void player(int playerPosition) {
        char playerSymbol;
        int row, col;

        if (playerPosition == 1) {
            playerSymbol = 'X';
        } else if (playerPosition == 2) {
            playerSymbol = 'O';
        }

        // Get player position input
        cout << "Player " << playerPosition << "(" << playerSymbol << ")" << " choose row: ";   
        cin >> row;
        
        cout << "Player " << playerPosition << "(" << playerSymbol << ")" << " choose col: ";
        cin >> col;
        
        
        

        row--;
        col--;
        if (board[row][col] == '.' && playerSymbol == 'X') {
            board[row][col] = 'X';
        } 
        else if (board[row][col] == '.' && playerSymbol == 'O'){
            board[row][col] = 'O';  
        } 
        else {
            cout << "Spot already taken!\n";
            player(playerPosition);
        }
    }
    //     void player1() {
    //         // int row = 1, col=2;
    //         int row, col;
    //         cout << "Player 1 choose row: ";
    //         std::cin >> row;

    //         cout << "Player 1 choose col: ";
    //         std::cin >> col;

    //         row--;
    //         col--;
    //         if (board[row][col] == '.') {
    //             board[row][col] = 'X';
    //         } else {
    //             player1();
    //         }

    //     }
    // public:
    //     void player2() {
    //         int row, col;
    //         cout << "Player 2 choose row: ";
    //         std::cin >> row;

    //         cout << "Player 2 choose col: ";
    //         std::cin >> col;

    //         row--;
    //         col--;
    //         if (board[row][col] == '.') {
    //             board[row][col] = 'O';
    //         } else {
    //             player2();
    //         }

    //     }

    
    //* utils (optional) 
    public: void DisplayBoard() {
        for (auto &row : board) {
            for (char val : row) {
                cout << val;
            }
            cout << "\n";
        }
    }

    //! NOT IN USE
    bool validatePosition(int pos) {
        try {
            if (1 <= pos >= 3) {
                throw -1;
            }
        }
        catch (...) {
            cout << "Invalid position!";
            return false;
        }
        return true;
    }

};







int main() {
    TicTac game;
    int player1 = 1, player2 = 2;


    // keeps track of rounds 
    int rounds = 1;
    int maxRounds = 9;

    // guide to rows and columns
    const char* boardGuide ="        Col\n"
                            "       1 2 3\n"
                            "   row 2    \n"
                            "       3    \n";
    cout << boardGuide;
    
    
    while (true) {
        //* If winner decided: outputs winner and stops game
        if (game.outputWinner()) {
            break;
        }
        
        //* Decides whos turn it is depending on the round 
        if (rounds % 2 != 0 && rounds <= maxRounds) {
            game.player(player1);
            game.DisplayBoard();
            rounds++;
        } else if (rounds % 2 == 0 && rounds <= maxRounds) {
            game.player(player2);
            game.DisplayBoard();
            rounds++;
        } else {
            cout << "Game Over!" << "\n";
            cout << "Tied Game!";
            break;
        }
        

    }
    
    return 0;
}