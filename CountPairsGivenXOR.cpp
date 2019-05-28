/* Count all pairs with given XOR.
Given an array of distinct positive integers and a number x, find the number of pairs of integers in the array whose XOR is equal to x.
Input: arr[] = {5, 4, 10, 15, 7, 6}, x = 5
Output: 1
Explanation: (10 ^ 15) = 5

Input: arr[] = {3, 6, 8, 10, 15, 50}, x = 5
Output: 2
Explanation: (3 ^ 6) = 5 and (10 ^ 15) = 5

An efficient solution of this problem take O(n) time. The idea is based on the fact that arr[i] ^ arr[j] is equal to x 
                                                        if and only if arr[i] ^ x is equal to arr[j].
1) Initialize result as 0.
2) Create an empty hash set "s".
3) Do following for each element arr[i] in arr[]
    (a) If x ^ arr[i] is in "s", then increment result by 1.
    (b) Insert arr[i] into the hash set "s".
   return result.
*/

//Program to count all pair with given XOR value x
#include <bits/stdc++.h>

using namespace std;

//Returns count of pairs in arr[0..n-1] with XOR value equals to x.
int xorPairCount(int arr[], int n, int x) 
{
    int result = 0; //Initialize result

    //create empty set that stores the visiting element of array
    //unordered_set<int> s; //set does not work if there are duplicates

    //So create empty map that stores counts of individual elements of array
    unordered_map<int, int> m;

    for(int i = 0; i < n; i++) {
        /* If there exist an element in set s with XOR equals to x ^ arr[i],
        that means there exist an element such that the XOR of element with arr[i] 
        is equal to x, then increment count. */
        //if(s.find(x ^ arr[i]) != s.end())
        //    result++;

        //Make element visited
        //s.insert(arr[i]);
        //set won't work when there are duplicates. so above lines are commented out.

        int curr_xor = x ^ arr[i];

        /* If there exist an element in map m with XOR equals to x^arr[i], that means
        there exists an element such that the XOR of element with arr[i] is equal to x, then increment count */
        if(m.find(curr_xor) != m.end())
            result += m[curr_xor];

        //Increment count of current element
        m[arr[i]]++;
    }

    //return total count of pairs with XOR equal to x
    return result;
}

int main()
{
    int arr[] = {5, 4, 10, 15, 7, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 5;
    cout << "Count of pairs with given XOR = " << xorPairCount(arr, n, x);
    return 0;
}
