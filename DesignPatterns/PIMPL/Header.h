#pragma once

class OutsideClass
{
public:
	OutsideClass();
	void FunctionOne();
	void FunctionTwo();
private:
	//Forward declaration
	class OutsideClassImpl;
	
	OutsideClassImpl* pimpl;
};

