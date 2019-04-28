/* 
Print all pairs with given sum

Given an array of integers, and a number ‘sum’, print all pairs in the array whose sum is equal to ‘sum’.

Examples :
Input  :  arr[] = {1, 5, 7, -1, 5}, 
          sum = 6
Output : (1, 5) (7, -1) (1, 5)

Input  :  arr[] = {2, 5, 17, -1}, 
          sum = 7
Output :  (2, 5)
*/
//A simple solution is to traverse each element and check if there's another number
//in the array which can be added to it to give sum.
#include <bits/stdc++.h>
using namespace std;

/* Naive Solution */
//Returns number of pairs in arr[0..n-1]
//with sum equal to 'sum'
int printPairs_Naive(int arr[], int n, int sum)
{
    int count = 0; //initialize result

    //Consider all possible pairs and check their sums
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if(arr[i] + arr[j] == sum)
                cout << "(" << arr[i] << ", " << arr[j] << ")" << endl; 
}

/* Method 2: (Use hashing).
    We create an empty hash table. Now we traverse through the array and check for pairs in hash table.
    If a matching element is found, we print the pair number of times equal to number of occurrences of
    the matching element. Note that the worst case of time complexity of this solution is O(c + n) where
    c is count of pairs with given sum.
*/
//Returns number of pairs in arr[0..n-1] with sum equal to 'sum'
void printPairs_UsingHashTable(int arr[], int n, int sum)
{
    //Store counts of all elements in map m
    unordered_map<int, int> m;

    //Traverse through all elements
    for(int i = 0; i < n; i++) {
        //Search if a pair can be formed with arr[i]
        int rem = sum - arr[i];

        if(m.find(rem) != m.end()) {
            int count = m[rem];
            for(int j = 0; j < count; j++)
                cout << "(" << rem << ", " << arr[i] << ")" << endl;
        }
        m[arr[i]]++;
    }
}

//driver function to test the above function
int main()
{
    int arr[] = {1, 5, 7, -1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target_sum = 6;

    cout << endl << "Using naive method: " << endl;
    printPairs_Naive(arr, n, target_sum);

    cout << endl << "Using hashTable: " << endl;
    printPairs_UsingHashTable(arr, n, target_sum);
    return 0;
}
