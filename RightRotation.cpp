#include <iostream>
#include <vector>
using namespace std;
/*
Algorithm to right rotate an array
Begin:
    read(arr)
    read(n)
    For i←1 to n do
        rotateArrayByOne(arr)
    End for
End
rotateArrayByOne(arr[], SIZE)
Begin:
    last ← arr[SIZE - 1]
    For i ← SIZE-1 to 0 do
        arr[i] ← arr[i - 1]
    End for
    arr[0] ← last
End
*/

void rotateByOne(int a[], int n)
{
    int i, last;

    //Store last element of vector
    last = a[n-1];

    for(int i = n-1; i > 0; i--)
    {
        a[i] = a[i-1];
    }

    a[0] = last;
}

void array_right_rotation(int a[], int n, int k)
{
    k %= n;

    //Right rotate array k times
    for(int i = 1; i <= k; i++)
    {
        rotateByOne(a, n);
    }

}

int main()
{
    int n, k;

    cin >> n >> k;

    int a[n];

    for(int i = 0; i < n; i++)
        cin >> a[i];    

    array_right_rotation(a, n, k);

    for(int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << endl;

    return 0;
}
