void func1()
{
    int* ptr = new int(4);
    int* ptr2 = new int(5);
    //int* ptr3 = new int(6);
    delete ptr;
    delete ptr2;
    //delete ptr3;
}

int main()
{
    int a = 5;
    func1();

    return 0;
}