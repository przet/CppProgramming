#include "pch.h"
#include "PizzaStoreInterface.h"
#include <stdexcept>
#include <memory>

IPizzaStore::~IPizzaStore() {}

Pizza IPizzaStore::orderPizza(std::string rPizzaType)
{
	std::shared_ptr<IPizza> vPizza = nullptr;

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
