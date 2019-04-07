//C++ code to demonstrate sorting of a row of 2D vector
#include <iostream>
#include <vector> //for 2D vector
#include <algorithm> //for sort()
using namespace std;

int main()
{
    //Initializing 2D vector 'vect' with values
    vector< vector<int> > vect{{3, 5, 1},
                               {4, 8, 6},
                               {7, 2, 9}};

    //Displaying the 2D vector
    for(int i = 0; i < vect.size(); i++)
    {
        for(int j = 0; j < vect[i].size(); j++)
            cout << vect[i][j] << " ";

        cout << endl;
    }

    //Number of rows
    int m = vect.size();

    //Number of columns (Assuming all rows are of same size. We can have different sizes like Java though).
    int n = vect[0].size();

    //use of "sort()" for sorting first row
    sort(vect[0].begin(), vect[0].end());

    //Displaying the 2D vector after sorting
    cout << "The Matrix after sorting 1st row is:\n";
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
            cout << vect[i][j] << " ";
        cout << endl;
    } 

    return 0;
}
