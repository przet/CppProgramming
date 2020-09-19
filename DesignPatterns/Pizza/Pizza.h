#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include <list>
#include <algorithm>
#include <memory>

class IPizza;
using Pizza = std::shared_ptr<IPizza>;

class IPizza
{
    public:
        IPizza(std::string rPizzaType);
		virtual ~IPizza() {};

		virtual void prepare() final;
		virtual void bake() final;
		virtual void cut(); // Only cut can be overriden
        virtual void box() final;

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
