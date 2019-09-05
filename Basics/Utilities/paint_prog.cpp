#include <iostream>
#include <math.h>
using namespace std; 

const int PAINT_COVERAGE_IN_SQ_FT = 350; 

int main(){

int height, width, area = 0;
double paint_needed = 0;

cout << "Enter wall height(feet): "; 
cin >> height;

cout << "Enter wall width(feet): ";
cin >> width; 

area = height*width;
paint_needed = static_cast<double> (area) / PAINT_COVERAGE_IN_SQ_FT;


cout << "Wall area: " << area << " square feet" <<endl;
cout << "Paint needed: " << paint_needed << endl;

cout << "Cans needed: " << ceil(paint_needed) << endl; //round up

return 0;

}