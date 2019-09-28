#ifndef DATES_CLASS_H
#define DATES_CLASS_H

#include <iostream>
#include<vector>
using namespace std;

class Date {

    private:
        unsigned month, day, year;
        string monthName;
        vector<string> monthList;

    public: 
        Date(); //creates the date January 1st, 2000
        Date(unsigned m, unsigned d, unsigned y);
        Date(const string &mn, unsigned d, unsigned y);
        void printNumeric() const;
        void printAlpha() const;
    
    private: //helper functions
        bool isLeap(unsigned y) const;
        unsigned daysPerMonth(unsigned m, unsigned y) const;
        void SetMonthNumber(const unsigned &m);
        void SetMonthName_Num(string m);
        void SetDay(const unsigned &d, const unsigned &m);
        void populateMonths(); //mutator to initialize months
};

Date::Date() : month(1), day(1), year(2000), monthName("January"){ return; }

Date::Date(unsigned m, unsigned d, unsigned y) : year(y) { 
    // given (3,1,2010) -> March 1st, 2010
    //if values out of range, fix to closest possible date (15, 32,2010) -> Dec 31st, 2010

    populateMonths();
    SetMonthNumber(m);
    SetDay(d,month-1);
    monthName = monthList.at(month-1);

    return; 
}

Date::Date(const string &mn, unsigned d, unsigned y) : year(y) {

    populateMonths();
    SetMonthName_Num(mn);
    SetDay(d,month-1);

    return; 
}

void Date::printNumeric() const{
    //format "3/1/2012"
    cout << month << "/" << day << "/" << year;
    return;
}

void Date::printAlpha() const{
    //format "March 1, 2012"
    cout << monthName << " " << day << ", " << year;
    return;
}

void Date::populateMonths () {
    monthList.push_back("January");
    monthList.push_back("February");
    monthList.push_back("March");
    monthList.push_back("April");
    monthList.push_back("May");
    monthList.push_back("June");
    monthList.push_back("July");
    monthList.push_back("August");
    monthList.push_back("September");
    monthList.push_back("October");
    monthList.push_back("November");
    monthList.push_back("December");
    return;
}

void Date::SetMonthName_Num(string userMonthName){
    userMonthName = userMonthName.substr(0,3);
    userMonthName.at(0) = (toupper(userMonthName.at(0)));

    for(unsigned i = 0; i < monthList.size(); i++){
        if(userMonthName == monthList.at(i).substr(0,3)){
            monthName = monthList.at(i); //assigns monthName from provided month
            month = i+1; // month number matches month name
            break;
        }
    }

    if(monthName == ""){ //if string argument invalid, set to default date.
        cout << "Invalid month name. Month set to default value." << endl;
        monthName = "January";
        day = 1;
        month = 1;
    }

    return;
}

void Date::SetDay(const unsigned &d, const unsigned &m){
    if(d > 31){ //if day is wrong, correct 
        cout << "Invalid day value. Day has been adjusted." << endl;
        day = daysPerMonth(m+1,year);

    } else if(d < 1){
        cout << "Invalid day value. Day has been adjusted" << endl;
        day = 1;
    } else{ //if no errors in day, set day to user value
        unsigned maxDays = daysPerMonth(m+1,year);
        if(d < maxDays) {
            day = d; 
        } else {
            cout << "Invalid day for current month. Correcting" << endl;
            day = maxDays;
        }
    }
    return;
}

void Date::SetMonthNumber(const unsigned &m){
    if(m > 12){
        cout << "Invalid month value. Month has been corrected." << endl;
        month = 12;

    } else if(m < 1){
        cout << "Invalid month value. Month has been corrected" << endl;
        month = 1;
    } else{
        month = m; 
    }
}

unsigned Date::daysPerMonth(unsigned m, unsigned y) const{
     if(m != 2){
        if(m == 9 || m == 4 || m == 6 || m == 11){ //Sep, April, June, Nov have 30 days
            return 30;
         }
        return 31; // rest of months have 31
     }
     //case for february
     if(isLeap(y) == true){
         return 29;
     }
     return 28;
 }

bool Date::isLeap(unsigned y) const{ //checks for leap years
    if(y % 4 == 0){
        if(year % 100 == 0){
            if(year % 400 == 0){ return true; }
            return false;
        }
        return true;
    }
    return false;
}

#endif 