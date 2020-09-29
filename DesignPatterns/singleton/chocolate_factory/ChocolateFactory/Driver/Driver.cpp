#include <iostream>
#include "../Boiler/Boiler.h"
#include <assert.h>
#include <string>
#include <thread>

template<typename T>
void print(T t)
{
	std::cout << t << std::endl;
}

void createSingleton(const std::string rId)
{
	ChocolateBoilerPtr vBoiler = ChocolateBoiler::getInstance(rId);
	print(vBoiler->mId);
}

int main()
{
	int count = 0;
	while (count < 10)
	{
		std::thread vThread1(createSingleton, "bob");
		std::thread vThread2(createSingleton, "fred");
		vThread1.join();
		vThread2.join();
		++count;
	}
	
	
}

