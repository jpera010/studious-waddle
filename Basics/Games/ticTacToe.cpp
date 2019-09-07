#include "ticTacToe.h"
int main(){

    vector <char> gameBoard(9);
    int curPlay = 0; 
    int whosTurn = PLAYER1; //player 1 always goes first and is "X"

    //initialize board to empty state 
    initVector(gameBoard);

    //display empty board
    drawBoard(gameBoard);

    //play until game is over 
    while(!boardFull(gameBoard)){

        //get a play
        curPlay = getPlay(gameBoard); 

        //set play on board
        setPlay(gameBoard,curPlay, whosTurn);

        //output the updated board
        drawBoard(gameBoard); 

        //check if game won after the play is set
        if(gameWon(gameBoard, whosTurn)){
            whosTurn == PLAYER1 ? cout << "Player 1 (X) wins!" << endl: 
                                  cout << "Player 2 (O) wins!" << endl;
            break;    
        }

        //switch turns if no one has won yet
        whosTurn == PLAYER1 ? whosTurn = PLAYER2 : whosTurn = PLAYER1;
    }
    
    return 0;
}