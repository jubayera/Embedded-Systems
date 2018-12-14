/*
Trapping Rain Water

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

Examples:

Input: arr[]   = {2, 0, 2}
Output: 2
Structure is like below
| |
|_|
We can trap 2 units of water in the middle gap.

Input: arr[]   = {3, 0, 0, 2, 0, 4}
Output: 10
Structure is like below
     |
|    |
|  | |
|__|_| 
We can trap "3*2 units" of water between 3 an 2,
"1 unit" on top of bar 2 and "3 units" between 2 
and 4.  See below diagram also.

Input: arr[] = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
Output: 6
       | 
   |   || |
_|_||_||||||
Trap "1 unit" between first 1 and 2, "4 units" between
first 2 and 3 and "1 unit" between second last 1 and last 2 

An element of array can store water if there are higher bars on left and right. We can find amount of water to be stored in every element by finding the heights of bars on left and right sides. The idea is to compute amount of water that can be stored in every element of array. For example, consider the array {3, 0, 0, 2, 0, 4}, we can store two units of water at indexes 1 and 2, and one unit of water at index 2.

A Simple Solution is to traverse every array element and find the highest bars on left and right sides. Take the smaller of two heights. The difference between smaller height and height of current element is the amount of water that can be stored in this array element. Time complexity of this solution is O(n2).

An Efficient Solution is to pre-compute highest bar on left and right of every bar in O(n) time. Then use these pre-computed values to find the amount of water in every array element. Below is C++ implementation of this solution.
*/
//C++ program to find maximum amount of water that can be trapped within given set of bars.
#include <bits/stdc++.h>
using namespace std;

int findWater_dp(int arr[], int n)
{
    //left[i] contains height of tallest bar to the left of i'th bar including itself
    int left[n];

    //right[i] contains height of tallest bar to the right of ith bar including itself
    int right[n];

    //initialize result
    int water = 0;

    //Fill left array
    left[0] = arr[0];
    for(int i = 1; i < n; i++)
        left[i] = max(left[i-1], arr[i]);

    //Fill right array
    right[n-1] = arr[n-1];
    for(int i = n-2; i >= 0; i--)
        right[i] = max(right[i+1], arr[i]);

    // Calculate the accumulated water element by element 
    // consider the amount of water on i'th bar, the 
    // amount of water accumulated on this particular 
    // bar will be equal to min(left[i], right[i]) - arr[i] . 
    for(int i = 0; i < n; i++)
        water += min(left[i], right[i]) - arr[i];

    return water;
}

/*
Instead of maintaing two arrays of size n for storing left and right max of each element, 
we will just maintain two variables to store the maximum till that point. 
Since water trapped at any element = min(max_left, max_right) – arr[i] 
we will calculate water trapped on smaller element out of A[lo] and A[hi] 
first and move the pointers till lo doesn’t cross hi.
*/
//module to find maximum amount of water that can be trapped within given set of bars.
//Space complexity: O(1)
int findWater_dp_space_eff(int arr[], int n)
{
    //initialize output
    int result = 0;

    //maximum element on left and right
    int left_max = 0, right_max = 0;

    //indices to traverse the array
    int lo = 0, hi = n-1;

    while(lo <= hi)
    {
        if(arr[lo] < arr[hi])
        {
            if(arr[lo] > left_max)
                //update max in left
                left_max = arr[lo];
            else
                //water on curr element = max - curr
                result += left_max - arr[lo];
            lo++;
        }
        else
        {
            if(arr[hi] > right_max)
                //update right maximum
                right_max = arr[hi];
            else
                result += right_max - arr[hi];
            hi--;
        }
    }

    return result;
}



int main()
{
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum water that can be accumulated is: " << findWater_dp(arr, n) << endl;
    cout << "Maximum water that can be accumulated: " << findWater_dp_space_eff(arr, n) << endl;

    return 0;
}
