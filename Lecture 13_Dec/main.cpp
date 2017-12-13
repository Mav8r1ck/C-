#include <iostream>
#include "Circle.h"

std::ostream& operator<<(std::ostream& stream, Circle& obj1){
    stream << "Radius: "<< obj1._Radius;
    return stream;
}


int main() {

    Circle r1(10);
    Circle r2(15);
    std::cout<< r1 << std::endl << r2 << std::endl;

    return 0;
}