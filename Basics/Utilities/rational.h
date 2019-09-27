#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
using namespace std;

class Rational {
    private: 
        int numerator;
        int denominator; 

    public: 
        Rational(); //default constructor 
        Rational(int); //for numerator
        Rational(int, int); //for numerator and denominator
        const Rational add(const Rational&) const;
        const Rational subtract(const Rational &) const;
        const Rational multiply(const Rational &) const;
        const Rational divide(const Rational &) const;
        void display() const;
};

Rational::Rational() : numerator(0), denominator(1){
    return;
}

Rational::Rational(int numerator) : numerator(numerator), denominator(1){
    return;
}

Rational::Rational(int numerator, int denominator) : numerator(numerator), denominator(denominator){
    return;
}

const Rational Rational::add(const Rational& rhs) const{
    //(a/b) + (c/d) = (ad+bc) / (b*d)
    int numer = numerator * rhs.denominator + denominator*rhs.numerator;
    int denom = denominator * rhs.denominator;
    return Rational(numer, denom);
}

const Rational Rational::subtract(const Rational& rhs) const{
    //(a/b) - (c/d) = (a*d - b*c) / (b*d)
    int numer = numerator * rhs.denominator - denominator * rhs.numerator;
    int denom = denominator * rhs.denominator;
    return Rational(numer, denom);
}

const Rational Rational::multiply(const Rational& rhs) const{
    //(a/b) * (c/d) = (a*c) / (b*d)
    int numer = numerator * rhs.numerator;
    int denom = denominator * rhs.denominator;
    return Rational(numer, denom);
}

const Rational Rational::divide(const Rational& rhs) const{
    //(a/b) / (c/d) = (a*d) / (c*b)
    int numer = numerator * rhs.denominator;
    int denom = rhs.numerator * denominator;
    return Rational(numer, denom);
}

void Rational::display() const{
    cout << numerator << " / " << denominator;

 }

#endif