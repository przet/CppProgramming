#include <bitset>
bool shared_bits(long a, long b)
{
  constexpr size_t longBits = sizeof(long)*8;
  auto a_bitset = static_cast<std::bitset<longBits>>(a);
  auto b_bitset = static_cast<std::bitset<longBits>>(b);
  auto c = a_bitset & b_bitset;
  return c.count() > 1;
}
