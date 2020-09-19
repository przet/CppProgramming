#include "pch.h"
#include "PizzaStoreInterface.h"

IPizzaStore::~IPizzaStore() {}

Pizza IPizzaStore::orderPizza(std::string rPizzaType)
{
	auto vPizza = std::make_shared<IPizza>(rPizzaType);

	vPizza = createPizza(rPizzaType);
	producePizzaOrder(vPizza);

	return vPizza;
}

void IPizzaStore::producePizzaOrder(Pizza rPizza)
{
	rPizza->prepare();
	rPizza->bake();
	rPizza->cut();
	rPizza->box();
}
