#pragma once
#include "../PizzaIngredientFactoryInterface/PizzaIngredientFactoryInterface.h"
#include "../ConcretePizzaIngredients/ConcretePizzaIngredients.h"

struct NYPizzaIngredientFactory : public IPizzaIngredientFactory
{
    // Inherited via IPizzaIngredientFactory
    virtual Dough createDough() override;

    virtual Sauce createSauce() override;

    virtual Cheese createCheese() override;

    virtual Vec<Veggies> createVeggies() override;

    virtual Pepperoni createPepperoni() override;

    virtual Clams createClams() override;
};

struct ChicagoIngredientFactory : public IPizzaIngredientFactory
{
    // Inherited via IPizzaIngredientFactory
    virtual Dough createDough() override;
    virtual Sauce createSauce() override;
    virtual Cheese createCheese() override;
    virtual Vec<Veggies> createVeggies() override;
    virtual Pepperoni createPepperoni() override;
    virtual Clams createClams() override;
};

