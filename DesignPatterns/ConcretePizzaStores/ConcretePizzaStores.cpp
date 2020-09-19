#include "pch.h"
#include "ConcretePizzaStores.h"

NYPizzaStore::NYPizzaStore()
{
	mStoreTypeName = "NYPizzaStore";
}

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

ChicagoPizzaStore::ChicagoPizzaStore()
{
	mStoreTypeName = "ChicagoPizzaStore";
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

MixedPizzaStore::MixedPizzaStore()
{
	mStoreTypeName = "MixedPizzaStore";
}

std::shared_ptr<IPizza> MixedPizzaStore::createPizza(std::string rPizzaType)
{
	auto vPizza = std::make_shared<IPizza>(rPizzaType);

	if (rPizzaType == "NY_cheese")
	{
		vPizza = std::shared_ptr<IPizza>(new NYCheesePizza(rPizzaType));
	}
	else if (rPizzaType == "Chicago_cheese")
	{
		vPizza = std::shared_ptr<IPizza>(new ChicagoCheesePizza(rPizzaType));
	}
	else
	{
		throw std::runtime_error("pizza type not yet supported");
	}

	return vPizza;

}
