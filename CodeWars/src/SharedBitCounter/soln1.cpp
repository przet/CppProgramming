#include <cmath>
bool shared_bits(long a, long b)
{
  long c = a & b;
  if (c == 0)
    return false;
  double intpart;
  double fracpart = modf(log2(c), &intpart);
  return !(fracpart == 0);
}
