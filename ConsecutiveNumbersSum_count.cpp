/* Consecutive Numbers Sum
   ------------------------
Given a positive integer N, how many ways we can write it as a sum of consecutive positive integers?
Example 1:
----------
    Input: 5
    Output: 2
    Explanation: 5 = 5 = 2 + 3

Example 2:
----------
    Input: 9
    Output: 3
    Explanation: 9 = 9 = 4 + 5 = 2 + 3 + 4

Example 3:
----------
    Input: 15
    Output: 4
    Explanation: 15 = 15 = 8 + 7 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5

Note: 1 <= N <= 10 ^ 9

*/
class Solution {
    public:
        int consecutiveNumbersSum(int N) {
            int result = 0;
            for(int i = 1; i <= (int) sqrt(2 * N); i++) {
                
                if((2 * N % i) != 0)
                    continue;
                
                int x = (2 * N / i) - i -1;

                if(x % 2 == 0 && x >= 0) {
                    result++;
                }
            }
            return result;
        }
};
