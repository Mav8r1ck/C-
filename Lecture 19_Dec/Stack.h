#pragma once
#include <iostream>

template<typename T>
class Stack{
public:
    Stack() = default;
    Stack(std::initializer_list<T> const& data);
    ~Stack();
    Stack(const Stack<T> &obj);
    size_t Count() const;
    void PushItem(T const& data);
    void PushItem(T const&& data);
    T PopItem();
    Stack<T>& operator=(const Stack<T>& obj);
    Stack<T>& operator+(const Stack<T>& obj);
    T& operator[](size_t index);
    T& operator[](size_t index) const;
    void Insert(size_t index, T&& data);
    T Remove(size_t index);
private:
    struct StackItem{
        T data;
        StackItem* previous = nullptr;
    };
    StackItem* _head = nullptr;
    void Reverse(StackItem* item);
};

template<typename T>
void Stack<T>::PushItem(T const& data) {
    StackItem* item = new StackItem;
    item->data = data;
    item->previous = _head;
    _head = item;
}

template<typename T>
Stack<T>::Stack(std::initializer_list<T> const &data) {
    for (auto item : data){
        PushItem(item);
    }
}

template<typename T>
Stack<T>::~Stack() {
    while(_head != nullptr){
        StackItem* item = _head;
        _head = item->previous;
        delete item;
    }
}

template<typename T>
Stack<T>::Stack(const Stack<T> &obj) {
    Reverse(obj._head);
}

template<typename T>
void Stack<T>::Reverse(StackItem *item) {
    if(item->previous != nullptr){
        Reverse(item->previous);
    }
    PushItem(item->data);
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& obj) {
    while (_head) {
        StackItem* item = _head;
        _head = item->previous;
        delete item;
    }
    Reverse(obj._head);
    return *this;
}

template<typename T>
Stack<T>& Stack<T>::operator+(const Stack<T>& obj) {
    Reverse(obj._head);
    return *this;
}

template<typename T>
size_t Stack<T>::Count() const {
    size_t count = 0;
    StackItem* temp = _head;
    while(temp){
        temp = temp->previous;
        count++;
    }
    return count;
}

template<typename T>
T Stack<T>::PopItem() {
    if(_head) {
        T data = _head->data;
        StackItem *item = _head;
        _head = _head->previous;
        delete item;
        return data;
    }
    return T();
}

template<typename T>
void Stack<T>::PushItem(T const&& data) {
    StackItem* item = new StackItem;
    item->data = std::move(data);
    item->previous = _head;
    _head = item;
}


template<typename T>
T &Stack<T>::operator[](size_t index) {
    StackItem* item = _head;
    for(size_t i = Count(); i > 0; i--){
        item = item->previous;
        if(i == index+1){
            break;
        }
    }

    return item->data;
}

template<typename T>
void Stack<T>::Insert(size_t index, T&& data) {
    StackItem* item_temp = _head;
    for(size_t i = Count(); i > 0; i--){
        item_temp = item_temp->previous;
        if(i == index+1){
            break;
        }
    }
    StackItem* item = new StackItem;
    item->data = std::move(data);
    item->previous = item_temp->previous;
    item_temp->previous = item;

}

template<typename T>
T Stack<T>::Remove(size_t index) {
    StackItem* item_temp = _head;
    for(size_t i = Count(); i > 0; i--){
        item_temp = item_temp->previous;
        if(i == index+2){
            break;
        }
    }
    StackItem* delete_item = item_temp->previous;
    item_temp->previous = item_temp->previous->previous;
    T temp = delete_item->data;
    delete delete_item;
    return temp;
}

template<typename T>
T &Stack<T>::operator[](size_t index) const {
    StackItem* item = _head;
    for(size_t i = Count(); i > 0; i--){
        item = item->previous;
        if(i == index+1){
            break;
        }
    }
    return item->data;
}

