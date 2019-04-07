//https://www.hackerrank.com/challenges/2d-array/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays

#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {

    /* Here loop runs (R-2)*(C-2) times considering
        different top left cells of hour glasses. */
    int max_sum = INT_MIN;

    for (int row = 0; row < arr.size() - 2; row++) 
    {
        for (int col = 0; col < arr[row].size() - 2; col++) 
        {
            //Considering arr[row][col] as top left cell of hour glass.
            int sum = (arr[row][col] + arr[row][col+1] + arr[row][col+2]) +
                        (arr[row+1][col+1]) + 
                      (arr[row+2][col] + arr[row+2][col+1] + arr[row+2][col+2]);

            //If previous sum is less than current sum then update new sum in max_sum
            max_sum = max(max_sum, sum);
        }
    }

    return max_sum;

}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    cout << result << "\n";

    //fout.close();

    return 0;
}
