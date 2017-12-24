#include <iostream>
#include "Stack.h"
#include "Queue.h"


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

void testqueue(){
    Queue<int> Q3;
    Queue<int> Q1={1, 2, 3};
    std::cout<<Q1.Count()<<std::endl;
    Queue<int> Q2={4, 5, 6};
    Q3=Q2;
    std::cout<<Q3.Count()<<std::endl;
    Q3=Q1+Q2;
    std::cout<<Q3.Count()<<std::endl;
    std::cout<<Q3[1]<<std::endl;
    Q3.Insert(3, 222);
    std::cout<<Q3[1]<<std::endl;
    std::cout<<Q3[2]<<std::endl;
    std::cout<<Q3[3]<<std::endl;
    std::cout<<"This data removed: "<<Q3.Remove(7)<<std::endl;
    std::cout<<Q3[6]<<std::endl;
    std::cout<<Q3.Count()<<std::endl;
}

int main() {
    teststack();
    testqueue();
    return 0;
}