#include "ticTacToe.h"

int main(){
    
    ///ascii for X = 88
    //ascii for O = 79

    vector <char> gameBoard(9);
    int curPlay = 0; 
    // whosTurn = PLAYER1; //player 1 always goes first and is "X"

    //initialize board to empty state 
    initVector(gameBoard);

    //display empty board
    drawBoard(gameBoard); 

    //todo play until game is over 
    while(!gameWon(gameBoard)){

        //get a play
        curPlay = getPlay(gameBoard); 

        //set the play on the board 
        //todo switch the turn to the other player 
        if(whosTurn == PLAYER1){
            gameBoard.at(curPlay) = 'X';
            whosTurn = PLAYER2;
        }
        else {
            gameBoard.at(curPlay) = 'O';
            whosTurn = PLAYER1;
        }

        //todo output the updated board
        drawBoard(gameBoard);  

        if(boardFull(gameBoard)){
            break;
        }
    }

    //todo determine winner and output appropriate message 

    cout << "either someone won or no one won" << endl;

    return 0;

}