#include <iostream>
#include <stdlib.h> 
using namespace std;

double percentHeads(int coin_tosses);

int main() {

    srand(4444);
    int coin_tosses = 0;

    cout << "Enter the number of times you want to toss the coin: "; 
    cin >> coin_tosses;
    cout << "Heads came up " << percentHeads(coin_tosses) << "% of the time"<< endl;

    return 0;
}

double percentHeads(int coin_tosses) {

    double result = 0;

    for(int i = 0; i < coin_tosses; i++) {
        result = result + (rand() % 2);
    }

    return (1 - (result/coin_tosses)) * 100;
}

