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







}
