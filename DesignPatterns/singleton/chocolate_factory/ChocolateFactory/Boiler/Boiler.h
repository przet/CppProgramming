#pragma once
#ifndef __BOILER__H
#define __BOILER__H
#include <memory>
#include<string>
#include <mutex>

class ChocolateBoiler;
using ChocolateBoilerPtr = std::shared_ptr<ChocolateBoiler>;

class ChocolateBoiler
{
	public:
		static ChocolateBoilerPtr getInstance(const std::string rId)
		{
			if (!mUniqueInstance)
			{
				std::lock_guard<std::mutex> vLock(mMutex);
				if (!mUniqueInstance)
				{
					mUniqueInstance = ChocolateBoilerPtr(new ChocolateBoiler(rId));
				}
			}
			return mUniqueInstance;
		}

		void fill();
		void drain();
		void boil();
		bool boilerIsEmpty();
		bool mixtureIsBoiled();
		std::string mId;
		static ChocolateBoilerPtr mUniqueInstance;

	private:
		ChocolateBoiler(const std::string rId = {});
		bool mEmpty;
		bool mBoiled;
		static std::mutex mMutex;
};

#endif  
