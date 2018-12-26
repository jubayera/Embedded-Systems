#include <stdio.h>
long int factorial(int n);

#define EOLN '\n'

void reverse(void);

int main(int argc, char const *argv[])
{
    int n;
    long int factorial(int n);

    //read in the integer quantity
    scanf("%d", &n);

    printf("n! = %ld\n", factorial(n));
   
    printf("\n\nPlease enter a line of text below\n");
    reverse();

    return 0;
}

long int factorial(int n) //calculate the factorial
{
    if(n <= 1)
        return(1);
    else
        return(n * factorial(n-1));
}

void reverse(void)
//read a line of characters and write it out backwards
{
    char c;
    if((c = getchar()) != EOLN)
        reverse();

    putchar(c);
}
