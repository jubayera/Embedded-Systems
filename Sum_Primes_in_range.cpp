/* 
Sum of all the prime numbers in a given range

Given a range [l, r], the task is to find the sum of all the prime numbers within that range.

Examples:

Input : l=1 and r=6
Output : 10
2+3+5=10

Input : l=4 and r=13
Output : 36
5+7+11+13=36
Approach 1: (Naive Approach)
Iterate the loop from ‘l’ to ‘r’ and add all the numbers which are prime.

Below is the implementation of the above approach:*/
// C++ Program to computer sum of prime number 
// in a given range 
#include <iostream> 
using namespace std; 
  
// Method to compute the prime number 
// Time Complexity is O(sqrt(N)) 
bool checkPrime(int numberToCheck) 
{ 
    if(numberToCheck == 1) { 
        return false; 
    } 
    for (int i = 2; i*i <= numberToCheck; i++) { 
        if (numberToCheck % i == 0) { 
            return false; 
        } 
    } 
    return true; 
} 
  
// Method to iterate the loop from l to r 
// If the current number is prime, sum the value 
int primeSum(int l, int r) 
{ 
    int sum = 0; 
    for (int i = r; i >= l; i--) { 
  
        // Check for prime 
        bool isPrime = checkPrime(i); 
        if (isPrime) { 
  
            // Sum the prime number 
            sum = sum + i; 
        } 
    } 
    return sum; 
} 
// Time Complexity is O(r x sqrt(N)) 
  
//Driver code 
int main() 
{ 
    int l = 4, r = 13; 
  
    // Call the method with l and r 
    cout << primeSum(l, r); 
} 

/*Time Complexity: O(n\sqrt{n})
Space Complexity: O(1)

Approach 2: (Dynamic Programming)

    Declare an array dp and arr
    Fill the array arr to 0
    Iterate the loop till sqrt(N) and if arr[i] = 0 (marked as prime), then set all of it’s multiples as non-prime by marking the respective location as 1
    Update the dp array with the running prime numbers sum, where each location ‘dp[i]’ holds the sum of all the prime numbers withing the range [1, i]*/

// Java Program to computer sum of prime number 
// in a given range 
public class GFG { 
  
    // Suppose the constraint is N<=1000 
    static int N = 1000; 
  
    // Declare an array for dynamic approach 
    static long dp[] = new long[N + 1]; 
  
    // Method to compute the array 
    static void sieve() 
    { 
        // Declare an extra array as arr 
        int arr[] = new int[N + 1]; 
        arr[0] = 1; 
        arr[1] = 1; 
  
        // Iterate the loop till sqrt(n) 
        // Time Complexity is O(log(n) X sqrt(n)) 
        for (int i = 2; i <= Math.sqrt(N); i++) 
  
            // if ith element of arr is 0 i.e. marked as prime 
            if (arr[i] == 0) 
  
                // mark all of it's multiples till N as non-prime 
                // by setting the locations to 1 
                for (int j = i * i; j <= N; j += i) 
                    arr[j] = 1; 
  
        long runningPrimeSum = 0; 
  
        // Update the array 'dp' with the running sum 
        // of prime numbers within the range [1, N] 
        // Time Complexity is O(n) 
        for (int i = 1; i <= N; i++) { 
            if (arr[i] == 0) 
                runningPrimeSum += i; 
  
            //Here, dp[i] is the sum of all the prime numbers 
            //within the range [1, i] 
            dp[i] = runningPrimeSum; 
        } 
    } 
  
    // Driver code 
    public static void main(String[] args) 
    { 
        int l = 4, r = 13; 
  
        // Compute dp 
        sieve(); 
        System.out.println(dp[r] - dp[l - 1]); 
    } 
} 
