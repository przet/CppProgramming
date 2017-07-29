#include <iostream>
#include <string>
#include <chrono>
#include <thread>

int main(int pooC, char** pooV)
{
	std::cout << pooC << " " << pooV[0] << ", "
		<< pooV[1] << ", " << pooV[2];
}











//int main(int argument, double time)
//{
//	std::cout << "Please input argument \n";
//	std::cin >> argument;
//	int n = 5;
//	std::cout << n + argument;
//	std::cout << "Please specify how long you want this thread to pause for \n";
//	std::cin >> time;
//	std::chrono::seconds duration((int)time);
//	std::this_thread::sleep_for(duration);
//	std::cout << "Current thread waited for " << (int)time << " seconds";
//
//	return 0;
//}

