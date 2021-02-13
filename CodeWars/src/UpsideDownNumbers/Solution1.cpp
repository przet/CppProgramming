#include <stack>
#include <unordered_map>
#include <queue>
struct RotationMap 
{
    std::unordered_map<int, int> hashMap
    {
        {0, 0},
        {1, 1},
        {6, 9},
        {8, 8},
        {9, 6}
    };

    int operator [](int digit)
    {
        return hashMap.find(digit) != std::end(hashMap) ? hashMap[digit] : -1;
    }

};

struct DigitStore
{
    DigitStore(int x)
    {
        int q = x;
        do
        {
            origDigitStore.push(q % 10);
            reverseDigitStore.push(q % 10);
            q /= 10;
        } while (q);

        if (std::size(origDigitStore) != std::size(reverseDigitStore))
            throw std::logic_error("Both internal digits store are to be the same size");

    }
    int nextOrigDigit() { return origDigitStore.front(); }

    int nextReverseDigit() { return reverseDigitStore.top(); }

    void pop() { origDigitStore.pop(); reverseDigitStore.pop(); }

    int size() { return origDigitStore.size(); }

    bool empty() { return !size(); }

    std::queue<int> origDigitStore;
    std::stack<int> reverseDigitStore;
};

bool singleDigit(int x) { return !x / 10; }

int solve(int x, int y)
{
    auto result{ 0 };
    RotationMap vRotationMap;
    while (x < y)
    {
        if (singleDigit(x))
        {
            if (x == 0 || x == 1 || x == 8)
                ++result;
            ++x;
            continue;
        }
        DigitStore vDigitStore(x);
        while (true)
        {
            if (vDigitStore.nextOrigDigit() != vRotationMap[vDigitStore.nextReverseDigit()])
                break;

            vDigitStore.pop();
            if (vDigitStore.empty())
            {
                ++result;
                break;
            }
        }
        ++x;
    }
    return result;
}
