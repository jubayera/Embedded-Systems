/*
Cutting a Rod | DP-13

Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. 
Determine the maximum value obtainable by cutting up the rod and selling the pieces. 
For example, if length of the rod is 8 and the values of different pieces are given as following, 
then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6)

length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 1   5   8   9  10  17  17  20

And if the prices are as following, then the maximum obtainable value is 24 (by cutting in eight pieces of length 1)

length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 3   5   8   9  10  17  17  20

A naive solution for this problem is to generate all configurations of different pieces and find the highest priced configuration. This solution is exponential in term of time complexity. Let us see how this problem possesses both important properties of a Dynamic Programming (DP) Problem and can efficiently solved using Dynamic Programming.

1) Optimal Substructure:
We can get the best price by making a cut at different positions and comparing the values obtained after a cut. We can recursively call the same function for a piece obtained after a cut.

Let cutRod(n) be the required (best possible price) value for a rod of length n. cutRod(n) can be written as following.

cutRod(n) = max(price[i] + cutRod(n-i-1)) for all i in {0, 1 .. n-1}

2) Overlapping Subproblems
Following is simple recursive implementation of the Rod Cutting problem. 
The implementation simply follows the recursive structure mentioned above.*/

// A Naive recursive solution for Rod cutting problem 
#include<stdio.h> 
#include<limits.h> 
  
// A utility function to get the maximum of two integers 
int max(int a, int b) { return (a > b)? a : b;} 
  
/* Returns the best obtainable price for a rod of length n and 
   price[] as prices of different pieces */
int cutRod(int price[], int n) 
{ 
   if (n <= 0) 
     return 0; 
   int max_val = INT_MIN; 
  
   // Recursively cut the rod in different pieces and compare different  
   // configurations 
   for (int i = 0; i<n; i++) 
         max_val = max(max_val, price[i] + cutRod(price, n-i-1)); 
  
   return max_val; 
} 
  
/* Driver program to test above functions */
int main() 
{ 
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20}; 
    int size = sizeof(arr)/sizeof(arr[0]); 
    printf("Maximum Obtainable Value is %dn", cutRod(arr, size)); 
    return 0; 
} 
