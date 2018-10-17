#include <iostream>
#include <algorithm>
#include <vector>

int main ()
{
	std::vector<int> v{1,2,3,4,5,6,7,8,9,10};
	auto areAllOdd = std::all_of(begin(v),end(v),[](auto i){return i %2 !=0;});
	auto areAnyOdd = std::any_of(begin(v),end(v),[](auto i){return i %2 !=0;});
	auto areNoneOdd = std::none_of(begin(v),end(v),[](auto i){return i %2 !=0;});
	std::cout << areAllOdd << std::endl;
	std::cout << areAnyOdd << std::endl;
	std::cout << areNoneOdd << std::endl;

	return 0;
	}

	//TODO:It was interesting when I accidently wrote the 
	// ranges as (begin(v), begin(v)). I want to come back
	//and find out what this means
