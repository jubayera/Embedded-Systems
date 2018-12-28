/* The time complexity of the above implementation is exponential (golden ratio raised to power n). It can be optimized to work in O(Logn) time using the previously discussed Fibonacci function optimizations.

Generalization of the above problem
How to count number of ways if the person can climb up to m stairs for a given value m? For example if m is 4, the person can climb 1 stair or 2 stairs or 3 stairs or 4 stairs at a time.

We can write the recurrence as following.

   ways(n, m) = ways(n-1, m) + ways(n-2, m) + ... ways(n-m, m) 

Following is the implementation of above recurrence.*/
// A C program to count number of ways to reach n't stair when 
// a person can climb either 1 or 2 stairs at a time 
#include<stdio.h> 
  
// A recursive function used by countWays 
int countWaysUtil(int n, int m) 
{ 
    if (n <= 1) 
        return n; 
    int res = 0; 
    for (int i = 1; i<=m && i<=n; i++) 
        res += countWaysUtil(n-i, m); 
    return res; 
} 
  
// Returns number of ways to reach s'th stair 
int countWays(int s, int m) 
{ 
    return countWaysUtil(s+1, m); 
} 
  
// Driver program to test above functions- 
int main () 
{ 
    int s = 4, m = 2; 
    printf("Nuber of ways = %d", countWays(s, m)); 
    return 0; 
} 
