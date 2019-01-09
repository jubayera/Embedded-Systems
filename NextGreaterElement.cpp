/* 
Next Greater Element

Given an array, print the Next Greater Element (NGE) for every element. The Next greater Element for an element x is the first greater element on the right side of x in array. Elements for which no greater element exist, consider next greater element as -1.

Examples:
a) For any array, rightmost element always has next greater element as -1.
b) For an array which is sorted in decreasing order, all elements have next greater element as -1.
c) For the input array [4, 5, 2, 25}, the next greater elements for each element are as follows.

Element       NGE
   4      -->   5
   5      -->   25
   2      -->   25
   25     -->   -1

d) For the input array [13, 7, 6, 12}, the next greater elements for each element are as follows.

  Element        NGE
   13      -->    -1
   7       -->     12
   6       -->     12
   12     -->     -1
Method 1 (Simple)
Use two loops: The outer loop picks all the elements one by one. The inner loop looks for the first greater element for the element picked by outer loop. If a greater element is found then that element is printed as next, otherwise -1 is printed.*/
// Simple C++ program to print next greater elements in a given array 
#include<iostream> 
using namespace std; 
  
/* prints element and NGE pair  
for all elements of arr[] of size n */
void printNGE(int arr[], int n) 
{ 
    int next, i, j; 
    for (i = 0; i < n; i++) 
    { 
        next = -1; 
        for (j = i + 1; j < n; j++) 
        { 
            if (arr[i] < arr[j]) 
            { 
                next = arr[j]; 
                break; 
            } 
        } 
        cout << arr[i] << " -- " 
             << next << endl; 
    } 
} 
  
// Driver Code 
int main() 
{ 
    int arr[] = {11, 13, 21, 3}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    printNGE(arr, n); 
    return 0; 
} 

/* Time Complexity: O(n^2). The worst case occurs when all elements are sorted in decreasing order.

Method 2 (Using Stack)
1) Push the first element to stack.
2) Pick rest of the elements one by one and follow following steps in loop.
….a) Mark the current element as next.
….b) If stack is not empty, then pop an element from stack and compare it with next.
….c) If next is greater than the popped element, then next is the next greater element for the popped element.
….d) Keep popping from the stack while the popped element is smaller than next. next becomes the next greater element for all such popped elements
….e) Finally, push the next in the stack.
3) After the loop in step 2 is over, pop all the elements from stack and print -1 as next element for them.

Below is the implementation of above approach:*/

// A Stack based C++ program to find next 
// greater element for all array elements. 
#include <bits/stdc++.h> 
using namespace std; 

/* prints element and NGE pair for all elements of arr[] of size n */
void printNGE(int arr[], int n) { 
  stack < int > s; 
  
  /* push the first element to stack */
  s.push(arr[0]); 
  
  // iterate for rest of the elements 
  for (int i = 1; i < n; i++) { 
  
    if (s.empty()) { 
      s.push(arr[i]); 
      continue; 
    } 
  
    /* if stack is not empty, then pop an element from stack. 
       If the popped element is smaller than next, then 
    a) print the pair 
    b) keep popping while elements are 
    smaller and stack is not empty */
    while (s.empty() == false && s.top() < arr[i]) 
    {          
        cout << s.top() << " --> " << arr[i] << endl; 
        s.pop(); 
    } 
  
    /* push next to stack so that we can find 
    next greater for it */
    s.push(arr[i]); 
  } 
  
  /* After iterating over the loop, the remaining 
  elements in stack do not have the next greater 
  element, so print -1 for them */
  while (s.empty() == false) { 
    cout << s.top() << " --> " << -1 << endl; 
    s.pop(); 
  } 
} 
  
/* Driver program to test above functions */
int main() { 
  int arr[] = {11, 13, 21, 3}; 
  int n = sizeof(arr) / sizeof(arr[0]); 
  printNGE(arr, n); 
  return 0; 
}

/* Output:

 11 -- 13
 13 -- 21
 3 -- -1
 21 -- -1

Time Complexity: O(n). The worst case occurs when all elements are sorted in decreasing order. If elements are sorted in decreasing order, then every element is processed at most 4 times.
a) Initially pushed to the stack.
b) Popped from the stack when next element is being processed.
c) Pushed back to the stack because next element is smaller.
d) Popped from the stack in step 3 of algo.

How to get elements in same order as input?
The above approach may not produce output elements in same order as input. To achieve same order, we can traverse the same in reverse order

Below is the implementation of above approach:*/

// A Stack based C++ program to find next  
// greater element for all array elements  
// in same order as input.  
#include <bits/stdc++.h> 
   
using namespace std;  
  
/* prints element and NGE pair for all  
elements of arr[] of size n */
void printNGE(int arr[], int n)  
{  
    stack<int> s;  
    unordered_map<int, int> mp;  
  
    /* push the first element to stack */
    s.push(arr[0]);  
      
  
    // iterate for rest of the elements  
    for (int i = 1; i < n; i++) {  
  
        if (s.empty()) {  
            s.push(arr[i]);  
            continue;  
        }  
  
        /* if stack is not empty, then  
    pop an element from stack.  
    If the popped element is smaller  
    than next, then  
    a) print the pair  
    b) keep popping while elements are  
    smaller and stack is not empty */
        while (s.empty() == false && s.top() < arr[i]) {  
            mp[s.top()] = arr[i];  
            s.pop();  
        }  
  
        /* push next to stack so that we can find  
    next smaller for it */
        s.push(arr[i]);  
    }  
  
    /* After iterating over the loop, the remaining  
elements in stack do not have the next smaller  
element, so print -1 for them */
    while (s.empty() == false) {  
        mp[s.top()] = -1;  
        s.pop();  
    }  
  
    for (int i=0; i<n; i++)  
    cout << arr[i] << " ---> " << mp[arr[i]] << endl;  
}  
  
/* Driver program to test above functions */
int main()  
{  
    int arr[] = { 11, 13, 21, 3 };  
    int n = sizeof(arr) / sizeof(arr[0]);  
    printNGE(arr, n);  
    return 0;  
} 
