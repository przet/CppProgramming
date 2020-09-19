#pragma once
#include "../Pizza/Pizza.h"

using BaseClass = IPizza;

struct NYCheesePizza : public IPizza
{
	NYCheesePizza(std::string rPizzaType);
};
struct ChicagoCheesePizza : public IPizza
{
	ChicagoCheesePizza(std::string rPizzaType);
};

