#include<vector>
#include<iostream>

int main()
{
	std::vector<int> v {1,2,3,4};
	int odds = 0;
	for (auto elem : v) //better than traditional for loop - less places to go wrong, don't need to worry about breaking out etc.
		if (elem % 2 != 0)
			odds++;
	std::cout << odds << std::endl;
	return 0;
}
