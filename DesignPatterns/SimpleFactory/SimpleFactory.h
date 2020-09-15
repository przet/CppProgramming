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

struct PizzaSimpleFactory
{
	virtual std::shared_ptr<IPizza> createPizza(std::string rPizzaType)
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

struct NYPizzaFactory : public PizzaSimpleFactory
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

struct ChicagoPizzaFactory : public PizzaSimpleFactory
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

class PizzaStore
{
public:
	PizzaStore(PizzaSimpleFactory* rPizzaSimpleFactory)
		:mFactory(rPizzaSimpleFactory)
	{

	}
	std::shared_ptr<IPizza> orderPizza(std::string rPizzaType)
	{
		auto vPizza = std::make_shared<IPizza>();

		vPizza = mFactory->createPizza(rPizzaType);
		producePizzaOrder(vPizza);

		return vPizza;
	}

private:
	PizzaSimpleFactory* mFactory;
	void producePizzaOrder(std::shared_ptr<IPizza> rPizza)
	{
		rPizza->prepare();
		rPizza->bake();
		rPizza->cut();
		rPizza->box();
	}

};
