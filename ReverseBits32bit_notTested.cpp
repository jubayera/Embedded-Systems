#include <iostream>
using namespace std;

typedef unsigned int uint32_t;

uint32_t reverseBits_Olgn(uint32_t n) {
        uint32_t x;
        for(unsigned int i = 31; n; ) {
            x |= (n & 1) << i;
            n >>= 1;
            -- i;
        }
        return x;
}

uint32_t reverseBits_O1(uint32_t n) {
        n = (n >> 1) & 0x55555555 | (n << 1) & 0xaaaaaaaa;
        n = (n >> 2) & 0x33333333 | (n << 2) & 0xcccccccc;
        n = (n >> 4) & 0x0f0f0f0f | (n << 4) & 0xf0f0f0f0;
        n = (n >> 8) & 0x00ff00ff | (n << 8) & 0xff00ff00;
        n = (n >> 16) & 0x0000ffff | (n << 16) & 0xffff0000;
        return n;
    }

// pre-calculated reverse results for up-to-2 bytes.
uint32_t map[65536];
 
uint32_t reverseBits(uint32_t n) {
    return (map[n & 0xFFFF] << 16) | map[n >> 16];
}

int main(int argc, char const *argv[])
{
    cout << reverseBits_Olgn(1) << endl;
    cout << reverseBits_Olgn(5) << endl;

    cout << reverseBits_O1(1) << endl;
    cout << reverseBits_O1(5) << endl;

    // compute the cache
    for (int i = 0; i <= 65535; ++i) {
        map[i] = reverseBits(i); 
    }

    cout << map[1] << map[5] << endl;
    /*
    2147483648
    3135429742
    */
    return 0;
}
    
