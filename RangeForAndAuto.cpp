#include <iostream>
#include <string>

int main()
{
	std::string str("some string");
	// print the characters in str one character to a line
	for (auto c : str)
		std::cout << c << std::endl;
	
	// now how would one do this WITHOUT a range for?
	for (int i = 0; i < str.size(); ++i)
	{
		std::cout << str[i] << std::endl;
	}
	// note that the above was using the knowledge that a string is an array of chars (C) to access it.
	// but using the string data type (C++) to use the size() function.
	// BUT NOT THIS was "Lucky thinking" in that it just turns out that
	// str[i] works (well it might have been defined like that, or maybe its 
	//in the string defintion) but remember string is a template class from the
	//STL
}