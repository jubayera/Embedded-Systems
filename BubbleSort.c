//reorder a one-dimensional integer array from smallest to largest
#include <stdio.h>
#define SIZE 100
void reorder(int n, int x[]);

void main()
{
    int i, n, x[SIZE];

    //read in a value for n
    scanf("%d", &n);

    //read in the list of numbers
    for(i = 0; i < n; i++) 
        scanf("%d", &x[i]);

    //reorder all array elements
    reorder(n, x);

    //Reordered list of numbers
    for(i = 0; i < n; i++)
        printf("i = %d   x = %d\n", i+1, x[i]);
}

void reorder(int n, int x[]) //rearrange the list of numbers
{
    int i, item, temp;

    for(item = 0; item < n-1; ++item)
        //find the smallest of all remaining elements
        for(i = item + 1; i < n; ++i)
            if(x[i] < x[item]) {
                //interchange the two elements
                temp = x[item];
                x[item] = x[i];
                x[i] = temp;
            }
}
