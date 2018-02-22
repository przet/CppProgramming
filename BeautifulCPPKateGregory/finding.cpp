#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

int main ()
{
	std::vector<int> v{1,2,3,5,100,4,7,4};
	auto result = std::find(begin(v),end(v),100);
	auto resultDeref = *result;
	//STL find's return an iterator for generality: not everything 
	// can be nicely indexed
	std::cout<< resultDeref << std::endl;
	result = std::find(result,end(v),4);
	if (result != end(v))
		std::cout << "we have found what we are looking for" << std::endl;
//result, begin(v) and end(v) are iterators. end(v) points to one after the end of v

	//works for strings too (or any collection). Note the initialization style:
	std::string s{"Hello There Matey!"};
	auto letter = std::find(begin(s),end(s),'a');
	std::cout << *letter << std::endl;
//TODO: the below won't work though... I will get  a pointer vs integer comparison forbidden error (C++ forbids) at compile time
//	auto word = std::find(begin(s),end(s),"Hello");
//	std::cout << *word << std::endl;

return 0;
}

