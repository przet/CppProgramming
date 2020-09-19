#include "pch.h"
#include "Pizza.h" 
#include <type_traits>

IPizza::IPizza() : 
mBakeTime(25), mBakeTemp(250), mSliceShape("Diagonal")
{
}

void IPizza::prepare()
{
	if (mDough->mName.size())
		throw std::logic_error("Dough type not set");
	if (!mSauce->mName.size())
		throw std::logic_error("Sauce type not set");
	if (!mVeggieList.size())
		throw std::logic_error("Vegies not set");

	std::cout << mPizzaName << __func__ << " stage\n";
	std::cout << "Using dough " << mDough->mName << std::endl;
	std::cout << "Using sauce " << mSauce->mName << std::endl;

	std::cout << "Adding the following toppings: \n ";
	std::for_each(std::begin(mVeggieList), std::end(mVeggieList),
		[](const auto& rVeggie) { std::cout << "\t-" << rVeggie->mName << std::endl; });
}

void IPizza::bake()
{
	std::cout << mPizzaName << __func__ << " stage\n";
	std::cout << "Baking for " << mBakeTime << "min at " << mBakeTemp << " deg C" << std::endl;
}

// Only cut can be overriden

void IPizza::cut()
{
	std::cout << mPizzaName << __func__ << " stage\n";
	std::cout << "Cutting into " << mSliceShape << " slices" << std::endl;
}

void IPizza::box()
{
	std::cout << mPizzaName << __func__ << " stage\n";
	std::cout << "Placing pizza in official box " << std::endl;
}
