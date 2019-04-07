#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {

    long num_repeated_A_s = 0, result;

    //count the number of a's in the original string
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'a')
            num_repeated_A_s++;
    }

    //count the number of times the original string repeats and add that to our answer
    result = (n / s.size()) * num_repeated_A_s;

    //count any remaining a's
    for(int i = 0; i < (n % s.size()); i++)
    {
        if(s[i] == 'a')
            result++;
    }

    return result;

}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    //fout << result << "\n";

    cout << result << "\n";

    //fout.close();

    return 0;
}
