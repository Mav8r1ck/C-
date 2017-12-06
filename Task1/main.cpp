#include <iostream>
#include "Squre.h"
#include <math.h>

Square::Square(Square* sqr){
    _square = (*sqr).GetSquare()/2.0;
};
Square::Square(double a):
    _square(a*a){
};
;
Square::Square(double a, double b):
    _square(a*b){
};
Square::Square(double a, double b, double c)
{
    double p = (a+b+c)/2.0;
    _square = sqrt(p*(p-a)*(p-b)*(p-c));
};
double Square::GetSquare() const
{
    return _square;
};

int main() {
    int commands=0;
    std::cout<<"Enter parameter"<<std::endl;
    std::cin>>commands;
    switch(commands){
        case TriangleG:
        {

            break;
        }
        case TriangleH:
        {
//            Square temp(2, 3);
            Square temp2(new Square(2,3));
            std::cout<<temp2.GetSquare()<<std::endl;
            break;
        }
        case Rectangle:
        {
            break;
        }
        case Quadrate:
        {
            break;
        }
        case Rhombus:
        {
            break;
        }
        default:
        {
            std::cout<<"Invalid parameter!!!"<<std::endl;
        }
    }
    return 0;
}