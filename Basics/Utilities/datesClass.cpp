#include "datesClass.h"

Date getDate(); 

int main() {
    Date testDate; 
    testDate = getDate();
    cout << endl; 
    cout << "Numeric: ";
    testDate.printNumeric();
    cout << endl;
    cout << "Alpha: ";
    testDate.printAlpha();
    cout << endl;

    return 0;
}

Date getDate(){
    int choice; 
    unsigned monthNumber, day, year;
    string monthName;

    cout << "Which Date construcor? (Enter 1, 2, or 3)" << endl
    << "1 - Month Number" << endl
    << "2 - Month Name" << endl
    << "3 - Default " << endl; 
    cin >> choice; 
    cout << endl;

    if(choice == 1){
        cout << "month number? ";
        cin >> monthNumber;
        cout << endl;
        cout << "day? ";
        cin >> day; 
        cout << endl;
        cout << "year? ";
        cin >> year; 
        cout << endl; 
        return Date(monthNumber, day, year);
    } else if(choice == 2){
        cout << "month name? ";
        cin >> monthName;
        cout << endl;
        cout << "day? ";
        cin >> day; 
        cout << endl;
        cout << "year? ";
        cin >> year; 
        cout << endl; 
        return Date(monthName, day, year);
    } else{
        return Date();
    }
}