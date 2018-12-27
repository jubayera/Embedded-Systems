//sort a list of strings alphabetically using a two-dimensional character array
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reorder(int n, char x[][12]); 

void main()
{
    int i, n = 0;
    char x[10][12];

    //read in the list of strings until END is entered
    do {
        scanf("%s", x[n]);
    } while(strcmp(x[n++], "END"));

    //adjust the value of n
    n--;

    //reorder the list of strings
    reorder(n, x);

    for(i = 0; i < n; ++i)
        printf("\nstring %d: %s", i+1, x[i]);
}

void reorder(int n, char x[][12]) //rearrange the list of strings
{
    char temp[12];
    int i, item;

    for(item = 0; item < n - 1; ++item)
        for(i = item + 1; i < n; ++i)
            if(strcmp(x[item], x[i]) > 0)
            {
                //interchange the two strings
                strcpy(temp, x[item]);
                strcpy(x[item], x[i]);
                strcpy(x[i], temp);
            }
}
