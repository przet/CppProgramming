#pragma once
#include "../Pizza/Pizza.h"
#include <memory>
#include "../PizzaIngredientFactoryInterface/PizzaIngredientFactoryInterface.h"

using PizzaIngredientFactory = std::shared_ptr<IPizzaIngredientFactory>;

class IPizzaStore
{
    public:
        virtual ~IPizzaStore();
        virtual Pizza createPizza(std::string rPizzaType) = 0;
        virtual Pizza orderPizza(std::string rPizzaType) final;
        std::string mStoreTypeName;

    protected:
        // TODO how can I make sure at the base level that
        // mIngredientFactory is not null when create is called?
        // Or is this a responsibility of the child?
        PizzaIngredientFactory mIngredientFactory;
    public:
        virtual void producePizzaOrder(Pizza rPizza) final;
};
