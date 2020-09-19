#include "pch.h"
#include "ConcretePizzas.h"

NYCheesePizza::NYCheesePizza(std::string rPizzaType)
	: IPizza::IPizza(rPizzaType)
{
	BaseClass::mPizzaType += "(NY Style) ";
	BaseClass::mDough = "Thin Crust Dough";
	BaseClass::mSauce = "Marinara Sauce";
	BaseClass::mToppingList.push_back("Grated Reggiano Cheese");
}

ChicagoCheesePizza::ChicagoCheesePizza(std::string rPizzaType)
	: IPizza::IPizza(rPizzaType)
{
	BaseClass::mPizzaType += "(Chicago Style) ";
	BaseClass::mSliceShape = "square";
	BaseClass::mDough = "Extra Thick Crust Dough";
	BaseClass::mSauce = "Plum Tomato Sauce";
	BaseClass::mToppingList.push_back("Shredded Mozzarella Cheese");
}
