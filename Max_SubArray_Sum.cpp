/* Largest Sum Contiguous Subarray. Write an efficient program to find the sum of contiguous subarray within a one-dimensional array of numbers which has the largest sum. 
Kadane’s Algorithm:

Initialize:
    max_so_far = 0
    max_ending_here = 0

Loop for each element of the array
  (a) max_ending_here = max_ending_here + a[i]
  (b) if(max_ending_here < 0)
            max_ending_here = 0
  (c) if(max_so_far < max_ending_here)
            max_so_far = max_ending_here
return max_so_far

Simple idea of the Kadane’s algorithm is to look for all positive contiguous segments of the array (max_ending_here is used for this). And keep track of maximum sum contiguous segment among all positive segments (max_so_far is used for this). Each time we get a positive sum compare it with max_so_far and update max_so_far if it is greater than max_so_far

    Lets take the example:
    {-2, -3, 4, -1, -2, 1, 5, -3}

    max_so_far = max_ending_here = 0

    for i=0,  a[0] =  -2
    max_ending_here = max_ending_here + (-2)
    Set max_ending_here = 0 because max_ending_here < 0

    for i=1,  a[1] =  -3
    max_ending_here = max_ending_here + (-3)
    Set max_ending_here = 0 because max_ending_here < 0

    for i=2,  a[2] =  4
    max_ending_here = max_ending_here + (4)
    max_ending_here = 4
    max_so_far is updated to 4 because max_ending_here greater 
    than max_so_far which was 0 till now

    for i=3,  a[3] =  -1
    max_ending_here = max_ending_here + (-1)
    max_ending_here = 3

    for i=4,  a[4] =  -2
    max_ending_here = max_ending_here + (-2)
    max_ending_here = 1

    for i=5,  a[5] =  1
    max_ending_here = max_ending_here + (1)
    max_ending_here = 2

    for i=6,  a[6] =  5
    max_ending_here = max_ending_here + (5)
    max_ending_here = 7
    max_so_far is updated to 7 because max_ending_here is 
    greater than max_so_far

    for i=7,  a[7] =  -3
    max_ending_here = max_ending_here + (-3)
    max_ending_here = 4
*/
//C++ program to print largest contiguous array sum
#include <iostream>
#include <climits>
using namespace std;

//To print the subarray with the maximum sum, we maintain indices whenever we get the maximum sum
int maxSubArraySum_trivial(int a[], int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0;

    int start = 0, end = 0, s = 0;

    for(int i = 0; i < size; i++)
    {
        max_ending_here += a[i];

        if(max_ending_here < 0) 
        {
            max_ending_here = 0;
            s = i + 1; //move the start index of max sum subarray to the next index
        }

        else if(max_ending_here > max_so_far) /* Do not compare for all elements. Compare only when max_ending_here > 0*/
        {
            max_so_far = max_ending_here;
            start = s; //update start and end indices
            end = i;
        }
        
    }

    cout << "Maximum contiguous sum found at Starting index: " << start << " Ending index: " << end << endl;

    return max_so_far;
}

/* Dynamic programming - O(n). The implementation handles the case when all numbers in array are negative */
int maxSubArraySum_DP(int a[], int size)
{
    int max_so_far = a[0];
    int curr_max = a[0];

    for(int i = 1; i < size; i++)
    {
        curr_max = max(a[i], curr_max + a[i]);
        max_so_far = max(max_so_far, curr_max);
    }

    return max_so_far;
}

int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSubArraySum_trivial(a, n);
    cout << "Maximum contiguous sum using trivial approach is " << max_sum;
    
    max_sum = maxSubArraySum_DP(a, n);
    cout << "\nMaximum contiguous sum using kinda DP approach is " << max_sum << endl;

    return 0;
}
