#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include <list>
#include <algorithm>
#include <memory>
#include <vector>
#include "../PizzaIngredientInterfaces/PizzaIngredientInterfaces.h" 

class IPizza;
using Pizza = std::shared_ptr<IPizza>;

//TODO this is duplicated from PizzaIngredientFactoryInterface -
// can we do something about that?
using Dough = std::shared_ptr<IDough>;
using Sauce = std::shared_ptr<ISauce>;
using Cheese = std::shared_ptr<ICheese>;
using Veggies = std::shared_ptr<IVeggies>;
using Pepperoni = std::shared_ptr<IPepperoni>;
using Clams = std::shared_ptr<IClams>;
template <typename T>
using Vec = std::vector<T>;

class IPizza
{
    public:
		IPizza();
		virtual ~IPizza() {};

		virtual void prepare() = 0 ;
		virtual void bake() final;
		virtual void cut(); // Only cut can be overriden
        virtual void box() final;

		// TODO I wanted to avoid these getter and setters,
		// but it makes things easier when accessing via shared_ptrs.
		// Can I get it to work without getters and setters?
		// Is there anything wrong with getter and setters here?
		// Reintroduce it in the constructor?
		void setName(std::string rPizzaName)
		{
			this->mPizzaName = rPizzaName;
		}

		std::string name()
		{
			return mPizzaName;
		}

    protected:
		std::string mSliceShape;
		Dough mDough;
		Sauce mSauce;
		Vec<Veggies> mVeggieList;
		Cheese mCheese;
		Clams mClams;
		Pepperoni mPepperoni;

    private:
        std::string mPizzaName;
		const int mBakeTime;
		const int mBakeTemp;
};
