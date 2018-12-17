/*

Write an Efficient C Program to Reverse Bits of a Number

Given an unsigned integer, reverse all bits of it and return the number with reversed bits.

Input : n = 1
Output : 2147483648  
On a machine with size of unsigned
bit as 32. Reverse of 0....001 is
100....0.

Input : n = 2147483648
Output : 1                          
Method1 – Simple
Loop through all the bits of an integer. If a bit at ith position is set in the i/p no,
then set the bit at (NO_OF_BITS – 1) – i in o/p. Where NO_OF_BITS is number of bits present in the given number.
*/
#include <stdio.h>

unsigned int ReverseBits_On(unsigned int num)
{
    unsigned int NO_OF_BITS = sizeof(num) * 8;

    unsigned int reverse_num = 0, i, temp;

    for(i = 0; i < NO_OF_BITS; i++)
    {
        temp = (num & (1 << i));
        if(temp)
            reverse_num |= (1 << ((NO_OF_BITS-1) - i));
    }

    return reverse_num;
}

/* The idea is to keep putting set bits of the num in reverse_num until num becomes zero. 
After num becomes zero, shift the remaining bits of reverse_num.
Let num is stored using 8 bits and num be 00000110. After the loop you will get reverse_num as 00000011. 
Now you need to left shift reverse_num 5 more times and you get the exact reverse 01100000.
*/
unsigned int ReverseBits_Olgn(unsigned int num)
{
	unsigned int count = sizeof(num) * 8 - 1; 
	unsigned int reverse_num = num; 
	
	num >>= 1; 
	while(num) 
	{ 
	    reverse_num <<= 1;	 
	    reverse_num |= num & 1; 
	    num >>= 1; 
	    count--; 
	} 
	reverse_num <<= count; 
	return reverse_num;  
}

int main(int argc, char const *argv[])
{
    unsigned int x = 2;
    printf("%u\n", ReverseBits_On(x));
    printf("%u\n", ReverseBits_Olgn(x));
    return 0;
}
