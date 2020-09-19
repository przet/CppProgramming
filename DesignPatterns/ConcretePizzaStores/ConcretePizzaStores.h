#pragma once
#include "../PizzaStoreInterface/PizzaStoreInterface.h"
#include "../ConcretePizzas/ConcretePizzas.h"

struct NYPizzaStore : public IPizzaStore
{
	NYPizzaStore();
	virtual Pizza createPizza(std::string rPizzaType) override;
};

struct ChicagoPizzaStore : public IPizzaStore
{
	ChicagoPizzaStore();
	virtual Pizza createPizza(std::string rPizzaType) override;
};

struct MixedPizzaStore : public IPizzaStore
{
	MixedPizzaStore();
	virtual Pizza createPizza(std::string rPizzaType) override;
};
