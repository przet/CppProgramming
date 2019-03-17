#include "Header.h"
#include <iostream>

class OutsideClass:: OutsideClassImpl
{
public:
	void FunctionOne()
	{
		std::cout << "The implemenation function has been successfully called" << std::endl;
	}
};

OutsideClass::OutsideClass()
{
	OutsideClassImpl outsideClassImpl_Instance;
	pimpl = &outsideClassImpl_Instance;
}

void OutsideClass::FunctionOne()
{
	pimpl->FunctionOne();
}

int main()
{
	OutsideClass outSideClass_Instance;
	outSideClass_Instance.FunctionOne();
	system("pause");
	return 0;
}