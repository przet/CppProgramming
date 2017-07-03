#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>


int main() {
    int a = 0, b = 0;
	std::cin >> a;
    std::cin >> b;
	typedef std::map <int, std::string> Map;
	Map m;
	m[1] = "one";
	m[2] = "two";
	m[3] = "three";
	m[4] = "four";
	m[5] = "five";
	m[6] = "six";
	m[7] = "seven";
	m[8] = "eight";
	m[9] = "nine";

    std::vector <int> interval;
    for (int i = a;i <= b;++i)
    {
        interval.push_back(i);
    }
    
    // console checker
    /*for (auto it = begin(interval); it != end(interval); ++it)
    {
            std::cout << *it << std::endl;
    }
 */   
    for (auto it = begin(interval); it != end(interval); ++it)
    {
        if (*it>=1 && *it <=9)
            std::cout << m.at(*it) << std::endl;
        else if (*it >=10 && *it % 2 == 0)
            std::cout << "even" << std::endl;
        else if (*it > 9 && *it % 2 != 0)
            std::cout << "odd" << std::endl;
    }
	
    
    return 0;
}