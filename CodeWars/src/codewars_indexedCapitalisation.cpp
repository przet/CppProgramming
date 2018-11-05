#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::string str = "abcdef";
    std::vector <int> vec {1, 2, 5};

    std::cout << str[0];
    str[0] = 'h';
    std::cout << str[0];
    
    
    /*for (int i = 0; i <= vec.size(); ++i) 
    {
	//std::cout << "\n" << vec.size();
	int ascii_zeroIndx = static_cast<int> (str[0]);
	//std::cout << "\n" << ascii_zeroIndx;





    }   
	*/

    std::string testStr = "Abcdef";
    testStr[0] = 97;
    std::cout << '\n' << testStr << std::endl;
    std::vector <int> vec {1, 2, 100, 5};

    std::cout << str << std::endl;
    /*std::cout <<'\n' << str [0]<< std::endl;
    str[0] = 'H';
    std::cout << str [0] << std::endl; */
    
    for (int i = 0; i <= vec.size()-1 ; ++i) 
    {
	/*
	int ascii_zeroIndx = static_cast<int> (str[0]);
	std::cout << "\n" << ascii_zeroIndx; */
	//std::cout << vec[i] << std::endl;
	
	//Test that index of vector is within the range of indicies of the string	
	str[vec[i]] = static_cast<int> (str[vec[i]]) -32;
	//std::cout <<'\n' << str[vec[i]] << std::endl;


    }   

    std::cout << str << std::endl;






}
