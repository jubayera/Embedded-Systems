/*  extract the digits of given binary number starting from right most digit and 
keep a variable dec_value. At the time of extracting digits from the binary number, 
multiply the digit with the proper base (Power of 2) and add it to the variable dec_value.
At the end, the variable dec_value will store the required decimal number.

For Example:
If the binary number is 111.
dec_value = 1*(2^2) + 1*(2^1) + 1*(2^0) = 7
*/
//C++ program to convert binary to decimal
#include <iostream>
using namespace std;

//function to convert binary to decimal
//The program works only with binary numbers in the range of integers. 
int binaryToDecimal(int n)
{
    int num = n;
    int dec_value = 0;

    //Initialize base value to 1, i.e., 2^0
    int base = 1;

    int temp = num;
    while(temp)
    {
        int last_digit = temp % 10;
        temp = temp / 10;

        dec_value += last_digit * base;

        base = base * 2;
    }

    return dec_value;
}

/*
 to work with long binary numbers like 20 bits or 30 bit, you can use string variable to store the binary numbers.

Below is a similar program which uses string variable instead of integers to store binary value:
*/
long long binaryStrToDecimal(string n)
{
    string num = n;
    long long dec_value = 0;

    //Initialize base value to 1, i.e. 2^0
    int base = 1;

    int len = num.length();

    for(int i = len-1; i >= 0; i--)
    {
        if(num[i] == '1')
            dec_value += base;

        base *= 2;
    }

    return dec_value;
}

int main(int argc, char const *argv[])
{
    int num = 1011010;

    cout << binaryToDecimal(num) << endl;

    string num_str = "1000000111101011";

    cout << binaryStrToDecimal(num_str) << endl;
    
    return 0;
}
