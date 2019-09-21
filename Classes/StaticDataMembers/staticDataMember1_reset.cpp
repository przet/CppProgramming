#include <iostream>
#include <vector>
#include <assert.h>

// Reset static members.
// Use case : when you need a static member, e.g templated members
// but you want to reset each construction
class Widget
{ 	
	public: 
		Widget (int n) { vec.push_back(n); }
		~Widget() { vec.clear();}
                const std::vector<int>& Vec() const{ return vec; } 
	private:
		static std::vector<int> vec;
};

class Widget_1
{ 	
	public: 
		Widget_1 (int n) { vec.push_back(n); }
		~Widget_1() { vec.clear();}
                const std::vector<int>& Vec() const{ return vec; } 
	private:
		static std::vector<int> vec;
};

std::vector<int >Widget::vec = {};
std::vector<int >Widget_1::vec = {};

//Program
int main(int argc , char** argv)
{
	Widget w(1), x(2), y(3), z(4);
        assert(w.Vec().size() == 4);
        w.~w();
        assert(w.Vec().size() == 0);

        for (int n = 1; n < 5;)
        {
            Widget_1 w(n);
            assert(w.Vec().size() == 1);
            assert(w.Vec()[0] == n++);
        }



}

	





