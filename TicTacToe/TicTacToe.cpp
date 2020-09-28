
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

bool flag = true;
int choice;
int players;
char markers;

char board[3][3] = { { '1', '2', '3' }, { '4','5','6' }, { '7','8','9' } };
char turn;


void drawBoard() {
    std::cout << " " << std::endl;
    std::cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << std::endl;
    std::cout << "-----------" << std::endl;
    std::cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << std::endl;
    std::cout << "-----------" << std::endl;
    std::cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << std::endl;

}

bool placeMarker(int slot) {
    int row = slot / 3;
    int col;
    if (slot % 3 == 0) {
        row = row - 1;
        col = 2;

    }
    
    else col = (slot % 3) - 1; //makes sure that a player cant take an already filled slot 
    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = markers;
        return true;
    }
    else return false;
}

char winner() { //if one of these happens the game stops and the player that put in the last mark wins
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return players;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return players;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return players;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return players;

    return 0;
}

void playerTurn() {  //switching between player
    if (markers == 'X') markers = 'O';
    else markers = 'X';

    if (players == 1) players = 2;
    else players = 1;
}

void game() {
    std::cout << "Player 1, are you X or O? ";
        char marker1;
        std::cin >> marker1; // makes what player 1 picked its own so the program understand what to switch to under turns

        players = 1;
        markers = marker1;

     drawBoard();

     int playerWinner;



     for (int i = 0; i < 9; i++) { //makes the game just have 9 turns and if none have won it is a draw
         std::cout << "It is player " << players << " turn. Enter a number: ";
         int slot;
         std::cin >> slot;
         
         if (slot < 1 || slot > 9) {
             (std::cout << "That is not a valid number. Pick one from the board. "); //if player writh a number that is lower or higher than 9 this messange will come
             i--;
             continue;
         }
         if (!placeMarker(slot))
         {
             std::cout << "That slot is taken. Pick different one. "; //if player takes a slot that is in us they will be told to take one dat is not in us
             i--;
             continue;
         }
        
         drawBoard();
         playerWinner = winner(); //looks to see if the recuairment to win the game is fufiled if not the game continues
         if (playerWinner == 1) {
             std::cout << "Player 1 is the winner!" << std::endl;
             std::cout << " " << std::endl;
             break;
         }
         if (playerWinner == 2) {
             std::cout << "Player 2 is the winner!" << std::endl;
             std::cout << " " << std::endl;
             break;
         }

         playerTurn();
        
     }
     if (playerWinner == 0) { 
         std::cout << "It is a draw!" << std::endl;
         std::cout << " " << std::endl;
     }
}

int main() {
    char answer;

    while (flag == true) {
        std::cout << "Welcome to Tic-Tac-Toe! " << std::endl;
        std::cout << " " << std::endl;
        std::cout << "Ready to play? Y/N ";
        std::cin >> answer;

        switch (answer) {
        case 'Y': case 'y':
           game();
            break;
        case 'N': case 'n':
            std::cout << "Bye!" << std::endl;
            flag = false;
            break;
        default:
            std::cout << "sorry that is not an option... " << std::endl;
            std::cout << " " << std::endl;
        }
    } 
}







 