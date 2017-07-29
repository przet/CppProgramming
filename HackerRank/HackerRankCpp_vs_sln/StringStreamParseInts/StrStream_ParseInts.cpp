#include <sstream>
#include <vector>
#include <iostream>

//std::vector<int> parseInts(std::string);


int main() {
	std::string str;
	std::cin >> str;
	std::stringstream ss;
	char ch;
	int a, b, c;
	ss << str;
	
	ss >> a;
	std::cout << a;
	ss >> ch;
	printf("%d %c", ch, ch);
	
	
	/*std::vector<int> integers = parseInts(str);
	for (int i = 0; i < integers.size(); i++) {
	std::cout << integers[i] << "\n";
	}*/

	return 0;
}


//std::vector<int> parseInts(std::string str)
//{
//	
//	
//	 
//}



/***************************************************************************
Operator >> Extracts formatted data.
Operator << Inserts formatted data.
Method str() Gets the contents of underlying string device object.
Method str(string) Sets the contents of underlying string device object.*/
