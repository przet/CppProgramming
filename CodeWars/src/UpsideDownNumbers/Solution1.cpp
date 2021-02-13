#include <stack>
#include <unordered_map>
#include <queue>
struct CustomMap
{
    std::unordered_map<int,int> hashMap
    {
        {0, 0},
        {1, 1},
        {6, 9},
        {8, 8},
        {9, 6}
    };
  
    int operator [](int digit)
    {
        if (digit == 0 || digit == 1 || digit == 6 || digit == 8 || digit == 9)
            return hashMap[digit];
        else 
            return -1;
    }

};
void storeDigits(int x, std::queue<int>& queue, std::stack<int>& stack)
{
    int q = x;
    do 
    {
        stack.push(q%10);
        queue.push(q%10);
        q /= 10;
    } while (q);
}

int solve(int x, int y)
{
    auto result{ 0 };
    CustomMap customMap;
    while (x < y)
    {
        if (x / 10 == 0)
        {
            if (x == 0 || x == 1 || x == 8)
                ++result;
            ++x;
            continue;
        }
        std::queue<int> origDigitStore;
        std::stack<int> rotatedDigitStore;
        storeDigits(x, origDigitStore, rotatedDigitStore);
        auto count{ 0 };
        while (true)
        {
            if (origDigitStore.front() != customMap[rotatedDigitStore.top()])
                break;

            ++count;
            origDigitStore.pop();
            rotatedDigitStore.pop();
            if (!std::size(origDigitStore))
            {
                ++result;
                break;

            }
        }
        ++x;
    }
    return result;
}
