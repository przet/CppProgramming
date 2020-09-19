#pragma once
#include <string>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <list>
#include <algorithm>

// Adapted from head first design patterns.

class Pizza
{
    public:
		Pizza(std::string rPizzaType) : mPizzaType(rPizzaType),
			mBakeTime(25), mBakeTemp(250), mSliceShape("Diagonal")
        {
        }

    public:
        virtual void prepare() final
		{
			if (!mDough.size())
				throw std::logic_error("Dough type not set");
			if (!mSauce.size())
				throw std::logic_error("Sauce type not set");
			if (!mToppingList.size())
				throw std::logic_error("Toppings not set");

			std::cout << mPizzaType << __func__ << " stage\n";
			std::cout << "Using dough " << mDough << std::endl;
			std::cout << "Using sauce " << mSauce << std::endl;

			std::cout << "Adding the following toppings: \n ";
			std::for_each(std::begin(mToppingList), std::end(mToppingList),
				[](const auto& rTopping) { std::cout <<"\t-" << rTopping << std::endl; });
		}
        virtual void bake() final
		{
			std::cout << mPizzaType << __func__ << " stage\n";
			std::cout << "Baking for " << mBakeTime << "min at " << mBakeTemp << " deg C" << std::endl;
		}
		// Only cut can be overriden
        virtual void cut()
		{
			std::cout << mPizzaType << __func__ << " stage\n";
			std::cout << "Cutting into " << mSliceShape << " slices" << std::endl;
		}
        virtual void box() final
		{
			std::cout << mPizzaType << __func__ << " stage\n";
			std::cout << "Placing pizza in official box " << std::endl;
		}

    protected:
        std::string mPizzaType;
        std::string mDough;
        std::string mSauce;
        std::list<std::string> mToppingList;
		std::string mSliceShape;

    private:
		const int mBakeTime;
		const int mBakeTemp;
};

struct NYCheesePizza : public Pizza
{
	using BaseClass = Pizza;
	NYCheesePizza(std::string rPizzaType)
		: Pizza::Pizza(rPizzaType) 
	{
		BaseClass::mPizzaType += "(NY Style) ";
		BaseClass::mDough = "Thin Crust Dough";
		BaseClass::mSauce = "Marinara Sauce";
		BaseClass::mToppingList.push_back("Grated Reggiano Cheese");
	}

};
struct ChicagoCheesePizza : public Pizza
{
	using BaseClass = Pizza;
	ChicagoCheesePizza(std::string rPizzaType)
		: Pizza::Pizza(rPizzaType)
	{
		BaseClass::mPizzaType += "(Chicago Style) ";
		BaseClass::mSliceShape = "square";
		BaseClass::mDough = "Extra Thick Crust Dough";
		BaseClass::mSauce = "Plum Tomato Sauce";
		BaseClass::mToppingList.push_back("Shredded Mozzarella Cheese");
	}


};

class IPizzaStore
{
public:
	virtual std::shared_ptr<Pizza> createPizza(std::string rPizzaType) = 0;

	virtual std::shared_ptr<Pizza> orderPizza(std::string rPizzaType) final
	{
		auto vPizza = std::make_shared<Pizza>(rPizzaType);

		vPizza = createPizza(rPizzaType);
		producePizzaOrder(vPizza);

		return vPizza;
	}

private:
	virtual void producePizzaOrder(std::shared_ptr<Pizza> rPizza) final
	{
		rPizza->prepare();
		rPizza->bake();
		rPizza->cut();
		rPizza->box();
	}
};

struct NYPizzaStore : public IPizzaStore
{
	virtual std::shared_ptr<Pizza> createPizza(std::string rPizzaType) override
	{
		auto vPizza = std::make_shared<Pizza>(rPizzaType);
		
		if (rPizzaType == "cheese")
		{
			vPizza = std::shared_ptr<Pizza>(new NYCheesePizza(rPizzaType));
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
	virtual std::shared_ptr<Pizza> createPizza(std::string rPizzaType) override
	{
		auto vPizza = std::make_shared<Pizza>(rPizzaType);
		
		if (rPizzaType == "cheese")
		{
			vPizza = std::shared_ptr<Pizza>(new ChicagoCheesePizza(rPizzaType));
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
		{
			std::cout << "We are in the Chicago store " << std::endl;
			return std::shared_ptr<IPizzaStore>(new ChicagoPizzaStore);
		}
		else if (rPizzaStore == "NY")
		{
			std::cout << "We are in the NY store " << std::endl;
			return std::shared_ptr<IPizzaStore>(new NYPizzaStore);
		}
		else
		{
			throw std::runtime_error("No pizza store in city with abbreviation " + rPizzaStore);
		}
	}
}
