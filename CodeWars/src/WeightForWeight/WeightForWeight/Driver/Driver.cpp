#include "..\Algorithm\Algorithm.h"

int main()
{
	try
	{
		std::string vInput("3 16 9 38 95 1131268 49455 347464 59544965313 496636983114762 85246814996697");
		auto result = WeightSort::orderWeight(vInput);
		std::cout << result;
		return 0;

	}
	catch (std::exception& e)
	{
		std::cout << e.what()  << std::endl;

	}
}

