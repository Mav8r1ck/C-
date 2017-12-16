#pragma once
#include <cstring>

template<typename T>
class Array{
public:
    Array() = default;
    Array(size_t size, size_t grow);
    ~Array();
    size_t GetSize();
    void SetSize(size_t size, size_t grow);
    void Add(T item);
    size_t GetUpperBound();
    bool IsEmpty();
    void FreeExtra();
    void RemoveAll();
    void operator= (Array<T> obj);
    T operator[] (size_t array_index);
    void SetAt(size_t array_index, T value);
    T* GetData();

private:
    size_t _size = 0;
    size_t _grow = 1;
    size_t _counter = 0;
    T* _array = nullptr;
    void Memory_copy();
};

template<typename T>
Array<T>::Array(size_t size, size_t grow) {
    _grow = grow;
    _size = size;
    _array = new T [size];
}

template<typename T>
Array<T>::~Array() {
    delete[] _array;
}

template<typename T>
size_t Array<T>::GetSize() {
    return _size;
}

template<typename T>
void Array<T>::Add(T item) {
    if(_counter < _size){
        _array[_counter++] = item;
    }
    else{
        Memory_copy();
        _array[_counter++] = item;
    }
}

template<typename T>
void Array<T>::Memory_copy() {
    T* temp_array = new T [_size + _grow];
    memcpy(temp_array, _array, sizeof(T)*(_size + _grow));
    delete[] _array;
    _array = temp_array;
    _size += _grow;
}

template<typename T>
void Array<T>::SetSize(size_t size, size_t grow) {
    if (size >_size) {
        _grow = grow;
        Memory_copy();
    }
    else{
        _size = size;
        _grow = 0;
        Memory_copy();
        _grow = grow;
        if(_counter > _size)
        _counter = _size;
    }
}

template<typename T>
size_t Array<T>::GetUpperBound() {
    return (_counter-1);
}

template<typename T>
bool Array<T>::IsEmpty() {
    if(_counter == 0) {
        return true;
    }
    return false;
}

template<typename T>
void Array<T>::FreeExtra() {
    size_t temp_grow = _grow;
    _grow = 0;
    _size = _counter;
    Memory_copy();
    _grow = temp_grow;
}

template<typename T>
void Array<T>::RemoveAll() {
    delete[] _array;
    _size = 1;
    _grow = 1;
    _counter = 0;
    _array = new T [_size];
}

template<typename T>
T Array<T>::operator[](size_t array_index) {
    if(array_index < _counter) {
        return _array[array_index];
    }
    else{
        return (_counter-1);
    }
}

template<typename T>
void Array<T>::SetAt(size_t array_index, T value) {
    if(array_index < _counter) {
        _array[array_index] = value;
    }
    else{
        std::cout<<"Last index is: "<<(_counter-1)<< std::endl;
        ;
    }
}

template<typename T>
T* Array<T>::GetData() {
    return _array;
}

template<typename T>
void Array<T>::operator= (Array<T> obj) {
    _array = new T [obj._size];
    memcpy(_array, obj._array, sizeof(T)*(obj._size));
    _counter = obj._counter;
    _size = obj._size;
    _grow = obj._grow;
}




