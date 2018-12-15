#include <bits/stdc++.h>

using namespace std;

// Complete the factorial function below.
long int factorial(int n) {

    if(n <= 0)
    {
        return 1;
    }
    return n * factorial(n-1);
}

long int summation(int n)
{
    if(n <= 0)
        return 0;

    return n + summation(n-1);
}

long int exponentiation(int n, int expo)
{
    if(expo <= 0)
        return 1;

    return n * exponentiation(n, expo-1);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long int result = factorial(n);

    long int sum_recur = summation(n);

    long int expo_result = exponentiation(5, 3);

    fout << result << "\n"; //fout does not print to console

    cout << sum_recur << " " << expo_result << endl;

    fout.close();

    return 0;
}
