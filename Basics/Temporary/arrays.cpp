#include <iostream>
#include <array>
#include <vector>
using namespace std; 

int main(){

    array<int,15> test_arr; 
    int myArray [15]; 

    for(unsigned int i = 0; i < test_arr.size(); i++){
        test_arr.at(i) = i+1; //populate array
    }

    for(auto i = test_arr.begin(); i !=test_arr.end() ; i++){
        cout << *i << " "; //output array 
    }
    cout << endl;

    for(unsigned int i = 0; i < test_arr.size(); i++){
        myArray[i] = i+1; //populate array
    }

    for(unsigned int i = 0; i < 15;i++){
        cout << myArray[i] << " "; //output array
    }
    cout << endl;



    int target = 9;
    vector<int> answer;

    answer.push_back(2);
    answer.push_back(7);
    answer.push_back(11);
    answer.push_back(15);
    
    for(int i = 0; i < answer.size(); i++){
        for(int j = i+1; j < answer.size(); j++){
                if(answer.at(i) + answer.at(j) == target){
                    cout << i << " " << j << endl;
                }
        }
    }


    int sizeOfArray = 5;
    array<int,5> myArray;
    int oldArray [sizeOfArray];
    int twoDArr [sizeOfArray][sizeOfArray];
    int tempTwoDArr [sizeOfArray][sizeOfArray];

    int amnt = 1;
    for(unsigned i = 0; i < sizeOfArray; i++){ //iterates through height
        for(unsigned j = 0; j < sizeOfArray; j++){ //iterates through width
            twoDArr[i][j] = amnt;
            amnt++;
            cout << twoDArr[i][j] << " ";
        }
        cout << endl; //skips to next line
    }

    cout << endl;

 //now reverse the array 
    int xPosition = 0; 
    int yPosition = 0;
    for(int i = sizeOfArray-1; i >= 0 ; i--){
        for(int j = sizeOfArray-1; j >= 0; j--){
            tempTwoDArr[yPosition][xPosition]= twoDArr[i][j];
            //cout << twoDArr[i][j] << " ";
            xPosition++;
        }
        xPosition = 0;
        yPosition++;
        //cout << endl;
    }

    for(int i = 0; i < sizeOfArray ; i++){
        for(int j = 0; j < sizeOfArray; j++){
            //tempTwoDArr[sizeOfArray -i][sizeOfArray-j] = twoDArr[i][j];
            cout << tempTwoDArr[i][j] << " ";
        }
        cout << endl;
    }




    return 0;


}