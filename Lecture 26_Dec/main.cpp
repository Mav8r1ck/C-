#include <iostream>
#include "AClass.h"

President::President(int64_t data) {
    _salary = data;
}

void President::print() {
    std::cout<<"President's salary is: "<<_salary<<std::endl;
}

Manager::Manager(int64_t data) {
    _salary = data;
}

void Manager::print() {
    std::cout<<"Manager's salary is: "<<_salary<<std::endl;
}

Worker::Worker(int64_t data) {
    _salary = data;
}

void Worker::print() {
    std::cout<<"Workers's salary is: "<<_salary<<std::endl;
}



int main() {
    President P(2000);
    Manager M(1500);
    Worker W(1000);
    P.print();
    M.print();
    W.print();
    return 0;
}



