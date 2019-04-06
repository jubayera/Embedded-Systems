/*
https://www.hackerrank.com/challenges/sock-merchant/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=warmup
*/
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Use map to keep track of how many socks that belong to a color.

int main() {
    int n;
    cin >> n;
    map<int,int> mp;
    for (int i=0; i<n; i++)
    {
        int color;
        cin >> color;
        mp[color]++;
    }
    int cnt=0;
    for (map<int,int> :: iterator j = mp.begin(); j!=mp.end(); j++)
        cnt += j->second / 2;

    cout << cnt << endl;
    
    return 0;
}
