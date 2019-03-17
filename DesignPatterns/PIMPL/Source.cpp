#include "Header.h"
#include <iostream>

class ModelClass::ModelClassImpl 
{
public:
	void FunctionOne()
	{
		std::cout << "The implemenation function has been successfully called" << std::endl;
	}
};

ModelClass::ModelClass()
{
	ModelClassImpl modelClassImpl_Instance;
	pimpl = &modelClassImpl_Instance;
}

void ModelClass::FunctionOne()
{
	pimpl->FunctionOne();
}

int main()
{
	ModelClass modelClass_Instance;
	modelClass_Instance.FunctionOne();
	return 0;
}