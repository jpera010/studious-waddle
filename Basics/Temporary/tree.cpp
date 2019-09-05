// #include <iostream>
// using namespace std;

// //need odd number for tree height, leav

// int main() {

//     int trunkHeight = 0; 
//     int trunkWidth  = 0; 
//     int leavesWidth = 0; 
    
    
//     cout << "Enter trunk height: "; 
//     cin >> trunkHeight;
    
//     cout << "Enter trunk width: ";
//     cin >> trunkWidth;
        
//     while((trunkWidth % 2) == 0) {
//         cout << "Please enter an odd number for the width: ";
//         cin >> trunkWidth;
//     }
    
//     while ((leavesWidth % 2) == 0) {
//         cout << "Enter leaves width: ";
//         cin >> leavesWidth;
//     }
    
//     cout << endl;
    
    
//     int numTimestoPrint = leavesWidth - ((leavesWidth - 1) / 2);
//     int numLeavesToPrint = 1; 
//     int numSpacesToPrint = (leavesWidth- trunkWidth) / 2;
    
//     //Draw leaves
//     for (int numLevels = 1; numLevels <= leavesWidth - ((leavesWidth - 1) / 2); numLevels++){ 
        
//         for (int numSpaces = 0; (numSpaces + 1) < (numTimestoPrint); numSpaces++){   
//             cout << ' ';
//         }
        
//         numTimestoPrint = numTimestoPrint -1; 
        
//         for (int numLeaves = 1; numLeaves <= numLeavesToPrint; numLeaves++) {
//             cout << "*";     
//         }
        
//         numLeavesToPrint = numLeavesToPrint + 2; 
        
//         cout << endl;
//     }
    
//     //Draw trunk 
//     for (int tH = 1; tH <= trunkHeight; tH++){
//         for (int j = 1; j <= numSpacesToPrint; j++) {
//             cout << " "; 
//         }
//         for (int tW = 1; tW <= trunkWidth; tW++) {
//             cout << "*"; 
//         }
//         cout << endl;
//     }
    
//     return 0;
// }



////////////////////////////////////////////
// #include <iostream>
// #include<cmath>
// using namespace std; 

// int main(){

//     int height = 0;
//     int trunkWidth = 0;
//     int leavesWidth = 0; 

//     cout << "Enter trunk height: "; 
//     cin >> height;

//     while(trunkWidth % 2 == 0){
//         cout << "Enter odd number for trunk width: ";
//         cin >> trunkWidth;
//     }

//     while(leavesWidth % 2 == 0){
//         cout << "Enter odd number for leaf width: ";
//         cin >> leavesWidth;
//     }

//     int i, j = 0;

//     for(i = 0; i < ceil(leavesWidth/2.0); i++) { // takes care of how many levels to print 
//         for(j = ceil(leavesWidth/2.0) - 1; j > 0 ; j--){
//             cout << "*";
//         }
    
//         cout << endl;
        
//     }
//     return 0; 
// }