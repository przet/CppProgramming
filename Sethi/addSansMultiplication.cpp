#include <iostream>
#include <string>

int main (){
	
	int count = 0;
	int m = 0, n = 0;
	std::cout << "\n Please input two integers \n";
	std::cin >> m;
	std::cin >> n;
	
	int sum = 0;
	
	for (int i = 0; i < n; ++i)
	{
		count = i;	
		sum += m;
		
	}
	
	std::cout << "multiplication via summation is " << sum;
	
	return 0;
	
	
	
	
	}
