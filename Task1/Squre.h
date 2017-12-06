#pragma once
#include <cstdint>
#include <iostream>

class Square{
public:
    Square()= default;
    ~Square()= default;
    Square(Square* sqr);
    Square(double a);
    Square(double a, double b);
    Square(double a, double b, double c);
/*
    SquareTriangleGeron(int64_t a, int64_t b, int64_t c);
    SquareTriangleHeight(int64_t a, int64_t b);
    SquareRectangle(int64_t a, int64_t b);

    SquareQuadrate(int64_t a);
    SquareRhombus(int64_t a, int64_t b);
*/
    double GetSquare() const;


private:
    double _square;
};

enum commands{
    Exit = 0,
    TriangleG,
    TriangleH,
    Rectangle,
    Quadrate,
    Rhombus
};