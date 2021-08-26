#include<vector>

std::vector<unsigned long long> partsSum(const std::vector<unsigned long long>& ls)
{
    size_t ls_size = std::size(ls);
    std::vector<unsigned long long> result(ls_size + 1,0);
    result[ls_size] = 0;
    int i = ls_size - 1 ;
    while (i >=0)
    {
        result[i] = ls[i] + result[i+1];
        i--;
    }
    return result;
    
}
