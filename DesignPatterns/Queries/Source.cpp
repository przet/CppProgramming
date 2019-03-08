#include "Header.h"

struct ModelA : public IModelAIfce
{
	void DoSomething() override;
	void DoAnotherThing() override;

	struct AQueryImpl : public IQuery
	{
		void ReadData() override
		{
			//Read Data Impl
		}

		void SendData() override
		{
			//Send Data Impl 
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
	int a = 1;
	int b = 2;
	int sum = a + b;
}

void ModelA::DoAnotherThing()
{
	int a = 1;
	int b = 2;
	int prod = a * b;
}

int main()
{
	ModelA ModelAInstance;
	ModelAInstance.QueryPtr->ReadData();

}
