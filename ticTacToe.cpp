#include <iostream>
using std::cout;

class TicTac {
    int board[3][3] = {
        {0,0,0},
        {0,0,0},
        {0,0,0},
    }; 
    // int player1, player2;
    int winner;
    int round = 9;

    public: 
        bool winCheck() {
        
            for (int row = 0; row < 3; row++) {
                for (int col = 0; col < 3; col++) {

                    if (board[row][col] != 0) {
                        // * Row Check
                        if ((board[row][0] && board[row][1] && board[row][2]) == 2 || 1) {
                            winner = board[row][0];
                            return true;
                        }
                        // * Col Check
                        if ((board[0][col] && board[1][col] && board[2][col]) == 2 || 1) {
                            winner = board[0][col];
                            return true;
                        }

                        //* dia Check
                        if ((board[0][0] && board[1][1] && board[2][2]) == 2 || 1) {
                            winner = board[0][0];
                            return true;
                        }
                        if ((board[0][2] && board[1][1] && board[2][0]) == 2 || 1) {
                            winner = board[0][2];
                            return true;
                        }
                    }
                }
            
            return false;
            
        }

        


    }

        int outputWinner() {
            //* outputs winner
            if (winner == 1) {
                cout << "Player 1 wins!" << "\n";
            }
            else if (winner == 2)
            {
                cout << "Player 2 wins" << "\n";
            }
            else {
                cout << "Tied!" << "\n";
            }
        }

    //* Refactor player controller into a single method    
    public:
        void player1() {
            int row = 1, col=2;
            cout << "Player 1 choose row: ";
            // std::cin >> row;

            cout << "Player 1 choose col: ";
            // std::cin >> col;

            row--;
            col--;
            board[row][col] = 1;

        }
    public:
        void player2() {
            int row, col;
            cout << "Player 1 choose row: ";
            std::cin >> row;

            cout << "Player 1 choose col: ";
            std::cin >> col;

            row--;
            col--;
            board[row][col] = 2;

        }

    public:
        void DisplayBoard() {
            for (auto &row : board) {
                for (int val : row) {
                    cout << val;
                }
                cout << "\n";
            }
        }

};







int main() {
    int rounds = 1;
    TicTac game;

    
    while (true) {
        //* If winner decided: outputs winner and stops game
        if (game.winCheck()) {
            game.outputWinner();
            game.DisplayBoard();
            break;
        }

        if (rounds % 2 != 0 && rounds <= 10) {
            game.player1();
            rounds++;
        } else {
            game.player2();
            rounds++;
        }
        game.DisplayBoard();

    }
    
    cout << "Game over!";
    
    
    
    return 0;
}