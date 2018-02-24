#ifndef SORTING_H
#define SORTING_H
class MyClass
{
	private:
		int x;
	public:
		void setX(int);
		int getX();
		bool operator<(const MyClass&);

};
bool MyClass::operator<(const MyClass &myclass2)
{
	return x < myclass2.x;
}
void MyClass::setX(int a)
{
	x = a;
}
int MyClass::getX()
{
	return x;
}
#endif
