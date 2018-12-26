//Following https://msdn.microsoft.com/en-us/library/ms235636.aspx
#pragma once

#ifdef MATHLIBRARY_EXPORTS
#define MATHLIBRARY_API __declspec(dllexport)
#else
#define MATHLIBRARY_API __declspec(dllexport)
#endif

namespace MathLibrary
{
	//This class is exported from the MathLibrary.dll
	class Functions
	{
	public:
		// Returns a + b
		static MATHLIBRARY_API double Add(double a, double b);



	};
}
