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

int main(int argc, char const *argv[])
{
  cout << 5 << " has " << CountBits(5) << " number of 1s" << endl;
  cout << 4 << " has " << CountBits(4) << " number of 1s" << endl;
  cout << 15 << " has " << CountBits(15) << " number of 1s" << endl;
  cout << 25 << " has " << CountBits(25) << " number of 1s" << endl;
  return 0;
}

/*
5 has 2 number of 1s
4 has 1 number of 1s
15 has 4 number of 1s
25 has 3 number of 1s
*/
