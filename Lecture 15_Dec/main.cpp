#include <iostream>
#include "Header.h"

int main() {
    Array <int> A(5,5);
    A.Add(1);
    A.Add(11);
    A.Add(111);
    std::cout<< A.GetSize()<<std::endl;
    std::cout<< A.GetUpperBound()<<std::endl;
    A.FreeExtra();
    A.SetSize(1, 1);
    std::cout<< A.GetUpperBound()<<std::endl;
    return 0;
}