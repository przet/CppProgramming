#pragma once
class ChocolateBoiler
{
	public:
		ChocolateBoiler();
		void fill();
		void drain();
		void boil();
		bool boilerIsEmpty();
		bool mixtureIsBoiled();

	private:
		bool mEmpty;
		bool mBoiled;


};
