//#include "Header.h"
#include<iostream>
#include <string>
#include <cstdint>
using namespace std;
/*
 * Реализуйте класс Дробь. Необходимо хранить числитель и знаменатель в качестве переменных-членов.
 * Реализуйте функции-члены для ввода данных в переменные-члены, для выполнения арифметических операций
 * (сложение, вычитание, умножение, деление, и т.д.).
 */
class Fraction{
private:
    int numerator;
    int denominator;
    int LCD(int x, int y)
    {
        if (y == 0) return x;
        return LCD(y, x % y);
    }
public:
    void Input(int c, int z)
    {
        numerator = c;
        denominator = z;
    }
    void Multiplication(int x)
    {
        numerator *= x;
        cout << "Fraction:  " << numerator << '/' << denominator << endl;
    }
    void Division(int x)
    {
        numerator *= x;
        cout << "Fraction: " << numerator << '/' << denominator << endl;
    }
    void Addition(int x)
    {
        numerator += (x*denominator);
        cout << "Fraction: " << numerator << '/' << denominator << endl;
    }
    void Subtraction(int x)
    {
        numerator -= (x*denominator);
        cout << "Fraction: " << numerator << '/' << denominator << endl;
    }
    void Print()
    {
        cout <<numerator<<"/"<<denominator<<endl;
    }
    int LCD()
    {
        return LCD(numerator, denominator);
    }
    void Edit(int x)
    {
        numerator /= x;
        denominator /= x;
    }
};

int main()
{
    Fraction one{};
    int n = 0;
    int d = 0;
    int m = 0;
    char c = 'y';
    cout << "Enter Numerator" << endl;
    cin >> n;
    cout << "Enter Denominator" << endl;
    cin >> d;
    one.Input(n, d);
    do {
        one.Edit(one.LCD());
        one.Print();
        cout << "Enter operation" << endl;
        cout << "Exit(0)" << endl;
        cout << "Addition(1)" << endl;
        cout << "Subtraction(2)" << endl;
        cout << "Multiplication(3)" << endl;
        cout << "Division(4)" << endl;
        cin >> m;
        switch (m)
        {
            case 1:
                cout << "Enter Number" << endl;
                cin >> n;
                one.Addition(n);
                break;
            case 2:
                cout << "Enter Number" << endl;
                cin >> n;
                one.Subtraction(n);
                break;
            case 3:
                cout << "Enter Number" << endl;
                cin >> n;
                one.Multiplication(n);
                break;
            case 4:
                cout << "Enter Number" << endl;
                cin >> n;
                one.Division(n);
                break;
            default:
                cout << "Repeat your choice" << endl;
        }
        cout << "Need more?(y/n)" << endl;
        cin >> c;
    }while(c != 'n');
    return 0;
}