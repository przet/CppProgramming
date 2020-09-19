#include "pch.h"
#include "Pizza.h" 

IPizza::IPizza(std::string rPizzaType) : mPizzaType(rPizzaType),
mBakeTime(25), mBakeTemp(250), mSliceShape("Diagonal")
{
}

void IPizza::prepare()
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
		[](const auto& rTopping) { std::cout << "\t-" << rTopping << std::endl; });
}

void IPizza::bake()
{
	std::cout << mPizzaType << __func__ << " stage\n";
	std::cout << "Baking for " << mBakeTime << "min at " << mBakeTemp << " deg C" << std::endl;
}

// Only cut can be overriden

void IPizza::cut()
{
	std::cout << mPizzaType << __func__ << " stage\n";
	std::cout << "Cutting into " << mSliceShape << " slices" << std::endl;
}

void IPizza::box()
{
	std::cout << mPizzaType << __func__ << " stage\n";
	std::cout << "Placing pizza in official box " << std::endl;
}
