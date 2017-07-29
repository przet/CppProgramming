#include <iostream>
#include <string>
#include <vector>

// Some Global definitions.
int a = 2;
int b = 5;
int* p = NULL;
double c;
float d;
long int e;
short int f;
char g;
std::string str;
std::vector <int> vecInt;
std::vector <double> vecDouble;
std::vector <std::string> vecString;
std::vector <char> vecChar;
std::vector <short> vecShort;
int arr[]; // allowed here in global scope - VS not happy in main though, need to specify size.
int value(4);  // I did not know you could do this in C++


int main()
{
	int a = 2;
	std::cout << a << '\n';
	int b = 4;
	int global_b = ::b;
	std::cout << global_b << '\n';
	int i;
	std::cout << i;
	int* p = NULL;
	double c;
	float d;
	long int e;
	short int f;
	char g;
	std::string str;
	std::vector <int> vecInt;
	std::vector <double> vecDouble;
	std::vector <std::string> vecString;
	std::vector <char> vecChar;
	std::vector <short> vecShort;
	int arr[10];

		



}