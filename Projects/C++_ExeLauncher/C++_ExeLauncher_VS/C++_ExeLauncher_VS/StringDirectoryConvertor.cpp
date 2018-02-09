#include<string>
#include <fstream>
#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm> // this is to use "find" in string


int main(int argc, char *argv[])
{
    std::fstream file1;
    file1.open("testfileForStringDirectoryConvertor.txt",
        std::ios::in);
    if (file1.fail())
        std::cout <<"Oi! This don't exist yo. Why don't you make sure the file exists!! DO IT NOW!";
    std::vector<std::string> linesVec;
    std::string lines;
    while (std::getline(file1, lines))
        std::back_inserter(linesVec) = lines;
    

    for (auto i : linesVec)
        std::cout << i << std::endl;

    file1.close();
    system("pause");
    return 0;

}