#include "Header.h"
#include<iostream>
#include <string>
#include <cstdint>
using namespace std;
/*
 * Реализуйте класс Дробь. Необходимо хранить числитель и знаменатель в качестве переменных-членов.
 * Реализуйте функции-члены для ввода данных в переменные-члены, для выполнения арифметических операций
 * (сложение, вычитание, умножение, деление, и т.д.).
 */
/*
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
 */
    void Fraction::Input(int64_t c, int64_t z)
    {
        numerator = c;
        denominator = z;
    }
    void Fraction::Multiplication(int64_t x)
    {
        numerator *= x;
        cout << "Fraction:  " << numerator << '/' << denominator << endl;
    }
    void Fraction::Division(int64_t x)
    {
        numerator *= x;
        cout << "Fraction: " << numerator << '/' << denominator << endl;
    }
    void Fraction::Addition(int64_t x)
    {
        numerator += (x*denominator);
        cout << "Fraction: " << numerator << '/' << denominator << endl;
    }
    void Fraction::Subtraction(int64_t x)
    {
        numerator -= (x*denominator);
        cout << "Fraction: " << numerator << '/' << denominator << endl;
    }
    void Fraction::Print()
    {
        cout <<numerator<<"/"<<denominator<<endl;
    }
    int64_t Fraction::LCD()
    {
        return LCD(numerator, denominator);
    }
    void Fraction::Edit(int64_t x)
    {
        numerator /= x;
        denominator /= x;
    }
/*
};
*/
int main()
{
    Fraction one{};
    int64_t n = 0;
    int64_t d = 0;
    int64_t m = 0;
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