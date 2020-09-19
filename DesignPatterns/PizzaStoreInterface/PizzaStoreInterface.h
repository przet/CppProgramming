#pragma once
#include "../Pizza/Pizza.h"
#include <memory>

class IPizzaStore
{
public:
	virtual ~IPizzaStore();
	virtual Pizza createPizza(std::string rPizzaType) = 0;
	virtual Pizza orderPizza(std::string rPizzaType) final;
	std::string mStoreTypeName;

private:
	virtual void producePizzaOrder(Pizza rPizza) final;
};
