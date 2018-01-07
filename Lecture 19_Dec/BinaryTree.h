#pragma once
#include <iostream>
#include <exception>

class NullptrException : public std::exception{
public:
    NullptrException(char const* message);
    const char* what() const override;
private:
    const char* _message;
};



class NotFindException : public std::exception{
public:
    NotFindException(char const* message);
    const char* what() const override;
private:
    const char* _message;
};


template<typename Key, typename Value>
class BTree{
private:
    struct TreeItem{
        Key _key;
        Value _value;
        TreeItem* _left = nullptr;
        TreeItem* _right = nullptr;
    };
    TreeItem* _root = nullptr;
    void RemoveTree(TreeItem* data);

public:
    BTree() = default;
    BTree(Key const& key, Value const& value);
    void PushData(Key const& key, Value const& value);
    Value Find(Key &key);
    void EditValue(Key &key, Value&& new_value);
    void RemoveElement(Key &key);

    ~BTree();
};

template<typename Key, typename Value>
BTree<Key, Value>::BTree(Key const& key, Value const& value) {
    PushData(key, value);
}

template<typename Key, typename Value>
void BTree<Key, Value>::PushData(Key const& key, Value const& value) {
    TreeItem* item = new TreeItem;
    item->_key = key;
    item->_value = value;

    if(_root == nullptr){
        _root = item;
        return;
    }

    TreeItem* temp = _root;
    while (true){
        if (temp->_key == key){
            temp->_value = value;
            break;
        }
        else if(key < temp->_key){
            if (temp->_left == nullptr) {
                temp->_left = item;
                return;
            }
            temp = temp->_left;
        }
        else{
            if(key > temp->_key){
                temp->_right = item;
                return;
            }
            temp = temp->_right;
        }
    }
}

template<typename Key, typename Value>
Value BTree<Key, Value>::Find(Key &key) {

    if (_root == nullptr) {
        throw NullptrException("Root is nullptr");
    }
    TreeItem* temp = _root;

    while (true){
        if (temp->_key == key){
            return temp->_value;
        }
        else if(key < temp->_key){
            temp = temp->_left;
            if(temp == nullptr){
                break;
            }
        }
        else{
            temp = temp->_right;
            if(temp == nullptr){
                break;
            }
        }
    }
    throw NotFindException("Item not found in try");
}

template<typename Key, typename Value>
void BTree<Key, Value>::RemoveElement(Key &key) {


    TreeItem* temp = _root;

    if (temp == nullptr) {
        throw NullptrException("Root is nullptr");
    }

    TreeItem* previous = nullptr;

    while (true){
        if (temp->_key == key){
            previous->_left = temp->_left;
            previous->_right = temp->_right;
            delete temp;
            break;
        }
        else if(key < temp->_key){
            temp = temp->_left;
            previous = temp;
            if(temp == nullptr){
                break;
            }
        }
        else{
            temp = temp->_right;
            previous = temp;
            if(temp == nullptr){
                break;
            }
        }
    }
}

template<typename Key, typename Value>
void BTree<Key, Value>::RemoveTree(TreeItem* data) {
    TreeItem* temp = data;
    if(temp->_left != nullptr){
        RemoveTree(temp->_left);
    }
    if(temp->_left != nullptr){
        RemoveTree(temp->_right);
    }
    delete temp;
}

template<typename Key, typename Value>
BTree<Key, Value>::~BTree() {
    RemoveTree(_root);
    _root = nullptr;
}

template<typename Key, typename Value>
void BTree<Key, Value>::EditValue(Key &key, Value&& new_value) {

    TreeItem* temp = _root;

    if (temp == nullptr) {
        throw NullptrException("Root is nullptr");
    }

    while (true){
        if (temp->_key == key){
            temp->_value = std::move(new_value);
        }
        else if(key < temp->_key){
            temp = temp->_left;
            if(temp == nullptr){
                break;
            }
        }
        else{
            temp = temp->_right;
            if(temp == nullptr){
                break;
            }
        }
    }

    throw NotFindException("Item not found in try");
}




