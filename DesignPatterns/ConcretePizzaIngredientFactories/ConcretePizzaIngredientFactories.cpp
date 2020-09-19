#include "pch.h"
#include "ConcretePizzaIngredientFactories.h"

Dough NYPizzaIngredientFactory::createDough()
{
    return Dough(new ThinCrustDough);
}

Sauce NYPizzaIngredientFactory::createSauce()
{
    return Sauce(new MarinaraSauce);
}

Cheese NYPizzaIngredientFactory::createCheese()
{
    return Cheese(new ReggianoCheese);
}

Vec<Veggies> NYPizzaIngredientFactory::createVeggies()
{
    Vec<Veggies> vVeggiesList
    {
        std::shared_ptr<IVeggies>(new Garlic),
        std::shared_ptr<IVeggies>(new Onion),
        std::shared_ptr<IVeggies>(new Mushroom),
        std::shared_ptr<IVeggies>(new RedPepper),
    };

    return vVeggiesList;
}

Pepperoni NYPizzaIngredientFactory::createPepperoni()
{
    return Pepperoni(new SlicedPepperoni);
}

Clams NYPizzaIngredientFactory::createClams()
{
    return Clams(new FreshClams);
}

Dough ChicagoIngredientFactory::createDough()
{
    return Dough(new ThickCrustDough);
}

Sauce ChicagoIngredientFactory::createSauce()
{
    return Sauce(new PlumTomatoSauce);
}

Cheese ChicagoIngredientFactory::createCheese()
{
    return Cheese(new MozzarellaCheese);
}

Vec<Veggies> ChicagoIngredientFactory::createVeggies()
{
    Vec<Veggies> vVeggiesList
    {
        std::shared_ptr<IVeggies>(new Spinach),
        std::shared_ptr<IVeggies>(new BlackOlives),
        std::shared_ptr<IVeggies>(new EggPlant),
    };

    return vVeggiesList;
}

Pepperoni ChicagoIngredientFactory::createPepperoni()
{
    return Pepperoni(new SlicedPepperoni);
}

Clams ChicagoIngredientFactory::createClams()
{
    return Clams(new FreshClams);
}
