#pragma once
#include<iostream>
#include <string>
#include <cstdint>
using namespace std;

class Fraction{
private:
    int64_t numerator;
    int64_t denominator;
    int64_t LCD(int64_t x, int64_t y)
    {
        if (y == 0) return x;
        return LCD(y, x % y);
    }
public:
    void Input(int64_t c, int64_t z);
    /*
    {
        numerator = c;
        denominator = z;
    }
     */
    void Multiplication(int64_t x);
    /*
    {
        numerator *= x;
        cout << "Fraction:  " << numerator << '/' << denominator << endl;
    }
     */
    void Division(int64_t x);
    /*
    {
        numerator *= x;
        cout << "Fraction: " << numerator << '/' << denominator << endl;
    }
     */
    void Addition(int64_t x);
    /*
    {
        numerator += (x*denominator);
        cout << "Fraction: " << numerator << '/' << denominator << endl;
    }
     */
    void Subtraction(int64_t x);
    /*
    {
        numerator -= (x*denominator);
        cout << "Fraction: " << numerator << '/' << denominator << endl;
    }
     */
    void Print();
    /*
    {
        cout <<numerator<<"/"<<denominator<<endl;
    }
     */
    int64_t LCD();
    /*
    {
        return LCD(numerator, denominator);
    }
     */
    void Edit(int64_t x);
    /*
    {
        numerator /= x;
        denominator /= x;
    }
     */
};