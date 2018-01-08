#pragma once

#include <iostream>

class Employer{
public:
    virtual void print() = 0;
};

class President : public Employer{
public:
    explicit President(int64_t data);
    void print () override ;
private:
    int64_t _salary = 0;
};

class Manager : public Employer{
public:
    explicit Manager(int64_t data);
    void print () override ;
private:
    int64_t _salary = 0;
};

class Worker : public Employer{
public:
    explicit Worker(int64_t data);
    void print () override ;
private:
    int64_t _salary = 0;
};


