#include <iostream> 
#include <string>
using namespace std; 

// string operations: c_str, copy, find, substr, compare			

int main(){

    string myString = "255.255.254.0";
    string testString;

    //how to iterate and output through a string, c++11

    cout << "Iterate thru and output string: ";
    for(auto it = myString.begin(); it != myString.end(); it++) cout << *it; 
    cout << endl; 

    //how to iterate and output through a string in reverse, c++ 11
    cout << "Iterate thru and output string in reverse: ";
    for(auto it = myString.rbegin(); it != myString.rend(); it++) cout << *it; 
    cout << endl;

    //capacity of string
    cout << "Size of string is: " << myString.length() << endl;  //size or length, same thing

    cout << "Resizing string..." << endl; 
    myString.resize(25);
    cout << "Size of string is now " << myString.size() << " and contains: " << myString << endl;

    if(!myString.empty()){
        myString.clear();
        cout << "String has been cleared: ";
        cout << myString << endl;
    }

    myString.push_back('8'); //pushback appends to back (duh)
    cout << myString << endl;

    myString.append(" this is me appending text to the string ");
    cout << myString << endl;

    myString.push_back('7');
    cout << myString << endl;

    myString.insert(4,4, '.'); //parameters: position (inserts right before that pos), amt of char, char to inserts
    cout << myString << endl;

    myString = "1.255.1.0";


    int dotsCnt = 0;

    for(int i  = 0; i < myString.size(); i++){
        if(myString.at(i) == '.'){
            myString.replace(i,1,"[.]"); //position, amount of places to replace, string to replace with
            dotsCnt++;
            if(dotsCnt == 3) break;
            i+=2;
        }
    }
    cout << myString << endl;

    myString.erase(0,4);
    cout << myString << endl;

    testString.push_back(myString.front());
    testString.push_back(myString.back());
    testString.pop_back();
    cout << testString << endl;


    testString.swap(myString);
    cout << myString << endl;
    cout << testString << endl;


    //c_str, copy, find, substr, compare	
    string palindrome = "tacocaT";
    bool isPalindrome = false;

    for(int i = 0; i < palindrome.size()/2; i++){
        if(palindrome.at(i) == palindrome.at(palindrome.size()-i-1)){
            isPalindrome = true;
        }
        else {
            isPalindrome = false;
        }
    }

    if(isPalindrome == true)  cout << "is palindrome" << endl;
    return 0;
}