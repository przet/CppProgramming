#include "pch.h"
#include "ConcretePizzaStores.h"

NYPizzaStore::NYPizzaStore()
{
	mStoreTypeName = "NYPizzaStore";
}

std::shared_ptr<IPizza> NYPizzaStore::createPizza(std::string rPizzaType)
{
	std::shared_ptr<IPizza> vPizza = nullptr;
	IPizzaStore::mIngredientFactory = PizzaIngredientFactory(new NYPizzaIngredientFactory);

	if (rPizzaType == "cheese")
	{
		vPizza = std::shared_ptr<IPizza>(new CheesePizza(mIngredientFactory));
		vPizza->setName(this->mStoreTypeName + " style " + rPizzaType + "pizza");
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
	std::shared_ptr<IPizza> vPizza = nullptr;
	IPizzaStore::mIngredientFactory = PizzaIngredientFactory(new ChicagoIngredientFactory);

	if (rPizzaType == "cheese")
	{
		vPizza = std::shared_ptr<IPizza>(new CheesePizza(mIngredientFactory));
		vPizza->setName(this->mStoreTypeName + " style " + rPizzaType + "pizza");
	}
	else
	{
		throw std::runtime_error("pizza type not yet supported");
	}

	return vPizza;

}

