void func1()
{
    int* ptr = new int[100000000];
    int* ptr2 = new int[100000000];
    int* ptr3 = new int[100000000];
    delete[] ptr;
    //delete ptr3;
}

int main()
{
    int a = 5;
    func1();

    return 0;
}