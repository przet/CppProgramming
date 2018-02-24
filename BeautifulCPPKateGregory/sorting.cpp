#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include "sorting.hpp"

int main()
{
 std::vector<int> v{4,1,0,1,-2,3,7,-6,2,0,0,-9,9};
 //original v
 for (auto elem : v)
		 std::cout << elem << ", ";

 std::cout <<std::endl;
 auto v2 = v;
 std::sort(begin(v2),end(v2)); //std::sort is void
 for (auto elem : v2)
		 std::cout << elem << ", ";

 v2 =v;//equivalent: this is default std::sort
 std::sort(begin(v2),end(v2), [](int elem1, int elem2) {return elem1<elem2;});
 std::cout << std::endl; //not just to create a new line, but also to flush buffers (if indeed relevant here)
 for (auto elem : v2)
		 std::cout << elem << ", ";

 //lets explore how std::sort works. We know, from above, the lambda it uses (or rather the lamda that
 //can be used to generate the same effect - I don't know how std::sort is implemented)
 
 //first, reset v2 and see what reversing the condition in the lambda gives
 //v2 = v;
 std::cout <<std::endl;
 std::sort(begin(v2),end(v2), [](int elem1, int elem2) {return elem1>elem2;});
 for (auto elem : v2)
		 std::cout << elem << ", ";
 
 //Note that resetting v2 was NOT required: the result is the same 
 std::cout <<std::endl;
 std::sort(begin(v2),end(v2), [](auto elem1, auto elem2) {return abs(elem1)>abs(elem2);});
 for (auto elem : v2)
		 std::cout << elem << ", ";
  
 

 std::cout<<std::endl;
 std::string s = "ih"; //strings seem to work by ascii val comp
 std::sort(begin(s),end(s));
 for (auto elem : s)
		 std::cout << elem;
 std::cout<<std::endl;
 
MyClass myclass1, myclass2;
myclass1.setX(4);
myclass2.setX(6);
std::vector<MyClass> myClassVec{myclass2,myclass1};
std::cout.setf(std::ios::boolalpha);
for (auto elem : myClassVec)
		std::cout << elem.getX()<< std::endl;
std::sort(begin(myClassVec),end(myClassVec), [](auto elem1, auto elem2) {return elem1 < elem2;});
for (auto elem : myClassVec)
		std::cout << elem.getX()<< std::endl;




	return 0;

}
