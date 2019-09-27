#include <iostream>
#include<array>
using namespace std; 

struct myStruct{

    int one = 0; 
    int two = 0;

    int add(int one, int two){
        return one + two;
    }
};

class myClass{

    private:
        int one = 0; 
        int two = 0;
        int three = 0;
        int sum = 0;
        void calcSum(int one, int two, int three){
            sum = one + two + three; 
        }

    public: 
        int getSum(int one, int two, int three){
            calcSum(one, two, three);
            return sum;
        }
};

int main(){

    myStruct test; 
    test.one = 1;
    test.two = 2; 
    int array[] = {2,7,4,1,5,3};
    //int sortedArray[6];

    cout << "one: " << test.one << " two: " << test.two << endl;
    cout << "Sum is: " << test.add(test.one,test.two) << endl;

    myClass testClass;
    
    cout << "Sum with class is: " << testClass.getSum(1,2,3) << endl;

    //implement selection sort

    int i = 0;
    int j = 0; 
    int min = 0;
    int temp =0;

    for(i = 0 ; i < 5; i++){
        min = i;
        for(j = i+1; j < 6; j++){
            if(array[min] > array[j]){
                min = j;
            }
        }
        swap(array[i], array[min]);
        // temp = array[i];
        // array[i] = array[min];
        // array[min] = temp;



    }

    for(int k = 0; k < 6;k++){
        cout << array[k] << " ";
    }
    cout << endl;

    return 0;
}