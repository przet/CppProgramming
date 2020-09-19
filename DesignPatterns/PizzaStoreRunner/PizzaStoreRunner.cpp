#include <iostream>
#include <stdexcept>
#include <string>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <memory>
#include "../PizzaStoreInterface/PizzaStoreInterface.h"
#include "../ConcretePizzaStores/ConcretePizzaStores.h"
#include <type_traits>

namespace
{
	std::shared_ptr<IPizzaStore> pizzaStore(std::string rPizzaStore)
	{
		if (rPizzaStore == "CHI")
		{
			std::cout << "We are in the Chicago store " << std::endl;
			return std::shared_ptr<IPizzaStore>(new ChicagoPizzaStore);
		}
		else if (rPizzaStore == "NY")
		{
			std::cout << "We are in the NY store " << std::endl;
			return std::shared_ptr<IPizzaStore>(new NYPizzaStore);
		}
		else
		{
			throw std::runtime_error("No pizza store in city with abbreviation " + rPizzaStore);
		}
	}
}

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cout << "Supply (at least) pizza store name" << std::endl;
		return -1;
	}

	if (argc > 3)
	{
		std::cout << "Supply (at most) pizza store name and type of pizza" << std::endl;
		return -1;
	}

	char* vCLArgPtr = argv[1];
	std::string vCLArgStr;
	while (*vCLArgPtr != '\0')
	{
		vCLArgStr += *(vCLArgPtr++);
	}

	// Allowable input strings 
	std::vector<std::pair<std::string, std::vector<std::string>>> vStringVec
	{
		{"CHI", {"chicago", "CHICAGO", "Chicago", "Chicargo", "chicargo", "CHICARGO", "CHI"}},
		{"NY", {"NY", "ny", "NEWYORK", "NEW YORK", "new york", "New York", "New Yorke", "NEW YORKE"} }
	};

	// Go through the string vec key by key. If we have a match for that key,
	// create the require pizza store, else continue, and if not match at all, return runtime error

	std::shared_ptr<IPizzaStore> vPizzaStore = nullptr;

	std::for_each(std::begin(vStringVec), std::end(vStringVec),
		[&](auto rElem)
		{
			if (std::find_if(std::begin(rElem.second), std::end(rElem.second),
				[&](auto rElem2) {return rElem2 == vCLArgStr; }) != std::end(rElem.second))
			{
				vPizzaStore = pizzaStore(rElem.first);
			}
		});
	if (!vPizzaStore)
	{
		std::cout << vCLArgStr << " not a current pizza store location!" << std::endl;
		return -1;
	}

	
	try
	{
        vPizzaStore->orderPizza("cheese");
	}
	catch (std::exception& rE)
	{
		std::cout << rE.what() << std::endl;
	}
}

