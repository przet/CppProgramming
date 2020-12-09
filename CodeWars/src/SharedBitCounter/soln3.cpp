#include <cmath>
bool shared_bits(long a, long b)
{
  long c = a & b;
  if (c == 0)
    return false;
  
    return !(static_cast<long double>(c) - pow(2, static_cast<int>(log2(c))) == 0);
}
