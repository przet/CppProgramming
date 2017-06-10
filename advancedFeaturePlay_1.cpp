#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <map>
#include <string>
#include <algorithm>
#include <random>
#include <memory>

int main ()
{
	std::vector <float> v(10);
	std::cout << std::addressof(v) << std::endl;
	std::vector <float> * vp = &v;
	std::cout << vp << std::endl;
	vp == std::addressof(v) ? std::cout << "Yes!" << std::endl :
		std::cout << "No!" << std::endl;

	std::default_random_engine generator;
	std::gamma_distribution <float> distribution(1, 10);
	for (auto i : v)
	{
		i = distribution(generator);
		std::cout << i << std::endl;
	}
	
	std::vector <std::string> w(2);
	std::shared_ptr <std::vector <std::string> > wp;
	for (auto i : w)
	{
		i = "PASSED";
		std::cout << i << std::endl;
	}
		




}


