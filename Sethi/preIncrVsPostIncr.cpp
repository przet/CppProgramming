#include <iostream>

int main ()
{
	int var=5;
	std::cout<<var++;  //returns 5. Then increments var by 1
	std::cout<<'\n';
	std::cout<<var;
	
	std::cout<<"\n\n";
	
	int var2=5;
	std::cout<<++var2;  //incremets var2 by 1, then returns the new result.
	std::cout<<'\n';
	std::cout<<var2;
}