//Write Declarations for the following, initializing each one:

// a pointer to a character:

#include <iostream>

int main() {
	char c = '0';
	char* cp = &c;
	
	//an array of 10 integers:

	int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int (&Raar) [10] = arr;  //Thanks to stack overflow for this answer (numerous users). Not having the [10] results in a compiler error about not being able to assign int [10]
																		 // to a pointer type or somthing like that. 
	std::cout << "\n" << arr <<" "<< Raar<< "\n";
	std::cout << arr[1];

	//a pointer to an array of character strings:

	char arrC[3] = { 'a', 'b', 'c' }; //Note the put to (<<) operator is overloaded to print strings, so std::cout << arrC; will output abc NOT the memory address of the first element.
	
	char (*arrC_p) = &(arrC[3]);   
	
	

 


	return 0;
}