/* 
Reverse bits using lookup table in O(1) time

Given an unsigned integer, reverse all bits of it and return the number with reversed bits.

Examples:

Input : n = 1
Output : 2147483648  
On a machine with size of unsigned
bit as 32. Reverse of 0....001 is
100....0.

Input : n = 2147483648
Output : 1       

Here we solve this problem in O(1) time using lookup table. It’s hard to reverse all 32 bits (assuming this as size of int) in one go using lookup table (” because it’s infeasible to create lookup table of size 232-1 “). So we break 32 bits into 8 bits of chunks( lookup table of size 28-1 “0-255”).

Lookup Table
in lookup tale we will store reverse of every number that are in a range( 0-255)

LookupTable[0] = 0 | binary 00000000 Reverse 00000000
LookupTable[1] = 128 | binary 00000001 reverse 10000000
LookupTable[2] = 64 | binary 00000010 reverse 01000000
LookupTanle[3] = 192 | binary 00000011 reverse 11000000
LookupTable[4] = 32 | binary 00000100 reverse 00100000
and so on… upto lookuptable[255].

Let’s take an Example How lookup table work.
let number = 12456
in Binary = 00000000000000000011000010101000

Split it into 8 bits chunks  :  00000000 | 00000000 | 00110000 | 10101000
         in decimal          :     0          0          48       168
reverse each chunks using lookup table :
Lookuptable[ 0 ] = 0  | in binary 00000000
Lookuptable[48 ] = 12 | in binary 00001100
Lookuptable[168] = 21 | in binary 00010101
 
Now Binary :  
00000000 | 00000000 | 00001100 | 00010101

Binary chunks after rearrangement : 
00010101 | 00001100 | 00000000 | 00000000   
  
Reverse of 12456 is 353107968  

*/

// CPP program to reverse bits using lookup table. 
#include<bits/stdc++.h> 
using namespace std; 
   
// Generate a lookup table for 32bit operating system  
// using macro  
#define R2(n)     n,     n + 2*64,     n + 1*64,     n + 3*64 
#define R4(n) R2(n), R2(n + 2*16), R2(n + 1*16), R2(n + 3*16) 
#define R6(n) R4(n), R4(n + 2*4 ), R4(n + 1*4 ), R4(n + 3*4 ) 
  
// Lookup table that store the reverse of each table 
unsigned int lookuptable[256] = { R6(0), R6(2), R6(1), R6(3) }; 
  
/* Function to reverse bits of num */
int reverseBits(unsigned int num) 
{ 
    int reverse_num = 0; 
  
     // Reverse and then rearrange  
  
     // first chunk of 8 bits from right 
     reverse_num = lookuptable[ num & 0xff ]<<24 |  
  
                   // second chunk of 8 bits from  right  
                   lookuptable[ (num >> 8) & 0xff ]<<16 |  
  
                   lookuptable[ (num >> 16 )& 0xff ]<< 8 | 
                   lookuptable[ (num >>24 ) & 0xff ] ; 
    
    return reverse_num; 
} 
  
//driver program to test above function  
int main() 
{ 
    int x = 12456;  
    printf("%u", reverseBits(x));     
    return 0; 
}  
