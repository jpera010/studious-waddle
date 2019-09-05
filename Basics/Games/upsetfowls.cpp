#include "upsetfowls.h"

int main() {
    double fowlAngle = 0.0; // angle of launch (rad)
    double fowlVel = 0.0; // velocity (m/s)
    double fowlLandingX = 0.0; //objects horiz. dist. from start (m)
    double swineX = 40.0; // distance to swine(m)
    int tries = 4; 

    srand(20); //to ensure testable, repeatable output 
    swineX = (rand() % 201) + 50;

    PrintIntro();

    do{
        GetUsrInput(swineX, fowlAngle, fowlVel);
        fowlLandingX = LaunchFowl(fowlAngle, fowlVel);
        tries--;

    }while(!DtrmnIfHit(fowlLandingX, swineX) && tries > 0);

    return 0;
}