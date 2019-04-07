//https://www.hackerrank.com/challenges/ctci-array-left-rotation/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays&h_r=next-challenge&h_v=zen
#include <iostream>
#include <vector>
using namespace std;

vector<int> array_left_rotation(vector<int> a, int n, int k)
{
    k %= n;

    vector<int> result(n);

    for(int i = 0; i < n; i++)
    {
        result[(n+i-k) % n] = a[i];        
    }

    return result;
}

int main()
{
    int n, k;

    cin >> n >> k;

    vector<int> a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> output = array_left_rotation(a, n, k);

    for(int i = 0; i < n; i++)
        cout << output[i] << " ";

    cout << endl;

    return 0;
}
