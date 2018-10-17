#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

int main()
{
    //set up std::cout formatting
	std::cout.setf(std::ios::boolalpha);

	std::vector<int> v{2,4,6,6,1,3,-2,0,11,2,3,2,4,4,2,4}; //carefully constructed by Kate to have adjacent members etc
	auto result = std::find_if_not(begin(v),end(v),[](auto i){return i%2 !=0;});
	std::cout << "first even number of collection is " << *result << std::endl;
	
	std::vector<int> primes{1,2,3,5,7,11,13};
	result = std::find_first_of(begin(v), end(v), begin(primes), end(primes));
	std::cout << *result << std::endl;
	std::vector<int> v2{4,6,6,3,-2};
	auto result2 = std::find_first_of(begin(v2),end(v2), begin(primes),end(primes));
	std::cout << *result2 << std::endl;
	std::vector<int> subsequence {2,4};

	//std::search. It may not do what you think it does. Booleans are not returned:
	//rather iterators. So in the example below, the iterator returns points to
	// 2, as that is the beginning of the subsequence, and matches the first 2 in v.
	result = std::search(begin(v), end(v), begin(subsequence), end(subsequence));
	std::cout <<"std::search result is: " << *result << std::endl;

	//To understand this, see what happens when returning the value of next iterator (forward by one):
	std::cout <<(*++result == 4) << std::endl;

	//reset result, as the increment above will have incremented the iterator ('result')
	result = std::search(begin(v), end(v), begin(subsequence), end(subsequence));
	
	std::cout << (*result++ ==2) <<std::endl;

	//reset result, as the increment above will have incremented the iterator ('result')
	result = std::search(begin(v), end(v), begin(subsequence), end(subsequence));
	
	std::cout << (*++++result ==6) << std::endl;
    	
	//reset result, as our increments above will have incremented the iterator ('result')
	result = --end(v);
	/*sidebar*/std::cout << (*result ==4) << std::endl;
	result = end(v);
	/*sidebar*/std::cout << *result << std::endl;

	std::string sentence = "Hello there mate!";
	std::string mate = "He";
	auto letter = std::search(begin(sentence),end(sentence),begin(mate), end(mate));
	std::cout << *letter << std::endl;
    
	result = find_end(begin(v),end(v),begin(subsequence), end(subsequence));
	std::cout <<(end(v)==++++result)<< std::endl;
	//translation: result is the iterator pointing to the first element of the
	//last occurence of subsequence
	
	//search for two 4's in a row
	result = std::search_n(begin(v),end(v),2,4);
	std::cout << (end(v)== ++++++++result) <<std::endl;
	//checked that indeed result pointed to the first occurence
	//of the adjacent 4's. Likewise:
	result = std::search_n(begin(v), end(v),2,6);
	std::cout << (begin(v)== ----result) << std::endl;

	//Finally adjacent find: always looks for two values in a row
	//this time I want to print v to screen so that I don't have to come back to look at the source.
	//I won't worry about brackets to make it look like a vector, but an interesting problem to do so
	//(would have to do something on the first and last elements)
	
	result = std::adjacent_find(begin(v),end(v));
	std::cout << (*result == 6 && *++result == 6 && *++result == 1) << std::endl;
	//NOTE what I did in the last &&: because result has already been incremented,
	//I only need to do ++result to get the iterator pointing to the element after
	//the last six in the adjacent pair.
	
	//to find the next repeated numbers:
	result = std::adjacent_find(result,end(v));
	std::cout << (*result==4) << std::endl;


return 0;
}
