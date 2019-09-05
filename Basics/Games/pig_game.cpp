#include <iostream>
#include<stdlib.h>
#include <cstdlib>
#include <ctime> 
using namespace std; 

const int PLAYER1 = 0; 
const int PLAYER2 = 1; 
const int WINNING_SCORE = 100;


void printIntro(); 
void getPlayerNames(string &, string &);
void humanTurn(string, int &);

int main(){
    srand(4444);

    int turn = PLAYER1;
    int player1score = 0;
    int player2score = 0;
    string player1name, player2name;

    printIntro();

    getPlayerNames(player1name, player2name);

    //play game 

    while(player1score < WINNING_SCORE && player2score < WINNING_SCORE){

        //player1 or player 2's turn
        if(turn == PLAYER1){
            humanTurn(player1name, player1score);
            turn = PLAYER2;
        }
        else{
            humanTurn(player2name, player2score);
            turn = PLAYER1;
        }

    }

    if(player1score > WINNING_SCORE){
        cout << player1name << " wins!" << endl;
    }
    else{
        cout << player2name << " wins!" << endl;
    }

    return 0;

}

void printIntro(){

    cout << "Welcome to the dice game Pig!" << endl; 
    cout << "The objective is to be the first to score 100 points.\n" << endl; 

    return;
}

void getPlayerNames(string &player1name, string &player2name){

    cout << "Player 1 - Enter your name: ";
    getline(cin, player1name);
    cout << endl;

    cout << "Player 2 - Enter your name: ";
    getline(cin, player2name);
    cout << endl;

    return;
}

void humanTurn(string playerName, int &playerScore){

    char ans = 'y'; 
    int rolled = 0;

    while (ans == 'y'){
        cout << playerName << endl;
        rolled = ((rand() % 6) + 1);

        if(rolled == 1){
            cout << "You rolled a 1 (PIG!)" << endl;
            cout << "Your turn is over" << endl;
            cout << "Your score: " << playerScore << "\n" << endl;
            break;
        }

        cout << "You rolled a " << rolled << endl; 
        playerScore = playerScore + rolled; 

        if(playerScore > WINNING_SCORE){
            break;
        }

        cout << "Your score: " << playerScore << endl; 
        cout << "Roll again? (y/n): ";
        cin >> ans;
        cout << endl;
    }

    return;
}