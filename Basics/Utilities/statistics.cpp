#include <iostream>
#include <cmath>
#include <vector>

using namespace std; 

void fillVector(vector<double> &userVector) {
    double userDouble = 0.0;

    cout << "Enter numbers to populate the vector, ";
    cout << "enter any other character to end user input: ";

    while(cin >> userDouble){
        userVector.push_back(userDouble);
    }

    cout << endl; 

    return;
}

double meanVector(const vector <double> &v){

    double sum = 0.0;

    for(int i = 0; i < v.size(); i++){
        sum += v.at(i);
    }

    return sum/v.size(); 
}

double varianceVector(double vectorAvg, const vector <double> &v){
    
    double sumOfSqDif = 0.0;

    for(int i = 0; i < v.size(); i++){
        sumOfSqDif = sumOfSqDif + pow((v.at(i)-vectorAvg),2);
    }

    return sumOfSqDif/(v.size()); 
}

double standardDeviationForVariance(double vectorVariance){

    return sqrt(vectorVariance);
}

int main(){

    vector<double> userVector; 
    double avg = 0.0; 
    double var = 0.0; 
    double stdDev = 0.0;
    unsigned int i = 0; 

    fillVector(userVector);

    cout << "You entered: "; 
    
    for(i = 0; i < userVector.size(); i++){
        cout << userVector.at(i) << " ";
    }

    cout << endl;

    avg = meanVector(userVector);

    var = varianceVector(avg, userVector);

    stdDev = standardDeviationForVariance(var);

    cout << "The mean is: " << avg << endl; 
    cout << "The variance is: " << var << endl; 
    cout << "The std dev is: " << stdDev << endl;

    return 0; 
}