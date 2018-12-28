/* 
Find maximum possible stolen value from houses

There are n houses build in a line, each of which contains some value in it. A thief is going to steal the maximal value of these houses, but he can’t steal in two adjacent houses because owner of the stolen houses will tell his two neighbour left and right side. What is the maximum stolen value.
Examples:

Input  : hval[] = {6, 7, 1, 3, 8, 2, 4}
Output : 19
Thief will steal 6, 1, 8 and 4 from house.

Input  : hval[] = {5, 3, 4, 11, 2}
Output : 16
Thief will steal 5 and 11
While reaching house i thief has two options, either he robs it or leave it. Let dp[i] represents the maximum value stolen so far on reaching house i. We can calculate the value of dp[i] as following –

dp[i] = max (hval[i] + dp[i-2], dp[i-1])

hval[i] + dp[i-2] is the case when thief decided to rob house i. In that situation 
maximum value will be the current value of house + maximum value stolen till last 
robbery at house not adjacent to house i which will be house i-2.  
 
dp[i-1] is the case when thief decided not to rob house i. So he will check adjacent 
house for maximum value stolen till now. 

Thief will consider both options and decide whether to rob or not and maximum of both values will be the maximum stolen value till reaching house i.

We can prepare dp in bottom up manner instead of recursively. Following is the program for that –*/

// CPP program to find the maximum stolen value 
#include <iostream> 
using namespace std; 
  
// calculate the maximum stolen value 
int maxLoot(int *hval, int n) 
{ 
    if (n == 0) 
        return 0; 
    if (n == 1) 
        return hval[0]; 
    if (n == 2) 
        return max(hval[0], hval[1]); 
  
    // dp[i] represent the maximum value stolen 
    // so far after reaching house i. 
    int dp[n]; 
  
    // Initialize the dp[0] and dp[1] 
    dp[0] = hval[0]; 
    dp[1] = max(hval[0], hval[1]); 
  
    // Fill remaining positions 
    for (int i = 2; i<n; i++) 
        dp[i] = max(hval[i]+dp[i-2], dp[i-1]); 
  
    return dp[n-1]; 
} 

//We can optimize extra space, by using two variables to store value dp[i-1] and dp[i-2]. Following is the program for that –
// calculate the maximum stolen value 
int maxLoot_optmz(int *hval, int n) 
{ 
    if (n == 0) 
        return 0; 
  
    int value1 = hval[0]; 
    if (n == 1) 
        return value1; 
  
    int value2 = max(hval[0], hval[1]); 
    if (n == 2) 
        return value2; 
  
    // contains maximum stolen value at the end 
    int max_val; 
  
    // Fill remaining positions 
    for (int i=2; i<n; i++) 
    { 
        max_val = max(hval[i]+value1, value2); 
        value1 = value2; 
        value2 = max_val; 
    } 
  
    return max_val; 
} 
  
// Driver to test above code 
int main() 
{ 
    int hval[] = {6, 7, 1, 3, 8, 2, 4}; 
    int n = sizeof(hval)/sizeof(hval[0]); 
    cout << "Maximum loot possible : "
        << maxLoot(hval, n); 
    return 0; 
} 
