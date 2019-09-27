#ifndef COEFOFLIFT_H
#define COEFOFLIFT_H

#include<iomanip>
#include <iostream>
#include <fstream>
#include <vector>
#include<time.h>
using namespace std;

bool isOrdered(const vector<double> &flightPathAngles){
    for(unsigned i = 0; i < flightPathAngles.size()-1; i++){
        if(flightPathAngles.at(i) > flightPathAngles.at(i+1)){
            return false;
        }
    }
    return true;
}

void reorder(vector<double> &flightPathAngles, vector<double> &coefOfLift){

    //implement selection sort
    unsigned i,j,min;

    for(i = 0 ;i < flightPathAngles.size()-1; i++){

        min = i;

        for(j = i+1;j < flightPathAngles.size(); j++){
            if(flightPathAngles.at(j) < flightPathAngles.at(min)) min = j;
        } 
        swap(flightPathAngles.at(i),flightPathAngles.at(min));
        swap(coefOfLift.at(i),coefOfLift.at(min));
    }

    return;
}

void readData(const string &nameOfFile, vector<double> &flightPathAngles, vector<double> &coefOfLift){

    double value = 0.0;
    ifstream myfile;
    myfile.open(nameOfFile.c_str());

    if(myfile.is_open()){
        while(!myfile.eof()){
            myfile >> value;
            flightPathAngles.push_back(value);
            myfile >> value;
            coefOfLift.push_back(value);
        }
    } else {
        cout << "Error opening file. Try again" << endl;
        exit(1);        
    }

    myfile.close();

    if(isOrdered(flightPathAngles) == false) {
        reorder(flightPathAngles, coefOfLift); 
    }

    return;
}

double interpolation(double userAngle, const vector<double> &flightPathAngles, const vector<double> &coefOfLift){

    double a, c, f_of_a, f_of_b, f_of_c = 0.0; 
    unsigned i = 0;

    a = flightPathAngles.at(i);
    f_of_a = coefOfLift.at(i);
    c = flightPathAngles.at(i+1);
    f_of_c = coefOfLift.at(i+1);

    
    for(i = 0; i < flightPathAngles.size()-1; i++){

        if(flightPathAngles.at(i) == userAngle) { //case for when program finds the correct angle in the vectors
            return coefOfLift.at(i);
        }
        
        if((a < userAngle) && (userAngle > c)){ //case for when program needs to compute interpolation
            a = c;
            f_of_a = coefOfLift.at(i+1);
            c = flightPathAngles.at(i+2);
            f_of_c = coefOfLift.at(i+2);
        }
    }

    f_of_b = f_of_a + (userAngle-a)/(c-a)*(f_of_c-f_of_a);
    return f_of_b;
}


#endif


