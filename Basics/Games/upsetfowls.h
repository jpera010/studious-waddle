#ifndef UPSETFOWLS_H
#define UPSETFOWLS_H 

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std; 

const double pi = 3.14159265;
const double grav = 9.8;

//convert degree value to radians 
double DegToRad(double deg){
    return ((deg * pi) / 180.0);
}

//prints game's intro message 
void PrintIntro() {
    cout << "Welcome to Upset Fowl! \n"; 
    cout << "The objective is to hit the Mean Swine. \n";
    return;
}

//given swines current horiz. position 
//get users desired launch angle and velocity for fow 
void GetUsrInput(double swineX, double &fowlAngle, double &fowlVel){

    cout << "\nThe Mean Swine is " << swineX << " meters away. \n";

    cout << "Enter launch angle (deg): "; 
    cin >> fowlAngle; 
    cout << endl;
    fowlAngle = DegToRad(fowlAngle); //convert to radians

    cout << "Enter launch velocity (m/s): ";
    cin >> fowlVel; 
    cout << endl;

    return;
}

//print time, x and y values 
void PrintUpdate(double t, double x, double y){
    cout << "Time " << fixed << setprecision(0)
    << setw(3) << t << "  x = " << setw(3) << x
    << "  y = " << setw(3) << y << endl;
}

//given time, angle, velocity, and gravity 
//update x and y values 
void Trajectory(double t, double a, double v, double &x, double &y){
    x = v*t*cos(a);
    y = v*t*sin(a) - 0.5 * grav * t * t;
    return;
}

double LaunchFowl(double fowlAngle, double fowlVel){

    double t = 1.0; //time (s)
    double fowlX = 0.0; 
    double fowlY = 0.0; // objects height above ground (m)

    do{
        PrintUpdate(t, fowlX, fowlY);
        Trajectory(t, fowlAngle, fowlVel, fowlX, fowlY);
        t=t+1.0;
    } while (fowlY > 0.0); // while above ground 
    PrintUpdate(t, fowlX, fowlY);

    return fowlX;
}

bool DtrmnIfHit(double fowlLandingX, double swineX){
    double beforeSwineX = 0.0; //distance before swine that is acceptable as a hit(m)
    double didHitSwine = false; //did hit the swine?

    beforeSwineX = swineX - 30; 
    if((fowlLandingX <= swineX) && (fowlLandingX >= beforeSwineX)){
        cout << "Hit'em!!!" << endl;
        didHitSwine = true; 
    }
    else {
        cout << "Missed 'em..." << endl; 
        didHitSwine = false;
    }
    return didHitSwine;
}


#endif