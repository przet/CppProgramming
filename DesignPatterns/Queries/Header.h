#pragma once

//Using structs to not worry about access

//A data query interface
struct IQuery
{
	virtual void ReadData() = 0;
	virtual void SendData() = 0;
};

//An example model interface, with a query ifce data member
struct IModelAIfce
{
	virtual void DoSomething() = 0;
	virtual void DoAnotherThing() = 0;

	IQuery* QueryPtr;
};
