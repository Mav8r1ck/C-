#pragma once

class Circle{
public:

    Circle() = default;

    explicit Circle(int x){
        _Radius = x;
    }

    bool operator==(const Circle& obj1){
        if(obj1._Radius==_Radius){
            return true;
            }
        return false;
    }

    bool operator>(const Circle& obj1){
        if(_Radius>obj1._Radius) {
            return true;
        }
        return false;
    }

    Circle operator+=(Circle& obj1){

        return Circle(_Radius = _Radius + obj1._Radius);
    }

    Circle operator=( const Circle& obj1){
        if(&obj1 == this) {
            return *this;
        }
        return Circle(this -> _Radius = obj1._Radius);
    }


private:
    friend std::ostream& operator<<(std::ostream& stream, Circle& obj1);
    int _Radius = 0;
};
