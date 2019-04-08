//https://www.hackerrank.com/challenges/two-strings/problem?h_l=interview&playlist_slugs[]=interview-preparation-kit&playlist_slugs[]=dictionaries-hashmaps&h_r=next-challenge&h_v=zen
#include <iostream>
using namespace std;

bool check(const string& _a, const string& _b)
{
    //Run time : O(n+m+52)

    bool arr[52] = {false};

    for(auto& a_chr : _a)
        arr[a_chr - 'a'] = true; //keep true flag for the a to z character for the characters of string _a

    for(auto& b_chr : _b)
        arr[b_chr - 'a' + 26] = true; //keep true flag for the a to z character for the characters of string _b

    for(int i = 0; i < 26; i++) //if the alphabet was present in both the strings _a and _b, then return true
        if(arr[i] && arr[i+26]) 
            return true;

    return false;
}

int main()
{
    int t;

    cin >> t;

    string a_str, b_str;

    while(t-- > 0)
    {
        cin >> a_str >> b_str;
        cout << (check(a_str, b_str) ? "YES" : "NO") << endl;
    }

    return 0;
}
