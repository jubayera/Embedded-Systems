/*
Given a 6x6 2D Array, A: 
1 1 1 0 0 0
0 1 0 0 0 0
1 1 1 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0

We define an hourglass in A
to be a subset of values with indices falling in this pattern in A's graphical representation:
a b c
  d
e f g

There are 16 hourglasses in A, and an hourglass sum is the sum of an hourglass' values.
 Calculate the hourglass sum for every hourglass in A, then print the maximum hourglass sum.
 There are 6 lines of input, where each line contains 6 space-separated integers
 describing 2D Array A; every value in A will be in the inclusive range of -9 to 9.
 Print the largest (maximum) hourglass sum found in A.
*/
#include <bits/stdc++.h>

using namespace std;

int main() {

    vector< vector<int> > arr(6, vector<int>(6));

    for(int arr_i = 0;arr_i < 6;arr_i++){
       for(int arr_j = 0;arr_j < 6;arr_j++){
          cin >> arr[arr_i][arr_j];
       }
    }

    int i,j,max;
    for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
                {
                    int sum = 0;
                    sum = arr[i][j]+arr[i][j+1]+arr[i][j+2]
                            +arr[i+1][j+1]
                            +arr[i+2][j]+arr[i+2][j+1]+arr[i+2][j+2];

                    if(i==0 && j==0)
                        max = sum;
                    if(sum > max)
                    {
                        max = sum;
                    }
            }
        }
        cout << max << endl;
    return 0;
}
