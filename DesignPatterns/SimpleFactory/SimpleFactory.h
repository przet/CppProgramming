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

struct NYCheesePizza : public IPizza
{
	NYCheesePizza() :mPizzaType("NYCheesePizza")
	{
		mPizzaType += " is in ";
	}
	virtual void prepare() override { std::cout << mPizzaType << __func__ << " stage\n"; }
	virtual void bake() override {std::cout << mPizzaType << __func__ << " stage\n";}
	virtual void cut() override {std::cout << mPizzaType << __func__ << " stage\n";}
	virtual void box() override {std::cout << mPizzaType << __func__ << " stage\n";}

	std::string mPizzaType;

};
struct ChicagoCheesePizza : public IPizza
{
	ChicagoCheesePizza() :mPizzaType("ChicagoCheesePizza")
	{
		mPizzaType += " is in ";
	}
	virtual void prepare() override { std::cout << mPizzaType << __func__ << " stage\n"; }
	virtual void bake() override {std::cout << mPizzaType << __func__ << " stage\n";}
	virtual void cut() override {std::cout << mPizzaType << __func__ << " stage\n";}
	virtual void box() override {std::cout << mPizzaType << __func__ << " stage\n";}

	std::string mPizzaType;

};

class IPizzaStore
{
public:
	virtual std::shared_ptr<IPizza> createPizza(std::string rPizzaType) = 0;

	virtual std::shared_ptr<IPizza> orderPizza(std::string rPizzaType) final
	{
		auto vPizza = std::make_shared<IPizza>();

		vPizza = createPizza(rPizzaType);
		producePizzaOrder(vPizza);

		return vPizza;
	}

private:
	virtual void producePizzaOrder(std::shared_ptr<IPizza> rPizza) final
	{
		rPizza->prepare();
		rPizza->bake();
		rPizza->cut();
		rPizza->box();
	}
};

struct NYPizzaStore : public IPizzaStore
{
	virtual std::shared_ptr<IPizza> createPizza(std::string rPizzaType) override
	{
		auto vPizza = std::make_shared<IPizza>();
		
		if (rPizzaType == "cheese")
		{
			vPizza = std::shared_ptr<IPizza>(new NYCheesePizza);
		}
		else
		{
			throw std::runtime_error("pizza type not yet supported");
		}

		return vPizza;

	}
};

struct ChicagoPizzaStore : public IPizzaStore
{
	virtual std::shared_ptr<IPizza> createPizza(std::string rPizzaType) override
	{
		auto vPizza = std::make_shared<IPizza>();
		
		if (rPizzaType == "cheese")
		{
			vPizza = std::shared_ptr<IPizza>(new ChicagoCheesePizza);
		}
		else
		{
			throw std::runtime_error("pizza type not yet supported");
		}

		return vPizza;

	}

};

namespace
{
	std::shared_ptr<IPizzaStore> pizzaStore(std::string rPizzaStore)
	{
		if (rPizzaStore == "CHI")
			return std::shared_ptr<IPizzaStore>(new ChicagoPizzaStore);
		else if (rPizzaStore == "NY")
			return std::shared_ptr<IPizzaStore>(new NYPizzaStore);
		else
			throw std::runtime_error("No pizza store in city with abbreviation " + rPizzaStore);
	}
}
