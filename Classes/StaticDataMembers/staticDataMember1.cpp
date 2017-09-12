#include <iostream>

class Widget
{ 	
	public: 
		Widget () { ++count;}
		~Widget() { --count;}
		int numWidgets(){ return count; }
	private:
		static int count;
};

//Global definition of static data membe
int Widget::count = 0; //Is this not zero always as a) it is global and b) it is static? Read Schaums,
// he mentions it on the first page of this topic!

// By the way I am pretty sure it is needed to specify count, as the constructor uses count straight away

//Program
int main()
{
	Widget x, w;
	if (w.numWidgets() != 1) 
			std::cout << "\nThere are " << w.numWidgets() << " widgets. \n\n";
	else
			std::cout << "\nThere is " << w.numWidgets() << " widget. \n\n";


}

	





