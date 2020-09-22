#pragma once
#ifndef __BOILER__H
#define __BOILER__H
#include <memory>

class ChocolateBoiler;
using ChocolateBoilerPtr = std::shared_ptr<ChocolateBoiler>;

class ChocolateBoiler
{
	public:
		static ChocolateBoilerPtr getInstance()
		{
			if (!mUniqueInstance)
			{
				mUniqueInstance = ChocolateBoilerPtr(new ChocolateBoiler);
			}
			return mUniqueInstance;
		}

		void fill();
		void drain();
		void boil();
		bool boilerIsEmpty();
		bool mixtureIsBoiled();
		static ChocolateBoilerPtr mUniqueInstance;

	private:
		ChocolateBoiler();
		bool mEmpty;
		bool mBoiled;


};

#endif  
