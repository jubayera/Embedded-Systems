/* 
Sort an array of 0s, 1s and 2s (Simple Counting)

Given an array A[] consisting 0s, 1s and 2s, write a function that sorts A[]. The functions should put all 0s first, then all 1s and all 2s in last.

Examples:

Input :  {0, 1, 2, 0, 1, 2}
Output : {0, 0, 1, 1, 2, 2}

Input :  {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1}
Output : {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2}

Count the number of 0’s, 1’s and 2’s. 
After Counting, put all 0’s first, then 1’s and lastly 2’s in the array. 
We traverse the array two times. Time complexity will be O(n).
Output:

0 0 0 0 0 1 1 1 1 1 2 2

Problems with above solution.
1) It requires two traversals of array.
2) This solution may not work if values are a part of structure. 
For example, consider a situation where 0 represents Computer Science Stream, 
1 represents Electronics and 2 represents Mechanical. 
We have a list of student objects (or structures) and we want to sort them. 
We cannot use above sort as we simply put 0s, 1s and 2s one by one.
*/
#include <iostream>
using namespace std;

void sort012(int* arr, int n)
{
    //Variables to maintain the count of 0's, 1's and 2's in the array
    int count0 = 0, count1 = 0, count2 = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] == 0)
            count0++;
        if(arr[i] == 1)
            count1++;
        if(arr[i] == 2)
            count2++;
    }

    //Putting the 0's in the array in starting.
    for(int i = 0; i < count0; i++)
        arr[i] = 0;

    //Putting the 1's in the array after the 0's
    for(int i = count0; i < (count0 + count1); i++)
        arr[i] = 1;

    //Putting the 2's in the array after the 1's
    for(int i = (count0 + count1); i < n; i++)
        arr[i] = 2;

    return;
}

//print the array function
void printArray(int* arr, int n)
{
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort012(arr, n);
    printArray(arr, n);
    return 0;
}
