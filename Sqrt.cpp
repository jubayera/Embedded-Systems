/* Sqrt(x)
Implement int sqrt(int x).
Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned. 

Example:
Input: 4  Output: 2

Input: 8  Output: 2 (Square root of 8 is 2.82842...., and since decimal part is truncated, 2 is returned). */

class Solution {
    public:
        int mySqrt(int x) {
            if(x < 0) return -1;
            else if(x < 2) return x;

            //Newton method
            //x_n + 1 = (xn + X/x_n)/2;
            int x0 = x-1;
            int x1 = (x0 + x/x0)/2;

            while(abs(x1-x0) > 1)
            {
                x0 = x1;
                x1 = (x0 + x/x0)/2;
            }

            int res = min(x0, x1);
            if(res*res > x) 
                res -= 1;

            return res;
        }
};
