#include <iostream>
#include "../Decorator/Decorator.h"

int main()
{
	Espresso vEspresso;
	IBeverage* vBeverage = &vEspresso;
	Mocha vMocha(vBeverage);
	IBeverage* vCondiment = &vMocha;
	vBeverage = vCondiment;
	std::cout << vBeverage->description() << std::endl;
}

