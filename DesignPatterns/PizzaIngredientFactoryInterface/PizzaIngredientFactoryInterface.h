#pragma once
#include <memory>
#include "../PizzaIngredientInterfaces/PizzaIngredientInterfaces.h"
#include <vector>

using Dough = std::shared_ptr<IDough>;
using Sauce = std::shared_ptr<ISauce>;
using Cheese = std::shared_ptr<ICheese>;
using Veggies = std::shared_ptr<IVeggies>;
using Pepperoni = std::shared_ptr<IPepperoni>;
using Clams = std::shared_ptr<IClams>;

template <typename T>
using Vec = std::vector<T>;

struct IPizzaIngredientFactory
{
    virtual ~IPizzaIngredientFactory() {}

    virtual Dough createDough() = 0;
    virtual Sauce createSauce() = 0;
    virtual Cheese createCheese() = 0;
    virtual Vec<Veggies> createVeggies () = 0;
    virtual Pepperoni createPepperoni() = 0;
    virtual Clams createClams() = 0;
};
