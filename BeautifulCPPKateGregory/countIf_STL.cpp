#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

int main ()
{
	std::vector <int> v {1,2,3,4};
	auto odds = std::count_if(begin(v),end(v),
					[](auto elem) {return elem %2 != 0;});
	std::cout<< odds << std::endl;
	
	std::map<int,int> monthLengths{{1,31},{2,28}};
	auto howManyLongMonths = std::count_if(begin(monthLengths), end(monthLengths),
					[](auto elem){return elem.second == 31;});
	std::cout << howManyLongMonths << std::endl;
			

	return 0;
}
