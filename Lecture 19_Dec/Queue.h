#pragma once
#include <iostream>

template<typename T>
class Queue{
public:
    Queue() = default;
    Queue(std::initializer_list<T> const& data);
    ~Queue();
    Queue(Queue<T> const& obj);
    size_t Count() const;
    void PushItem(T const& data);
    void PushItem(T const&& data);
    T PopItem();
    Queue<T>& operator=(Queue<T> const& obj);
    Queue<T>& operator+(const Queue<T>& obj);
    T& operator[](size_t index);
    T& operator[](size_t index) const;
    void Insert(size_t index, T&& data);
    T Remove(size_t index);
private:
    struct QueueItem{
        T data;
        QueueItem* next = nullptr;
    };
    QueueItem* _head = nullptr;
    QueueItem* _tail = nullptr;
};

template<typename T>
void Queue<T>::PushItem(const T &data) {
    QueueItem* item = new QueueItem;
    item->data = data;
    item->next = nullptr;
    if(_tail != nullptr){
        _tail->next = item;
    }
    else{
        _head = item;
    }
    _tail = item;
}

template<typename T>
Queue<T>::Queue(std::initializer_list<T> const& data) {
    for(auto item : data){
        PushItem(item);
    }
}

template<typename T>
Queue<T>::~Queue() {
    while(_head != nullptr){
        QueueItem* item = _head;
        _head = item->next;
        delete item;
    }
}

template<typename T>
Queue<T>::Queue(Queue<T> const& obj) {
    QueueItem* item = obj._head;
    while(item != nullptr){
        PushItem(item->data);
        item = item->next;
    }

}

template<typename T>
size_t Queue<T>::Count() const {
    size_t count = 0;
    QueueItem* temp = _head;
    while(temp != nullptr){
        temp = temp->next;
        count++;
    }
    return count;
}

template<typename T>
void Queue<T>::PushItem(const T &&data) {
    QueueItem* item = new QueueItem;
    item->data = std::move(data);
    item->next = nullptr;
    if(_tail != nullptr){
        _tail->next = item;
    }
    else{
        _head = item;
    }
    _tail = item;
}

template<typename T>
T Queue<T>::PopItem() {
    if(_head!=nullptr) {
        T data = std::move(_head->data);
        QueueItem *temp = _head;
        _head = _head->next;
        delete temp;
        return std::move(data);
    }
    return T();
}

template<typename T>
Queue<T>& Queue<T>::operator=(Queue<T> const& obj) {
    while(_head != nullptr){
        QueueItem* item = _head;
        _head = item->next;
        delete item;
    }
    _tail = nullptr;
    QueueItem* temp = obj._head;

    while(temp) {
        PushItem(temp->data);
        temp = temp->next;
    }
    return *this;
}

template<typename T>
Queue<T> &Queue<T>::operator+(const Queue<T> &obj) {
    QueueItem* temp = obj._head;
    while(temp) {
        PushItem(temp->data);
        temp = temp->next;
    }
    return *this;

}

template<typename T>
T &Queue<T>::operator[](size_t index) {
    QueueItem* temp = _head;
    for(size_t i = 1; i<=Count(); i++){
        if(i == index){
            return temp->data;
            break;
        }
        temp=temp->next;
    }
}

template<typename T>
T &Queue<T>::operator[](size_t index) const {
    QueueItem* temp = _head;
    for(size_t i = 1; i<=Count(); i++){
        if(i == index){
            return temp->data;
            break;
        }
        temp=temp->next;
    }
}

template<typename T>
void Queue<T>::Insert(size_t index, T &&data) {
    QueueItem* temp = _head;
    QueueItem* item = new QueueItem;
    item->data=std::move(data);
    if(index == 1){
        item->next = temp;
        _head = item;
    }
    else{
        for(size_t i = 1; i < index-1; i++){
            temp = temp->next;
        }
        item->next = temp->next;
        temp->next = item;
    }
}

template<typename T>
T Queue<T>::Remove(size_t index) {
    QueueItem* temp = _head;
    if(index == 1){
        _head = temp->next;
        delete temp;
    }
    else{
        for(size_t i = 1; i < index-1; i++){
            temp = temp->next;
        }
        QueueItem* delete_item = temp->next;
        if(index == Count()){
            temp->next = nullptr;
            _tail = temp;
            delete delete_item;
        }
        else {
            temp->next = temp->next->next;
            delete delete_item;
        }
    }
}


