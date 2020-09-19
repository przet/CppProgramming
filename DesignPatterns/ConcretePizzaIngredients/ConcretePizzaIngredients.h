#pragma once
#include "../PizzaIngredientInterfaces/PizzaIngredientInterfaces.h"


struct ThinCrustDough : public IDough
{
    ThinCrustDough()
    {
        IDough::mName = "Thin Crust Dough";
    }

};

struct ThickCrustDough : public IDough
{
    ThickCrustDough()
    {
        IDough::mName = "Thick Crust Dough";
    }

};

struct PlumTomatoSauce : public ISauce
{
    PlumTomatoSauce()
    {
        ISauce::mName = "Plum Tomato Sauce";
    }

};

struct MarinaraSauce : public ISauce
{
    MarinaraSauce()
    {
        ISauce::mName = "Marinara Sauce";
    }
};

struct ReggianoCheese : public ICheese
{
    ReggianoCheese()
    {
        ICheese::mName = "Reggiano Cheese";
    }

};

struct MozzarellaCheese : public ICheese
{
    MozzarellaCheese()
    {
        ICheese::mName = "Mozzarella Cheese";
    }

};

struct Garlic : public IVeggies
{
    Garlic()
    {
        IVeggies::mName = "Garlic";
    }

};

struct Onion : public IVeggies
{
    Onion()
    {
        IVeggies::mName = "Onion";
    }

};

struct Mushroom : public IVeggies
{
    Mushroom()
    {
        IVeggies::mName = "Mushroom";
    }

};

#define _create_def_ctor(ClassName, Parent) \
ClassName() \
{\
Parent::mName = #ClassName;\
}

struct RedPepper : public IVeggies
{
    _create_def_ctor(RedPepper, IVeggies)

};

struct Spinach : public IVeggies
{
    _create_def_ctor(Spinach, IVeggies)

};

struct BlackOlives : public IVeggies
{
    _create_def_ctor(BlackOlives, IVeggies)

};

struct EggPlant : public IVeggies
{
    _create_def_ctor(EggPlant, IVeggies)

};

struct SlicedPepperoni : public IPepperoni
{
    _create_def_ctor(SlicedPepperoni, IPepperoni)

};

struct FreshClams : public IClams
{
    _create_def_ctor(FreshClams, IClams)

};

struct FrozenClams : public IClams
{
    _create_def_ctor(FrozenClams, IClams)

};



