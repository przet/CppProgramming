#include<regex>
#include<stdio.h>
#include<fstream>
#include<iostream>

int main(int argc, char **argv)
{
	std::fstream file;
	if (argc == 1){
		printf("\n\nUsage: write in file name after program name (whitespace seperated)\nProgram Terminating...\n\n");
		return 0;
		}
	std::string fileIfError;
	file.open(argv[1],std::ios::in);
	if(file.fail())
		std::cerr << "File does not exist" << std::endl;
		


	file.close();




}
