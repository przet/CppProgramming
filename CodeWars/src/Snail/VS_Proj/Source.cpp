#include <iostream>
#include <vector>
#include <assert.h>

void snail(
    const std::vector<std::vector<int>>& snail_map,
    std::vector<int>& result,
    int topRow,
    int rightColumn,
    int bottomRow,
    int leftColumn,
    int n)
{
    
    if (topRow > bottomRow)
        return;

    for (int i = leftColumn; i <= rightColumn; ++i)
        result.push_back(snail_map[topRow][i]);

    for (int i = topRow + 1; i <= bottomRow; ++i)
        result.push_back(snail_map[i][rightColumn]);

    for (int i = rightColumn - 1; i >= leftColumn; --i)
        result.push_back(snail_map[bottomRow][i]);

    for (int i = bottomRow - 1; i >= leftColumn + 1 ; --i)
         result.push_back(snail_map[i][leftColumn]);
    

    snail(
        snail_map,
        result,
        topRow + 1,
        rightColumn - 1,
        bottomRow - 1,
        leftColumn + 1,
        n-1);
   
}
std::vector<int> snail(const std::vector<std::vector<int>> &snail_map)
{
    const size_t mapSize = snail_map.size();
    std::vector<int> result;

    if (mapSize == 1)
        return !snail_map[0].size() ?
        result : std::vector<int>{ snail_map[0][0] };
    
    snail(
        snail_map,
        result,
        0,
        mapSize - 1,
        mapSize - 1,
        0,
        mapSize);

    return result;
}
int main()
{
    
    std::vector<std::vector<int>> v = {{1,2,3}, {8,9,4}, {7,6,5}};
    std::vector<int> expected = {1,2,3,4,5,6,7,8,9};
    assert(snail(v) == expected);

    auto res = snail(v);
    for (auto elem : res)
        std::cout << elem << ", ";

    v = {{1,2,3,4}, {12,13,14,5}, {11,16,15,6}, {10,9,8,7}};
    expected = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    assert(snail(v) == expected);

      v = {{1,2}, {4,3}};
    expected = {1,2,3,4};
    assert(snail(v) == expected);

    
    v = {{}};
    expected = {};
    assert(snail(v) == expected);
    
    v = {{1}};
    expected = {1};
    assert(snail(v) == expected);



    return 0;
}