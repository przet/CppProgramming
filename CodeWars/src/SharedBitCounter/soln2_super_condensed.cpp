#include <bitset>
bool shared_bits(long a, long b)
{
  return std::bitset<sizeof(long)*8>(a&b).count() > 1  ;
}
