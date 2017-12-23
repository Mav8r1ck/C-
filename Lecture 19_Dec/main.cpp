#include <iostream>
#include "Stack.h"

void teststack(){
    Stack<int> S1;
    Stack<int> S3 = {4, 5, 6};
    Stack<int> S2 = {1, 2, 3};
    S1=S2;
    std::cout<<S1.Count()<<std::endl;
    S1=S2+S3;
    std::cout<<S1.Count()<<std::endl;
    std::cout<<S1[2]<<std::endl;
    S1.Insert(2, 111);
    std::cout<<"Size S1 after insert is: "<<S1.Count()<<std::endl;
    std::cout<<S1[2]<<std::endl;
    std::cout<<S1.Remove(2)<<std::endl;
    std::cout<<"Size S1 after remove is: "<<S1.Count()<<std::endl;
    std::cout<<S1.PopItem()<<std::endl;
    std::cout<<S1.Count()<<std::endl;
    std::cout<<S1[2]<<std::endl;
};

int main() {
    teststack();
    return 0;
}