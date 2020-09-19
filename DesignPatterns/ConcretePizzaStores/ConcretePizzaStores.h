#pragma once
#include "../PizzaStoreInterface/PizzaStoreInterface.h"
#include "../ConcretePizzas/ConcretePizzas.h"

struct NYPizzaStore : public IPizzaStore
{
	virtual Pizza createPizza(std::string rPizzaType) override;
};

struct ChicagoPizzaStore : public IPizzaStore
{
	virtual Pizza createPizza(std::string rPizzaType) override;
};
