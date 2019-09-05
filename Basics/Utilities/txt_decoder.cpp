#include <iostream> 
using namespace std;

int main() {
    string text; 

    cout << "Enter text abbreviation: "; 
    cin >> text; 

    cout <<  text << " means: "; 

    if(text == "LOL" || text == "lol") {
        cout << "laughing out loud" << endl;
    }
}

//use string find, replace to get the 

// #include <iostream>
// #include <cmath>
// using namespace std;

// int main() {
//    string input;
//    string expanded; 
   
//    cout << "Enter text: " << endl; 
//    getline(cin, input); 
   
//    cout << "You entered: " <<  input << endl; 
//    int i = 0; 
//    while (input[i]) {
      
//       if (input.find("BFF") != string::npos) {
//          input.replace(input.find("BFF"), 3, "best friend forever");
//       }
   
//       if (input.find("IDK") != string::npos) {
//          input.replace(input.find("IDK"), 3, "I don't know");
//       }
      
//       if (input.find("JK") != string::npos) {
//          input.replace(input.find("JK"), 2, "just kidding");
//       }
      
//       if (input.find("TMI") != string::npos) {
//          input.replace(input.find("TMI"), 3, "too much information");
//       }
      
//       if (input.find("TTYL") != string::npos) {
//          input.replace(input.find("TTYL"), 4, "talk to you later");      
//       }
      
//       i++; 
//    }
   
   
//      cout << "Expanded: " << input << endl;
     
//    return 0;
// }