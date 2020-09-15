#include <iostream>
#include "../SimpleFactory/SimpleFactory.h"
#include <stdexcept>
#include <string>

int main()
{
	try
	{
		PizzaStore::orderPizza("cheese");
	}
	catch (std::exception& rE)
	{
		std::cout << rE.what() << std::endl;
	}
}

