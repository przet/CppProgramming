#include "pch.h"
#include "ConcretePizzaStores.h"

std::shared_ptr<IPizza> NYPizzaStore::createPizza(std::string rPizzaType)
{
	auto vPizza = std::make_shared<IPizza>(rPizzaType);

	if (rPizzaType == "cheese")
	{
		vPizza = std::shared_ptr<IPizza>(new NYCheesePizza(rPizzaType));
	}
	else
	{
		throw std::runtime_error("pizza type not yet supported");
	}

	return vPizza;

}

std::shared_ptr<IPizza> ChicagoPizzaStore::createPizza(std::string rPizzaType)
{
	auto vPizza = std::make_shared<IPizza>(rPizzaType);

	if (rPizzaType == "cheese")
	{
		vPizza = std::shared_ptr<IPizza>(new ChicagoCheesePizza(rPizzaType));
	}
	else
	{
		throw std::runtime_error("pizza type not yet supported");
	}

	return vPizza;

}
