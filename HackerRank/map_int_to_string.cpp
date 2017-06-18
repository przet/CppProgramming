#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>


int main() {
	int n = 0;
	std::cin >> n;
	typedef std::map <int, std::string> Map;
	Map m;
	m[1] = "one";
	m[2] = "two";
	m[3] = "three";
	m[4] = "four";
	m[5] = "five";
	m[6] = "six";
	m[7] = "seven";
	m[8] = "eight";
	m[9] = "nine";
	if (n<1 | n>pow(10, 9))
		return 1;
	if (n >= 1 | n <= 9)
	{
		switch (n)
		{
		case 1:
			std::cout << m.at(1) << std::endl;
			break;
		case 2:
			std::cout << m.at(2)<< std::endl;
			break;
		case 3:
			std::cout << m.at(3)<< std::endl;
			break;
		case 4:
			std::cout << m.at(3)<< std::endl;
			break;
		case 5:
			std::cout << m.at(3)<< std::endl;
			break;
		case 6:
			std::cout << m.at(3)<< std::endl;
			break;
		case 7:
			std::cout << m.at(3)<< std::endl;
			break;
		case 8:			
			std::cout << m.at(3)<< std::endl;
			break;
		case 9:
			std::cout << m.at(3)<< std::endl;
			break;

		default:
			break;
		}
	}
	if (n > 9)
		std::cout << n << "is greater than 9" << std::endl;


		return 0;
}