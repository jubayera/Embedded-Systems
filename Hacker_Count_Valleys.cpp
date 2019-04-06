// https://www.hackerrank.com/contests/rookierank/challenges/counting-valleys
#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) 
{
    int height = 0, result = 0;

    for(int i = 0; i < n; i++) // n = str.length()
    { 
        if(s.at(i) == 'U')
        {
            height++;

            if(height == 0)
            {
                result++;
            }

        }
        else {
            height--;
        }
    }

    return result;

}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    //fout << result << "\n";

    cout << result << "\n";

    //fout.close();

    return 0;
}

/*
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    int n;
    char k;
    
	cin>>n;
  
	int height = 0;
	int result = 0;
  
    while(cin>>k)
    {
        if(k=='U')
        {
          height++;
          if(height==0)
          {
            result++;
          }
        }
        else
        {
          height--;
        }
    }
    
	cout<<result;
	return 0;
}
*/
