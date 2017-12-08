#pragma once


class Man{
public:
    Man() = default;
    explicit Man(const char* FIO);
    Man(const Man& objMan);
    ~Man();
    char* GetMen() const;

private:
    char* _FIO = nullptr;
};



class Flat{
public:
    Flat() = default;
    explicit Flat(Man dweller);
//    Flat(const Flat& obj_dweller);
    ~Flat();
    void add_dweller(Man dweller);
//    Man* delete_dweller();
//    Man* operator[](int number);

private:
    Man* _dwellers = nullptr;
    int _counter = 0;
    int _flat_number = 0;
};



class House{
public:
    House() = default;
//    House(const House& obj_house);
    explicit House(Flat obj);
    ~House();
    void add_flats(Flat obj);

private:
    Flat* _flats = nullptr;
    int _counter = 0;

};
