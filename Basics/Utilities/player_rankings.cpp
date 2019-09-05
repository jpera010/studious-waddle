#include <iostream>
#include <array>
using namespace std;

int main() {
    int tempscore = 0;
    array<int,3> playernums;
    array<string,3>playernames;
    string tempname;

    for(int i = 0; i < playernums.size(); i++){
        cout << "Enter player " << i+1 << "'s name: "; 
        cin >> playernames[i];
        cout << "Enter player " << i+1 << "'s score: "; 
        cin >> playernums[i];
    }

    for(int j = 0; j < 2; j++) {
        for(int i = 0; i < playernums.size(); i++){        
            if(playernums[i+1] < playernums[i]){
                tempscore = playernums[i];
                tempname = playernames[i];
                playernums[i] = playernums[i+1];
                playernames[i] =  playernames[i+1];
                playernums[i+1] = tempscore;
                playernames[i+1] = tempname;
            }
        }
    }

    for(int i = 0; i < 3; i++){        
        cout << playernums[i] << ":" << playernames[i] << endl;
    }

    return 0; 
}

// This program is on hold. Need to upgrade it with proper sorting algorithms,

// #include <iostream>
// #include <cmath>
// #include <string>
// using namespace std;

// int main() {
   
//    string name1; 
//    string name2; 
//    string name3; 
//    int yards1 = 0; 
//    int yards2 = 0; 
//    int yards3 = 0; 
   
//    cout << "Enter player 1's name:" << endl; 
//    cin >> name1;
//    cout << "Enter player 1's yards gained:" << endl;
//    cin >> yards1; 
   
//    cout << "Enter player 2's name:" << endl;  
//    cin >> name2;
//    cout << "Enter player 2's yards gained:" << endl;  
//    cin >> yards2;
   
//    cout << "Enter player 3's name:" << endl;  
//    cin >> name3;
//    cout << "Enter player 3's yards gained:" << endl; 
//    cin >> yards3;
//    cout << endl; 
   
//    cout << "Player 1 - " << name1 << ": " << yards1 << endl; 
//    cout << "Player 2 - " << name2 << ": " << yards2 << endl;   
//    cout << "Player 3 - " << name3 << ": " << yards3 << endl;   

//    if (yards1 > yards2 && yards2 > yards3) {
//       cout << "1. " << name1 << ": " <<yards1 << endl;
//       cout << "2. " << name2 << ": " <<yards2 << endl;
//       cout << "3. " << name3 << ": " <<yards3 << endl;
//    }
   
//    else if (yards1 > yards3 && yards3 > yards2) {
//       cout << "1. " << name1 << ": " <<yards1 << endl;
//       cout << "2. " << name3 << ": " <<yards3 << endl;
//       cout << "3. " << name2 << ": " <<yards2 << endl;
//    }
   
//    else if (yards2 > yards3 && yards3 > yards1) {
//       cout << "1. " << name2 << ": " <<yards2 << endl;
//       cout << "2. " << name3 << ": " <<yards3 << endl;
//       cout << "3. " << name1 << ": " <<yards1 << endl;
//    }
   
//    else if (yards2 > yards1 && yards1 > yards3) {
//       cout << "1. " << name2 << ": " <<yards2 << endl;
//       cout << "2. " << name1 << ": " <<yards1 << endl;
//       cout << "3. " << name3 << ": " <<yards3 << endl;
//    }
   
//    else if (yards3 > yards2 && yards2 > yards1) {
//       cout << "1. " << name3 << ": " <<yards3 << endl;
//       cout << "2. " << name2 << ": " <<yards2 << endl;
//       cout << "3. " << name1 << ": " <<yards1 << endl;
//    }
   
//    else if (yards3 > yards1 && yards1 > yards2) {
//       cout << "1. " << name3 << ": " <<yards3 << endl;
//       cout << "2. " << name1 << ": " <<yards1 << endl;
//       cout << "3. " << name2 << ": " <<yards2 << endl;
//    }
   

//    return 0;
// }