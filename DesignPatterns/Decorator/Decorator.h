#pragma once
// Head First Design Patterns Book
struct IBeverage
{
	virtual float cost() = 0;
	virtual std::string description()
	{
		return mDescription;
	}

	std::string mDescription = "Unkown Beverage";
};

struct ICondimentDecorator : public IBeverage
{
	virtual std::string description() override = 0;

};

struct Espresso : public IBeverage {
	Espresso(float rCost = 1.99)
		: mCost(rCost)
	{
		IBeverage::mDescription = "Espresso";
	}

	virtual float cost() override
	{
		return mCost;
	}
	float mCost;
};

struct Mocha : public ICondimentDecorator
{
	Mocha(IBeverage* rBeverage)
		: mBeverage(rBeverage)
	{

	}

	virtual std::string description() override
	{
		return mBeverage->description() + ", Mocha";
	}

	virtual float cost() override
	{
		return 0.20 + mBeverage->cost();
	}

	IBeverage* mBeverage;

};
