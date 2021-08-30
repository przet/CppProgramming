#include <cmath>
class ASum
{
  public:
  static long long findNb(long long m);
};

long long ASum::findNb(long long m)
{
    std::cout << "m is : " << m << std::endl;
    long long count = 1;
    long long origM = m;
    while (m - (long long)pow(count,3) != (long long)pow(count + 1,3) )
    {
        if (m - (long long)pow(count,3) < 1 )
            return -1;
        m  = m - (long long)pow(count,3);
        ++count;
    }
    return count + 1;
        
    
}
