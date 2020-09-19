#pragma once
#include "../Pizza/Pizza.h"
#include "../PizzaIngredientFactoryInterface/PizzaIngredientFactoryInterface.h"

using BaseClass = IPizza;
using PizzaIngredientFactory = std::shared_ptr < IPizzaIngredientFactory>;

class CheesePizza : public IPizza
{
    public:
        CheesePizza(PizzaIngredientFactory rIngredientFactory)
            :mIngredientFactory(rIngredientFactory)
        {
        }
        virtual void prepare() override
        {
            mDough = mIngredientFactory->createDough();
            mSauce = mIngredientFactory->createSauce();
            mCheese = mIngredientFactory->createCheese();
        }
    
    private:
        PizzaIngredientFactory mIngredientFactory;


};

class ClamPizza : public IPizza
{
    public:
        ClamPizza(PizzaIngredientFactory rIngredientFactory)
            :mIngredientFactory(rIngredientFactory)
        {
        }

        virtual void prepare() override
        {
            mDough = mIngredientFactory->createDough();
            mSauce = mIngredientFactory->createSauce();
            mCheese = mIngredientFactory->createCheese();
        }
    
    private:
        PizzaIngredientFactory mIngredientFactory;

};
