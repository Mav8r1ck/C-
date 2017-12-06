#pragma once


class Man{
public:
    Man() = default;
    Man(const char* FIO);
    Man(const Man& objMan);
    ~Man();
    char* GetMen() const;

private:
    char* _FIO = nullptr;
};

class Flat{
public:
    Flat() = default;
    Flat(Man* dweller);
    Flat(const Flat& obj_dweller);
    ~Flat();
    Man* add_dweller(const Man* dweller);
    Man* delete_dweller();
    Man* operator[](int number);

private:
    Man* _dwellers = nullptr;
    int _counter = 0;
};