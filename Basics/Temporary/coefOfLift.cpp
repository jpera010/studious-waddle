#include "coefOfLift.h"

int main(int argc, char* argv[]){

    string nameOfFile;
    double userAngle, coefOfLiftDesired = 0.0;
    vector<double> flightPathAngles; 
    vector<double> coefOfLift;

    //ask user for file name 
    if(argc < 2){
        cout << "Please pass in file name that contains wind tunnel data" << endl;
        exit(1);
    }

    nameOfFile = argv[1]; 
    //transfer data to vectors, and call reorder if needed
    readData(nameOfFile, flightPathAngles, coefOfLift);

    //ask user for desired angle 
    cout << "Enter desired flight path angle: "; 
    cin >> userAngle;
    cout << endl;

    //check if angle is within bounds
    while(userAngle < flightPathAngles.front() || userAngle > flightPathAngles.back()){
        cout << "Flight path angle is not within bounds" << endl << "Enter another flight path angle: ";
        cin >> userAngle;
    }

    coefOfLiftDesired = interpolation(userAngle, flightPathAngles, coefOfLift);
    cout << "Corresponding coefficent of lift is: " << coefOfLiftDesired << endl;

    return 0;
}
