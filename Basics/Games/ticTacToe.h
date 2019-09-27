#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include <vector>
using namespace std; 

//global constants
const int PLAYER1 = 0; 
const int PLAYER2 = 1;
const bool CLEAR_SCREEN = true;

//uses an escape character sequence to clear the screen
void clearScreen(){
    cout << endl;

    if(CLEAR_SCREEN){
        cout << "\033c";
    }
    
    cout << endl;

    return;
}

//draws the provided tic-tac-toe board to the screen
void drawBoard(const vector <char> &gameBoard){
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

//fills vector with characters staring at lowercase a 
void initVector(vector <char> & v){
    char letter = 'a';

    for (unsigned int i = 0; i < v.size(); i++){
        v.at(i) = letter;
        letter+=1;
    }
    return;
}

//converts a character representing a cell to associated vector index, uses ascii values
int convertPosition(char boardPosition){
    int i = 0;

    for(i = 97; i < 106; i++){ //ascii values  
        if(i == int(boardPosition)){
            break;
        }
    }

    return (i - 97);
}

//determines if a spot on the board is available
bool validPlacement(const vector<char> &gameBoard, int positionIndex){

    if(gameBoard.at(positionIndex) == 'X' ||
       gameBoard.at(positionIndex) == 'O' ){
        return false; 
    }

    return true;
}

//determines if the board is full 
bool boardFull(const vector<char> &gameBoard) {
    int count = 0;

    for(unsigned int i = 0; i < gameBoard.size(); i++){
        if(gameBoard.at(i) == 'X' || gameBoard.at(i) == 'O'){
            count+=1;
        }
    }

    if(count == 9){
        cout << "No one wins - rematch?" << endl;
        return true;
    }

    return false;

}

//acquires a play from the user
//utilizes convertPosition and validPlacement functions to convert the 
//user input and then determine if the converted input is a valid play 
int getPlay(const vector<char> &gameBoard){
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


//determines if the game has been won
//winning conditions:three marks from same player in a single row, column,
//or diagonal

bool gameWon(const vector<char> &gameBoard, const int whosTurn){

    int horizCount = 0;
    int vertCount = 0; //use 3 seperate counters for easier code legibility/debugging
    int diagCount = 0;
    char whosMark = ' ';

    whosTurn == PLAYER1 ? whosMark = 'X' : whosMark = 'O';

    //check for horizontal win - positions 0,1,2 ; 3,4,5 ; 6,7,8

    for(int j = 0; j < 7 ;j=j+3){ //0, 3,6
        for(unsigned int i = 0+j; i < gameBoard.size()-(6-j); i++){ 

            if(gameBoard.at(i) == whosMark) horizCount+=1;
            if(horizCount == 3){
                return true;
            }
        }
        horizCount = 0;
    }

    //check for vertical win - positions 0,3,6 ; 1,4,7 ;3,5,8 
    for(int j = 0; j < 3; j++){
        for(unsigned int i = j; i < gameBoard.size()-(2-j); i=i+3){

            if(gameBoard.at(i) == whosMark) vertCount+=1;

            if(vertCount == 3) {
                return true;
            }
        }
        vertCount = 0;
    }

    //check for diagonal win -  positions 0,4,8 ; 2,4,6
    for(int i = 0; i < 3; i=i+2){
        for(unsigned int j = i; j < gameBoard.size()-i; j=j+4-i){
            
            if(gameBoard.at(j) == whosMark) diagCount+=1;

            if(diagCount == 3) {
                return true;
            }
        }
        diagCount = 0;
    }

    return false;
}

//set the play on the board
void setPlay(vector <char> &gameBoard, const int curPlay, const int whosTurn){

    whosTurn == PLAYER1 ? gameBoard.at(curPlay) = 'X' : gameBoard.at(curPlay) = 'O';

    return;
}

#endif