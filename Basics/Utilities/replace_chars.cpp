#include <iostream>
using namespace std; 

int main(){

    string word;
    cout << "Enter word: "; 
    cin >> word; 

    for(int i = 0; i < word.size(); i++){
        if(word.at(i) == 'a'){
            word.at(i) = '@';
        }
        if(word.at(i) == 'e'){
            word.at(i) = '3';
        }
        if(word.at(i) == 'i'){
            word.at(i) = '!';
        }
        if(word.at(i) == 'g'){
            word.at(i) = '9';
        }
        if(word.at(i) == 's'){
            word.at(i) = '$';
        }
        if(word.at(i) == 'x'){
            word.at(i) = '*';
        }
    }

    cout << word << endl;

    return 0;
}