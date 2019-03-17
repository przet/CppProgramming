#include "Header.h"
#include <iostream>

struct ModelA : public IModelAIfce
{
	void DoSomething() override;
	void DoAnotherThing() override;

	struct AQueryImpl : public IQuery
	{
		void ReadData() override
		{
            std::cout << "Reading Data" << std::endl;
		}

		void SendData() override
		{
            std::cout << "Sending Data" << std::endl;
		}
	};

	ModelA()
	{
		AQueryImpl QueryImplInstance;
		QueryPtr = &QueryImplInstance;
	}

};

void ModelA::DoSomething()
{
    std::cout << "Hi, I am ModelA, and I am doing something" << std::endl;
}

void ModelA::DoAnotherThing()
{
    std::cout << "Hi, I am ModelA, and I am doing another thing" << std::endl;
}

int main()
{
	ModelA ModelAInstance;
	ModelAInstance.QueryPtr->ReadData();
    return 0;
}
