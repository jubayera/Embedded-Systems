/*Given a base-10 integer,n, convert it to binary (base-2). 
Then find and print the base-10 integer denoting the maximum number of consecutive 
1's in n's binary representation.
Input: A single integer, n. 1<=n<=10^6 
Output: Print a single base-10 integer denoting the maximum 
number of consecutive 1's in the binary representation of n.
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int max = 0, count = 0;

    while(n > 0)
    {
        if(n%2 == 1)
            count++;
        else
            count = 0;

        if(count > max)
            max = count;

        n = n / 2;
    }

    cout << max << endl;

    return 0;
}
