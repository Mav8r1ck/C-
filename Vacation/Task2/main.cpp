#include <iostream>
#include "Man.h"
#include <cstring>


Man::Man(const char* FIO){
    if(FIO){
        _FIO = new char[strlen(FIO)+1];
        strcpy(_FIO, FIO);
    }
}

Man::Man(const Man& objMan){
    _FIO = new char[strlen(objMan._FIO)+1];
    strcpy(_FIO, objMan._FIO ? objMan._FIO : "");
}

Man::~Man(){
    if(_FIO != nullptr)
    {
        delete[] _FIO;
    }
}

char* Man::GetMen() const{
    return _FIO;
};

Flat::Flat(Man dweller){
    _dwellers = new Man[1];
    _dwellers[0] = dweller;
    _counter++;
}

Flat::~Flat(){
    if(_dwellers!= nullptr) {
        delete[] _dwellers;
    }
}

void Flat::add_dweller(Man dweller)
{
    Man* temp = new Man[_counter+1];
    memcpy(temp, _dwellers, sizeof(Man)*_counter);
    /*
    for(int i = 0; i < _counter; i++){
        temp[i] = _dwellers[i];
    }
     */
    temp[_counter] = dweller;
    delete[] _dwellers;
    _dwellers = temp;
    _counter++;
}


House::House(Flat obj){
    _flats = new Flat[1];
    _flats[0] = obj;
    _counter++;
}

House::~House(){
    if(_flats!= nullptr) {
        delete[] _flats;
    }
}

void House::add_flats(Flat obj)
{
    Flat* temp = new Flat[_counter+1];
    memcpy(temp, _flats, sizeof(Flat)*_counter);
    /*
    for(int i = 0; i < _counter; i++){
        temp[i] = _dwellers[i];
    }
     */
    temp[_counter] = obj;
    delete[] _flats;
    _flats = temp;
    _counter++;
};

/*
Flat::Flat(const Flat& obj_dweller)
{
    _dwellers = new Man[obj_dweller._counter];
    _counter = obj_dweller._counter;
    for(int i = 0; i < _counter; i++)
    {
        _dwellers = new Man(obj_dweller._dwellers[i].GetMen());
        _dwellers++;
    }
}
 */

int main() {
    Man boy("Ivanov Ivan Ivanovich");
    std::cout << boy.GetMen() << std::endl;
    return 0;
}
