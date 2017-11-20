#pragma once
#include<iostream>
#include <string>
#include <cstdint>

class Rectangle{
public:

	Rectangle(int x, int y, char s);
	void Print();
	
private:
	int _x;
	int _y;
	char _s;
};