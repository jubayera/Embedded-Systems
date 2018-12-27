/* 
Maximum Subarray Sum using Divide and Conquer algorithm
You are given a one dimensional array that may contain both positive and negative integers, find the sum of contiguous subarray of numbers which has the largest sum.
For example, if the given array is {-2, -5, 6, -2, -3, 1, 5, -6}, then the maximum subarray sum is 7 (see highlighted elements).
Using Divide and Conquer approach, we can find the maximum subarray sum in O(nLogn) time. Following is the Divide and Conquer algorithm.
1) Divide the given array in two halves
2) Return the maximum of following three
….a) Maximum subarray sum in left half (Make a recursive call)
….b) Maximum subarray sum in right half (Make a recursive call)
….c) Maximum subarray sum such that the subarray crosses the midpoint
The lines 2.a and 2.b are simple recursive calls. How to find maximum subarray sum such that the subarray crosses the midpoint? We can easily find the crossing sum in linear time. The idea is simple, find the maximum sum starting from mid point and ending at some point on left of mid, then find the maximum sum starting from mid + 1 and ending with sum point on right of mid + 1. Finally, combine the two and return.
*/
//Divide and Conquer based program for maximum subarray sum problem
#include <iostream>
#include <limits.h>
using namespace std;

//utility function to find maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }

//utility function to find maximum of three integers
int max(int a, int b, int c) { return max(max(a, b), c); }

//Find the maximum possible sum in arr[] such that arr[m] is part of it
int maxCrossingSum(int arr[], int l, int m, int h)
{
    //include elements on left of mid.
    int sum = 0;
    int left_sum = INT_MIN;

    for(int i = m; i >= l; i--)
    {
        sum += arr[i];
        if(sum > left_sum)
            left_sum = sum;
    }

    //include elements on right of mid.
    sum = 0;
    int right_sum = INT_MIN;

    for(int i = m + 1; i <= h; i++)
    {
        sum += arr[i];
        if(sum > right_sum)
            right_sum = sum;
    }

    //Return sum of elements on left and right of mid
    return left_sum + right_sum;
}

//Returns sum of maximum sum subarray in arr[l..h]
int maxSubArraySum(int arr[], int l, int h)
{
    //base case: only one element
    if(l == h)
        return arr[l];

    //Find the middle point
    int m = (l + h) / 2;

    /* Return maximum of following three possible cases
        a) Maximum subarray sum in left half
        b) Maximum subarray sum in right half
        c) Maximum subarray sum such that the subarray crosses the midpoint */
    return max(maxSubArraySum(arr, l, m),
               maxSubArraySum(arr, m+1, h),
               maxCrossingSum(arr, l, m, h));    
}

int main()
{
    int arr[] = {2, 3, 4, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max_sum = maxSubArraySum(arr, 0, n-1);
    cout << "Maximum contiguous sum is " << max_sum << endl;
    return 0;
}
