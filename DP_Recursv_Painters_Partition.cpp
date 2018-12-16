/* The painter's partition problem 
is to paint n boards of length {A1, A2, ..., An}. There are k painters available and 
each takes 1 unit time to paint 1 unit of board. The problem is to find the minimum time to get 
this job done under the constraints that any painter will only paint continuous sections of
boards, say board {2,3,4} or only board {1} or nothing but not board {2,4,5}.

Input : k = 2, A = {10, 10, 10, 10} 
Output : 20.
Here we can divide the boards into 2 equal sized partitions, so each painter 
gets 20 units of board and the total time taken is 20. 

Input : k = 2, A = {10, 20, 30, 40} 
Output : 60.
Here we can divide first 3 boards for one painter and the last board for second painter.

From the above examples, it is obvious that the strategy of dividing the boards into 
k equal partitions won’t work for all the cases. We can observe that the problem can 
be broken down into: Given an array A of non-negative integers and 
a positive integer k, we have to divide A into k of fewer partitions 
such that the maximum sum of the elements in a partition, overall partitions is minimized. 
So for the second example above, possible divisions are:
* One partition: so time is 100.
* Two partitions: (10) & (20, 30, 40), so time is 90. 
Similarly we can put the first divider after 20 (=> time 70) 
or 30 (=> time 60); so this means the minimum time: (100, 90, 70, 60) is 60. 
A brute force solution is to consider all possible set of contiguous partitions 
and calculate the maximum sum partition in each case and return the minimum of 
all these cases.

1) Optimal Substructure:
We can implement the naive solution using recursion with the following optimal 
substructure property:
Assuming that we already have k-1 partitions in place (using k-2 dividers), 
we now have to put the k-1 th divider to get k partitions.

We can put the k-1 th divider between the i th and i+1 th element where i = 1 to n. 
Please note that putting it before the first element is the same as putting it after 
the last element.

The total cost of this arrangement can be calculated as the maximum of the following:
a) The cost of the last partition: sum(Ai..An), where the k-1 th divider is
before element i.
b) The maximum cost of any partition already formed to the left of the k-1 th divider.

Here a) can be found out using a simple helper function to calculate sum
of elements between two indices in the array. How to find out b) ?
We can observe that b) actually is to place the k-2 separators as fairly as
possible, so it is a subproblem of the given problem. Thus we can write the optimal
substructure property as the following recurrence relation:

    T(n,k) = min{max(i=1 to n){T(i,k-1), sum(j=i+1 to n Aj)}}
    The base case are:   T(1,k) = A1    T(n,1)=sum(i=1 to n Ai)
*/

#include <climits>
#include <iostream>
using namespace std;

//function to calculate sum between two indices in array
int sum(int arr[], int from, int to)
{
    int total = 0;
    for(int i = from; i <= to; i++)
        total += arr[i];
    return total;
}

//for n boards and k partitions, Time complexity: exponential.
int partition_recursive(int arr[], int n, int k)
{
    //base cases
    if(k == 1) //one partition
        return sum(arr, 0, n-1);
    if(n == 1) //one board
        return arr[0];

    int best = INT_MAX;

    /* find minimum of all possible maximum k-1 partitions to the left of arr[i],
    with i elements, put k-1 th divider between arr[i-1] & arr[i] to get k-th partition.
    */
   for(int i = 1; i <= n; i++)
        best = min(best, max(partition_recursive(arr, i, k-1), sum(arr, i, n-1)));
    
    return best;
}

/*
The time complexity of the above solution is exponential.

2) Overlapping subproblems:
Following is the partial recursion tree for T(4, 3) in above equation.

      T(4, 3)
     /    /    \ ..         
T(1, 2)  T(2, 2) T(3, 2) 
          /..      /..     
      T(1, 1)    T(1, 1) 

We can observe that many subproblems like T(1, 1) in the above problem are being solved 
again and again. Because of these two properties of this problem, 
we can solve it using dynamic programming, either by top down memoized method 
or bottom up tabular method. Following is the bottom up tabular implementation:
*/
//bootom up tabular DP
int findMax(int arr[], int n, int k)
{
    //initialize table
    int dp[k+1][n+1] = {0};

    //base cases
    //k=1
    for(int i = 1; i <= n; i++)
        dp[1][i] = sum(arr, 0, i-1);

    //n=1
    for(int i = 1; i <= k; i++)
        dp[i][1] = arr[0];

    //2 to k partitions
    for(int i = 2; i <= k; i++) // 2 to n boards
    {
        for(int j = 2; j <= n; j++)
        {
            //track minimum
            int best = INT_MAX;

            //i-1 th separator before position arr[p=1..j]
            for(int p = 1; p <= j; p++)
            {
                best = min(best, max(dp[i - 1][p], sum(arr, p, j-1)));
            }

            dp[i][j] = best;
        }
    }

    //required
    return dp[k][n];
}

int main()
{
    int arr[] = {10, 20, 60, 50, 30, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    cout << "Using recursion: " << partition_recursive(arr, n, k) << endl;

    cout << "Using DP: " << findMax(arr, n, k) << endl;
    return 0;
}
