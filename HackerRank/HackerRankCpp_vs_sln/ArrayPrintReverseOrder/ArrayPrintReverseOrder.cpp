#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>



int main() {
	int arraySize = 0;
	int &N = arraySize;
	int* Array = NULL;
	std::cin >> N;
	Array = new int[arraySize];
	if (N>10000 || N<1)

		throw std::runtime_error("N is greater than 1000, or less than 1");
	for (int i = 0; i<N; ++i)
	{
		std::cin >> Array[i];
		if (Array[i] > 10000 || Array[i] < 1)
			throw std::runtime_error("Array element is greater than 10000 or less than 1");
	}
	for (int i = N - 1; i >= 0; --i)
	{
		std::cout << Array[i] << " ";
	}
	delete[] Array;
	Array = NULL;
	return 0;
}
