#include <iostream>
#include "Header.h"

int main() {
    Array <int> A(5,5);
    A.Add(1);
    A.Add(11);
    A.Add(111);
    A.SetAt(2, 5);
    Array<int> A1;
    std::cout<< A[2] <<std::endl;
    std::cout<< A.GetData() <<std::endl;
    std::cout<< A.GetSize()<<std::endl;
    std::cout<< A.GetUpperBound()<<std::endl;
    A.FreeExtra();
    A.SetSize(1, 1);
    std::cout<< A.GetUpperBound()<<std::endl;
    A1=A;
    std::cout<< A1[0] <<std::endl;
    Array<char> S(5, 5);
    S.Add('a');
    S.Add('b');
    Array<char> S1;
    S1=S;
    std::cout<< S1[1] <<std::endl;
    return 0;
}