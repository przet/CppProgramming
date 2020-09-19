#pragma once
#include <string>
struct IDough 
{
    virtual ~IDough() {}
    std::string mName;
};

struct ISauce
{
    virtual ~ISauce() {}
    std::string mName;
};

struct ICheese
{
    virtual ~ICheese() {}
    std::string mName;
};
struct IVeggies
{
    virtual ~IVeggies() {}
    std::string mName;
};

struct IPepperoni
{
    virtual ~IPepperoni() {}
    std::string mName;
};

struct IClams
{
    virtual ~IClams() {}
    std::string mName;
};



