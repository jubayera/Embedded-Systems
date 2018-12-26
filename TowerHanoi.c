//The Towers of Hanoi - solved using recursion
#include <stdio.h>

void transfer(int n, char from, char to, char temp);

int main(int argc, char const *argv[])
{
    int n;
    printf("How many disks? ");
    scanf("%d", &n);

    transfer(n, 'L', 'R', 'C');

    return 0;
}

void transfer(int n, char from, char to, char temp)
/*
    transfer n disks from one pole to another
    n = number of disks
    from = origin
    to = destination
    temp = temporary storage
*/
{
    if(n > 0) {
        //move n-1 disks from origin to temporary
        transfer(n-1, from, temp, to);

        //move the nth disk from origin to destination
        printf("Move disk %d from %c to %c\n", n, from, to);

        //move n-1 disks from temporary to destination
        transfer(n-1, temp, to, from);
    }
    
}
