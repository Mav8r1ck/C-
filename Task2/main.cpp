#include <iostream>
#include "Man.h"
#include <cstring>


Man::Man(const char* FIO){
    if(FIO){
        _FIO = new char[strlen(FIO)+1];
        strcpy(_FIO, FIO);
    }
};

Man::Man(const Man& objMan){
    _FIO = new char[strlen(objMan._FIO)+1];
    strcpy(_FIO, objMan._FIO ? objMan._FIO : "");
};

Man::~Man(){
    delete[] _FIO;
};

char* Man::GetMen() const{
    return _FIO;
};

Flat::Flat(Man* dweller){
    _dwellers = dweller;
    _counter++;
};

Flat::Flat(const Flat& obj_dweller)
{
    _dwellers = new Man[obj_dweller._counter];
    _counter = obj_dweller._counter;
    for(int i = 0; i < _counter; i++)
    {
        _dwellers = new Man(obj_dweller._dwellers[i].GetMen());
        _dwellers++;
    }
};

int main() {
    Man boy("Ivanov Ivan Ivanovich");
    std::cout << boy.GetMen() << std::endl;
    return 0;
}

