/* Find duplicates in O(n) time and O(1) extra space | Set 1

Given an array of n elements which contains elements from 0 to n-1, with any of these numbers appearing any number of times. Find these repeating numbers in O(n) and using only constant memory space.

For example, let n be 7 and array be {1, 2, 3, 1, 3, 6, 6}, the answer should be 1, 3 and 6.

Method 1 and Method 2 of the above link are not applicable as the question says O(n) time complexity and O(1) constant space. Also, Method 3 and Method 4 cannot be applied here because there can be more than 2 repeating elements in this problem. Method 5 can be extended to work for this problem. Below is the solution that is similar to the Method 5.

Algorithm:

traverse the list for i= 0 to n-1 elements
{
  check for sign of A[abs(A[i])] ;
  if positive then
     make it negative by   A[abs(A[i])]=-A[abs(A[i])];
  else  // i.e., A[abs(A[i])] is negative
     this   element (ith element of list) is a repetition

There is a problem in above approach. It prints the repeated number more than once. For example: {1, 6, 3, 1, 3, 6, 6} it will give output as : 1 3 6 6. In below set, another approach is discussed that prints repeating elements only once.
}*/

// C++ code to find 
// duplicates in O(n) time 
#include <bits/stdc++.h> 
using namespace std; 
  
// Function to print duplicates 
void printRepeating(int arr[], int size) 
{ 
    int i; 
    cout << "The repeating elements are:" << endl; 

    for (i = 0; i < size; i++) 
    { 
        if (arr[abs(arr[i])] >= 0) 
            arr[abs(arr[i])] = -arr[abs(arr[i])]; 
        else
            cout << abs(arr[i]) << " "; 
    } 
}

/* Duplicates in an array in O(n) and by using O(1) extra space | Set-2

Given an array of n elements which contains elements from 0 to n-1, with any of these numbers appearing any number of times. 
Find these repeating numbers in O(n) and using only constant memory space.

For example, let n be 7 and array be {1, 2, 3, 1, 3, 6, 6}, the answer should be 1, 3 and 6.
We have discussed an approach for this question in below post:
Duplicates in an array in O(n) and by using O(1) extra space | Set-2.
There is a problem in above approach. It prints the repeated number more than once. For example: {1, 6, 3, 1, 3, 6, 6} 
it will give output as : 3 6 6. So, in this article, another method is discussed to overcome this problem.

1- Traverse the given array from i= 0 to n-1 elements
     Go to index arr[i]%n and increment its value by n.
3- Now traverse the array again and print all those 
   indexes i for which arr[i]/n is greater than 1.

This approach works because all elements are in range
from 0 to n-1 and arr[i]/n would be greater than 1
only if a value "i" has appeared more than once. */

// function to find repeating elements 
void printRepeating( int arr[], int n) 
{ 
    // First check all the values that are 
    // present in an array then go to that 
    // values as indexes and increment by 
    // the size of array 
    for (int i = 0; i < n; i++) 
    { 
        int index = arr[i] % n; 
        arr[index] += n; 
    } 
  
    // Now check which value exists more 
    // than once by dividing with the size 
    // of array 
    for (int i = 0; i < n; i++) 
    { 
        if ((arr[i]/n) > 1) 
            cout << i << " "; 
    } 
} 
  
// Driver Code 
int main() 
{ 
    int arr[] = {1, 2, 3, 1, 3, 6, 6}; 
    int arr_size = sizeof(arr)/sizeof(arr[0]); 
    printRepeating(arr, arr_size); 
    return 0; 
} 
