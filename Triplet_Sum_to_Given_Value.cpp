/* Find a triplet that sum to a given value.
Given an array and a value, find if there is a triplet in array whose sum is equal to the given value. If there is such a triplet present in array, then print the triplet and return true. Else return false. For example, if the given array is {12, 3, 4, 1, 6, 9} and given sum is 24, then there is a triplet (12, 3 and 9) present in array whose sum is 24. 
Method 1 (Naive)
A simple method is to generate all possible triplets and compare the sum of every triplet with the given value. The following code implements this simple method using three nested loops.*/

#include <stdio.h> 
  
// returns true if there is triplet with sum equal 
// to 'sum' present in A[]. Also, prints the triplet 
bool find3Numbers(int A[], int arr_size, int sum) 
{ 
    int l, r; 
  
    // Fix the first element as A[i] 
    for (int i = 0; i < arr_size - 2; i++) { 
  
        // Fix the second element as A[j] 
        for (int j = i + 1; j < arr_size - 1; j++) { 
  
            // Now look for the third number 
            for (int k = j + 1; k < arr_size; k++) 
            { 
                if (A[i] + A[j] + A[k] == sum) { 
                    printf("Triplet is %d, %d, %d", 
                           A[i], A[j], A[k]); 
                    return true; 
                } 
            } 
        } 
    } 
  
    // If we reach here, then no triplet was found 
    return false; 
} 
  
/* Driver program to test above function */
int main() 
{ 
    int A[] = { 1, 4, 45, 6, 10, 8 }; 
    int sum = 22; 
    int arr_size = sizeof(A) / sizeof(A[0]); 
    find3Numbers(A, arr_size, sum); 
    return 0; 
} 

/* Triplet is 4, 10, 8

Time Complexity : O(n^3)

Method 2 (Use Sorting)
Time complexity of the method 1 is O(n^3). The complexity can be reduced to O(n^2) by sorting the array first, and then using method 1 of this post in a loop.
1) Sort the input array.
2) Fix the first element as A[i] where i is from 0 to array size – 2. After fixing the first element of triplet, find the other two elements using method 1 of this post.*/

// C++ program to find a triplet 
#include <bits/stdc++.h> 
using namespace std; 
  
// returns true if there is triplet with sum equal 
// to 'sum' present in A[]. Also, prints the triplet 
bool find3Numbers(int A[], int arr_size, int sum) 
{ 
    int l, r; 
  
    /* Sort the elements */
    sort(A, A + arr_size); 
  
    /* Now fix the first element one by one and find the 
       other two elements */
    for (int i = 0; i < arr_size - 2; i++) { 
  
        // To find the other two elements, start two index 
        // variables from two corners of the array and move 
        // them toward each other 
        l = i + 1; // index of the first element in the 
        // remaining elements 
  
        r = arr_size - 1; // index of the last element 

        while (l < r) { 

            if (A[i] + A[l] + A[r] == sum) { 

                printf("Triplet is %d, %d, %d", A[i], A[l], A[r]); 
                return true; 
            } 
            else if (A[i] + A[l] + A[r] < sum) 
                l++; 
            else // A[i] + A[l] + A[r] > sum 
                r--; 
        } 
    } 
  
    // If we reach here, then no triplet was found 
    return false; 
} 
  
/* Driver program to test above function */
int main() 
{ 
    int A[] = { 1, 4, 45, 6, 10, 8 }; 
    int sum = 22; 
    int arr_size = sizeof(A) / sizeof(A[0]); 
  
    find3Numbers(A, arr_size, sum); 
  
    return 0; 
} 

/* Output :

Triplet is 4, 8, 10

Time Complexity : O(n^2)

Method 3 (Hashing Based Solution) */

// C++ program to find a triplet using Hashing 
#include <bits/stdc++.h> 
using namespace std; 
  
// returns true if there is triplet with sum equal 
// to 'sum' present in A[]. Also, prints the triplet 
bool find3Numbers(int A[], int arr_size, int sum) 
{ 
    // Fix the first element as A[i] 
    for (int i = 0; i < arr_size - 2; i++) { 
  
        // Find pair in subarray A[i+1..n-1] 
        // with sum equal to sum - A[i] 
        unordered_set<int> s; 

        int curr_sum = sum - A[i]; 

        for (int j = i + 1; j < arr_size; j++) { 

            if (s.find(curr_sum - A[j]) != s.end()) { 

            printf("Triplet is %d, %d, %d", A[i], A[j], curr_sum - A[j]); 
                return true; 
            } 

            s.insert(A[j]); 
        } 
    } 
  
    // If we reach here, then no triplet was found 
    return false; 
} 
  
/* Driver program to test above function */
int main() 
{ 
    int A[] = { 1, 4, 45, 6, 10, 8 }; 
    int sum = 22; 
    int arr_size = sizeof(A) / sizeof(A[0]); 
  
     find3Numbers(A, arr_size, sum); 
      
    return 0; 
} 

//Output: Triplet is 4, 8, 10
