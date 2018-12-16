/* Program to count the number of bits that are set to 1 in a nonnegative integer.
*/
#include <iostream>

using namespace std;

/* tests bits one-at-a-time starting with the least-significant bit. It illustrates shifting
and masking; it also shows how to avoid hard-coding the size of the integer word.
*/
short CountBits(unsigned int x) 
{
  short num_bits = 0;

  while (x) 
  {
    num_bits += x & 1;
    x >>= 1;
  }

  return num_bits;
}

/* Parity of a binary word is 1 if the number of 1s in the word is odd; otherwise, it is 0. Parity checks are used to detect
single bit errors. Computing parity of a single 64-bit word.
Iteratitvely tests the value of each bit while tracking the number of 1s seen so far. Since we only care if the number of 1s
is even or odd, we can store the number mod 2. The complexity if O(n), where n is the word size.
*/
short Parity(unsigned long x)
{
    short result = 0;

    while(x)
    {
        result ^= (x & 1);
        x >>= 1;
    }

    return result;
}

int main(int argc, char const *argv[])
{
  cout << 35 << " has " << CountBits(35) << " number of 1s" << endl;
  cout << 44 << " has " << CountBits(44) << " number of 1s" << endl;
  cout << 15 << " has " << Parity(15) << " parity" << endl;
  cout << 25 << " has " << Parity(25) << " parity" << endl;
  return 0;
}

/*
5 has 2 number of 1s
4 has 1 number of 1s
15 has 4 number of 1s
25 has 3 number of 1s
*/
