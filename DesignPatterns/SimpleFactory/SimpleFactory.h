#pragma once
#include <string>
#include <iostream>
#include <memory>
#include <stdexcept>

// Adapted from head first design patterns.

struct IPizza
{
	virtual void prepare() {};
	virtual void bake() {};
	virtual void cut() {};
	virtual void box() {};
};

struct CheesePizza : public IPizza
{
	CheesePizza() :mPizzaType("CheesePizza")
	{
		mPizzaType += " is in ";
	}
	virtual void prepare() override { std::cout << mPizzaType << __func__ << " stage\n"; }
	virtual void bake() override {std::cout << mPizzaType << __func__ << " stage\n";}
	virtual void cut() override {std::cout << mPizzaType << __func__ << " stage\n";}
	virtual void box() override {std::cout << mPizzaType << __func__ << " stage\n";}

	std::string mPizzaType;

};

// This could be a free function perhaps, there is no state we are modifying
struct PizzaSimpleFactory
{
	// TODO...templates. Having to pass in string is error prone (or needs lots of diferrent cases covered!
	static std::shared_ptr<IPizza> createPizza(std::string rPizzaType)
	{
		auto vPizza = std::make_shared<IPizza>();
		
		if (rPizzaType == "cheese")
		{
			vPizza = std::shared_ptr<IPizza>(new CheesePizza);
		}
		else
		{
			throw std::runtime_error("pizza type not yet supported");
		}

		return vPizza;

	}
};

namespace PizzaStore
{
	void producePizzaOrder(std::shared_ptr<IPizza> rPizza)
	{
		rPizza->prepare();
		rPizza->bake();
		rPizza->cut();
		rPizza->box();
	}

	std::shared_ptr<IPizza> orderPizza(std::string rPizzaType)
	{
		auto vPizza = std::make_shared<IPizza>();
		
		vPizza = PizzaSimpleFactory::createPizza(rPizzaType);
		producePizzaOrder(vPizza);

		return vPizza;
	}

}
