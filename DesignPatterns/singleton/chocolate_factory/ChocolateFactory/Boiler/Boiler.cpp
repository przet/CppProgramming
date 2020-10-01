#include "pch.h"
#include "Boiler.h"

ChocolateBoiler::ChocolateBoiler(const std::string rId) : mEmpty(true), mBoiled(false), mId(rId)
{

}

void ChocolateBoiler::fill()
{
	if (boilerIsEmpty())
	{
		// Code to fill boiler
		mEmpty = false;
		mBoiled = false;
	}

}

void ChocolateBoiler::drain()
{
	if (!boilerIsEmpty() && mixtureIsBoiled())
	{
		// Code to drain the mixture
		mEmpty = true;
	}
}

void ChocolateBoiler::boil()
{
	if (!boilerIsEmpty() && !mixtureIsBoiled())
	{
		// code to boil mixture
		mBoiled = true;
	}
}

bool ChocolateBoiler::boilerIsEmpty()
{
	return mEmpty;

}

bool ChocolateBoiler::mixtureIsBoiled()
{
	return mBoiled;
}
ChocolateBoilerPtr ChocolateBoiler::mUniqueInstance = nullptr;
std::mutex ChocolateBoiler::mMutex;
