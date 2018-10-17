#include <iostream>
#include <vector>
#include <algorithm>

int main ()
{
	//'old' way of checking if two vectors are the same.
	std::vector<int> a{1,2,3,4,5};
	std::vector<int> b{1,2,0,4,5};
	
	bool same = a.size()==b.size(); //this will control execution/non-execution of for loop coming up
	int count=0;
	for (int i = 0; i < a.size() && same;++i)
	{
		if (a[i] != b[i])
		{	same = false;
			std::cout <<"Loop execution count is: " << ++count << std::endl;}
		else 
			std::cout <<"Loop execution count is: " << ++count << std::endl;
	}
	std::cout << std::boolalpha << (count == 3) << std::endl;

	// note how if sizes are NOT the same, the for loop is not entered:
	// i is < than size of a but same is false. Otherwise, we continue
	// until we get a mismatch, and then set same to false (in this case
	// sizes may be the same but the elements are not.
	
	// The above is a pretty neat trick leading to some consise code (when you remove
	// my debugging statements. However, as expected, the STL has a one liner:
	
	same = std::equal(begin(a), end(a), begin(b), end(b));
	std::cout.setf(std::ios::boolalpha);
	std::cout << same << std::endl;
	b.erase(--end(b));
	std::cout << same << std::endl;
	std::cout << (b.size() == a.size()-1 ) << std::endl;
	std::vector<int> a1{1,2};
	std::vector<int> b1{1,2};
	same = std::equal(begin(a1), end(a1), begin(b1), end(b1));
	std::cout << same << std::endl;

	//std::mismatch is quite cool:
	//Return value is a pair of iterators
	auto firstchange = std::mismatch(begin(a), end(a), begin(b));
	auto avalue = *(firstchange.first);
	auto bvalue = *(firstchange.second);
	std::cout << (avalue ==3 && bvalue == 0) <<std::endl;
	auto distance = firstchange.first - begin(a) + 1;//NOTE this is an int!! TODO: find out why not an iterator!
	//NOTE2: remove the '+1' just to get the position of the first mismatch, or how many elements before the mismatch.
	std::cout << (distance ==3) << std::endl;

	return 0;
}

