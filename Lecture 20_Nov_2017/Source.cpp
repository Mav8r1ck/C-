#include "Header.h"
void Rectangle::Print()
	{
		for (int j = 0; j < _y; j++)
		{
			for (int i = 0; i < _x; i++)
			{
				std::cout << _s;
			}
			std::cout << std::endl;
		}
	}

Rectangle::Rectangle(int x, int y, char s){
	_x = x;
	_y = y;
	_s = s;
	Rectangle::Print();
}

int main()
{
	std::cout << "Enter Xside" << std::endl;
	int x;
	std::cin >> x;
	std::cout << "Enter Yside" << std::endl;
	int y;
	std::cin >> y;
	std::cout << "Enter Symbol" << std::endl;
	char s;
	std::cin >> s;
	Rectangle R(x, y, s);
	system ("pause");
	return 0;
}