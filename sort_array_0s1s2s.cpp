/* 
Sort an array of 0s, 1s and 2s

Given an array A[] consisting 0s, 1s and 2s, write a function that sorts A[]. 
The functions should put all 0s first, then all 1s and all 2s in last.
Examples:

Input :  {0, 1, 2, 0, 1, 2}
Output : {0, 0, 1, 1, 2, 2}

Input :  {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1}
Output : {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2}

Dutch national flag problem.

The problem was posed with three colours, here `0′, `1′ and `2′. 
The array is divided into four sections:

    a[1..Lo-1] zeroes (red)
    a[Lo..Mid-1] ones (white)
    a[Mid..Hi] unknown
    a[Hi+1..N] twos (blue)

The unknown region is shrunk while maintaining these conditions

        1. Lo := 1; Mid := 1; Hi := N;
        2. while Mid <= Hi do
            2.1. Invariant: a[1..Lo-1]=0 and a[Lo..Mid-1]=1 and a[Hi+1..N]=2; 
                        a[Mid..Hi] are unknown.
            2.2. case a[Mid] in
                0: swap a[Lo] and a[Mid]; Lo++; Mid++
                1: Mid++
                2: swap a[Mid] and a[Hi]; Hi–-

    — Dutch National Flag Algorithm, or 3-way Partitioning — 

Part way through the process, some red, white and blue elements are known and are in the 
“right” place. The section of unknown elements, a[Mid..Hi], is shrunk by examining a[Mid]:

            0 0 0 1 1 1 ? ? ? ? 2 2 2
                  |     |     |
                 low   mid   high
Examine a[Mid]. There are three possibilities: 
a[Mid] is (0) red, (1) white or (2) blue.

Case (0) a[Mid] is red, swap a[Lo] and a[Mid]; Lo++; Mid++

            0 0 0 0 1 1 1 ? ? ? 2 2 2
                    |     |   |
                   low   mid  high

Case (1) a[Mid] is white, Mid++

Case (2) a[Mid] is blue, swap a[Mid] and a[Hi]; Hi--

Continue until Mid>Hi. 
*/
//C program to sort an array with 0, 1 and 2 in a single pass
#include <stdio.h>
//Function to swap *a and *b
void swap(int *a, int *b);

/* Sort the input array, the array is assumed to have values in {0, 1, 2} */
void sort012(int a[], int arr_size)
{
    int low = 0;
    int high = arr_size - 1;
    int middle = 0;

    while(middle <= high)
    {
        switch(a[middle])
        {
            case 0:
                swap(&a[low++], &a[middle++]);
                break;
            case 1:
                middle++;
                break;
            case 2:
                swap(&a[middle], &a[high--]);
                break;
        }
    }
}

//function to swap
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//print array
void printArray(int arr[], int arr_size)
{
    for(int i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    sort012(arr, arr_size);

    printf("array after segregation: ");
    printArray(arr, arr_size);
    
    return 0;
}
