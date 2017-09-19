#include <iostream>
// extenstion of staticDataMember.cpp to use static function members

class Widget
{ 	
	public: 
		Widget () { ++count;}
		~Widget() { --count;}
		static int numWidgets(){ return count; }
	private:
		static int count;
};

int Widget::count = 0;

//Program
int main(int argc , char** argv)
{
    //No object created
    std::cout << "\nThere are " << Widget::numWidgets() << " widgets.\n\n";
    
    Widget w;
    std::cout << "\nThere are " << Widget::numWidgets() << " widgets.\n\n";
    // Using the objects function should not work...yet it does...
    std::cout << "\nThere is " << w.numWidgets() << " widget. \n\n";

}

