#include <iostream>
#include <vector>
#include <algorithm>

int main ()
{
	//STL way to count how many entries have the target value (2)
	int const target = 2; // still have this: nice little "executable commment"
	std::vector <int> v {2,2,3,4,5};
	int simple = std::count(begin(v),end(v),target); //self documenting - no comments needed
	std::cout << simple << std::endl;


	return 0;
		
}


