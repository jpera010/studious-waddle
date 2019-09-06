#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include <vector>
using namespace std; 

//global constants for player representation
const int PLAYER1 = 0; 
const int PLAYER2 = 1;
int whosTurn = PLAYER1;

const bool CLEAR_SCREEN = true;

//@brief utilizes an escape character sequence to clear the screen
void clearScreen(){
    cout << endl;

    if(CLEAR_SCREEN){
        cout << "\033c";
    }
    
    cout << endl;

    return;
}

//@brief draws the provided tic-tac-toe board to the screen
//@param board is the tic-tac-toe board that should be drawn 
void drawBoard(const vector < char > &gameBoard){
    clearScreen();
    for(int i = 0; i < 9; i +=3){
        cout << " " << gameBoard.at(i) << "  |  " << gameBoard.at(i+1)
        << "  |  " << gameBoard.at(i+2) << "  " << endl;

        if(i < 6){
            cout << "----|-----|----" << endl;
        }
    }

    cout << endl;

    return;
}

/*
brief - fills vector with characters staring at lowercase a 
 */
void initVector(vector <char> & v){
    char letter = 'a';

    for (int i = 0; i < v.size(); i++){
        v.at(i) = letter;
        letter+=1;
    }
    return;
}

/*
brief - converts a character representing a cell to associated vector index 

@param - the position to be converted to a vector index 
@return the integer index in the vector should be 0 to (vector size -1)
 */
int convertPosition(char boardPosition){
    int i = 0;

    for(i = 97; i < 106; i++){ //ascii values  
        if(i == int(boardPosition)){
            break;
        }
    }

    return (i - 97);
}

/*
@brief - predicate function to determine if a spot on the board is available 
@param - board the current tic-tac-toe board 
@param position is an index into vector to check if available 
@return true if positions state is available (not marked) AND is in bounds 
 */
bool validPlacement(const vector<char> &gameBoard, int positionIndex){
    if((int(gameBoard.at(positionIndex)) == 88) ||(int(gameBoard.at(positionIndex)) == 79) ){
        return false; 
    }

    return true;
}

/*
@brief predicate function to determine if the board is full 
@param board the current tic tac toe board
@return true iff the board is full (no cell is available)
 */
bool boardFull(const vector<char> &gameBoard) {

    bool isFull;

    for(int i = 0; i < gameBoard.size(); i++){
        if(gameBoard.at(i) == 'X' || gameBoard.at(i) == 'O'){
            isFull = true;
        }
        else{
            isFull = false;
        }
    }
    return isFull;
}


/*
@brief - acquires a play from the user as to where to put her mark 
    utilizes convertPosition and validPlacement functions to convert the 
    user input and then determine if the converted input is a valid play 

@param - board the current tic-tac-toe board
@return an integer index in board vector of a chosen available board spot 
 */
int getPlay(const vector<char> &gameBoard){
    //todo implement function 
    char boardPosition = ' ';

    do{
        cout << "Please choose a position: ";
        cin >> boardPosition;

        while(int(boardPosition) < 97 || int(boardPosition) > 105){
            cout << "Please choose position from a-i: ";
            cin >> boardPosition;
        }

    }while(!validPlacement(gameBoard,convertPosition(boardPosition)));

    return convertPosition(boardPosition);
}

/*
@brief - predicate function to determine if the game has been won

    winning conditions in tic-tac-toe require three markes from same player in a single row, column,
    or diagonal

@param - board the current tic tac toe board
@return true if the game has been won, false otherwise 
 */
bool gameWon(const vector<char> &gameBoard){

    int horizCount = 0;
    int vertCount = 0;
    int diagCount = 0;

    //check for horizontal win - positions 0,1,2 ; 3,4,5 ; 6,7,8
    for(int i = 0; i < gameBoard.size(); i++){

        gameBoard.at(i) == 'X' ? horizCount+=1: horizCount = 0;
        if(horizCount == 3) return true;
    }

    //check for vertical win - positions 0,3,6 ; 1,4,7 ;3,5,8 
    for(int j = 0; j < 3; j++){
        for(int i = j; i < gameBoard.size()-(2-j); i=i+3){

            gameBoard.at(i) == 'X' ? vertCount+=1: vertCount = 0;
            if(vertCount == 3) return true;

        }
    }
    // //check for diagonal win -  positions 0,4,8 ; 2,4,6
    for(int i = 0; i < 3; i=i+2){
        for(int j = i; j < gameBoard.size()-i; j=j+4-i){ // 0,0,+4 gives first diagonal,2, -2, +2
            
            gameBoard.at(j) == 'X' ? diagCount+=1: diagCount = 0;
            if(diagCount == 3) return true;

        }
    }

    return false;
}

#endif