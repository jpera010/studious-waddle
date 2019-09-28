#include <iostream>
using namespace std;

double mean(const double array[], int arraySize);
void remove(double array[], int &arraySize, int index);
void display(const double array[], int arraySize);

int main(){
    int arraySize = 10;
    int index = 0;
    double myArray[arraySize];

    cout << "Enter 10 values:" << endl;
    for(int i = 0; i < arraySize; i++) cin >> myArray[i];
    cout << "Mean: " << mean(myArray, arraySize) << endl;

    do{
        cout << "Enter index of value to be removed (0-9): ";
        cin >> index;
    }while(index < 0 || index > 9);

    cout << "Before removing value: ";
    display(myArray,arraySize);

    remove(myArray, arraySize, index);

    cout << "After removing value: ";
    display(myArray,arraySize);


    return 0;
}

double mean(const double myArray[], int arraySize){

    double mean = 0.0;
    for(int i = 0; i < arraySize; i++) { mean += myArray[i]; }
    return mean/double(arraySize);
}

void remove(double myArray[], int &arraySize, int index){

    double myArrayCopy[arraySize-1];

    for(int i = 0; i < arraySize; i++) {
        if(i < index){ 
            myArrayCopy[i] = myArray[i]; 
        } else if(i >= index){
            myArrayCopy[i] = myArray[i+1];
        }
    }

    arraySize-=1;
    for(int i = 0; i < arraySize; i++){
        myArray[i] = myArrayCopy[i];
    }

    return;
}

void display(const double myArray[], int arraySize){

    for(int i = 0; i < arraySize; i++) { cout << myArray[i] << " "; }
    cout << endl;
    return;
}