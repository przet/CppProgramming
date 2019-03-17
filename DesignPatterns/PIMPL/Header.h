#pragma once

class ModelClass
{
public:
	ModelClass();
	void FunctionOne();
	void FunctionTwo();
private:
	// Forward declaration
	class ModelClassImpl;

    // Pointer to the Implementation class
	ModelClassImpl* pimpl;
};

