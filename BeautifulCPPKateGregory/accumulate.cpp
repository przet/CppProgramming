#include <iostream>
#include <numeric> //!!NOTE. accumulate in the numeric, not algorithm, header
#include <vector>

int main ()
{
		std::vector<int> a {1,2,3,4,5};

		//non stl algo way of totalling the vector elements, although ranged for is still safer (less room for mistakes)
		//than standard for loop
		int total = 0;
		for (int i : a)
				total +=i;
		std::cout.setf(std::ios::boolalpha);
		std::cout << (total == 5*6/2) << std::endl;

		//But check this out! Note the starting value - same as total above- as the (manadtory) third argument
		total = 0;
		total = std::accumulate(begin(a),end(a),0);
		std::cout << (total == 5*6/2) << std::endl;

		//some lambda fun now :)
		total = std::accumulate(begin(a),end(a),0,[](auto totalSoFar, auto elem){if(elem%2==0)return totalSoFar+elem;return totalSoFar;});
		std::cout << (total == 6) << std::endl;

		total = std::accumulate(begin(a), end(a), 1, [](auto tsf, auto el){return tsf*el;});
		std::cout << total << std::endl;

		//note the lambda takes in as one if its arguments the starting value (the third argument in accumulate
		//I can rewrite the call of accumulate to generate the same effect as its default call, using a lambda, to
		//show how things are passed into the lambda:

		total = std::accumulate(begin(a), end(a),0,[](auto total, auto i){return total + i;});
		std::cout << (total == 5*6/2) << std::endl;

		//In fact, check this out:
		total = std::accumulate(begin(a), end(a),0,[](auto total, auto i){return total;});
		std::cout << (total ==0 ) << std::endl;
		total = std::accumulate(begin(a), end(a),12345,[](auto total, auto i){return total;});
		std::cout << (total == 12345 ) << std::endl;
		total = std::accumulate(begin(a), end(a),12345,[](auto total, auto i){return i;});
		std::cout << (total == 5 ) << std::endl;
		total = std::accumulate(begin(a), end(a),12345,[]( auto i,auto total){return i;});
		std::cout << (total == 12345 ) << std::endl; //!Argument order in Lambda's matter! Here i is acting like total, the thing coming in)
		total = std::accumulate(begin(a), end(a),12345,[]( auto i,auto total){return total;});
		std::cout << (total == 5 ) << std::endl; 
		a.push_back(198);
		total = std::accumulate(begin(a), end(a),12345,[]( auto total,auto i){return i;});
		std::cout << (total == 198 ) << std::endl; 
		a.erase(--end(a));





		return 0;
}

