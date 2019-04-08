//https://www.hackerrank.com/challenges/ctci-ransom-note/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dictionaries-hashmaps
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool ransom_note(vector<string> magazine, vector<string> ransom)
{
    //Save in map
    unordered_map <string, int> magazine_map;

    for(auto m_note : magazine)
        magazine_map[m_note] += 1;

    //If value not present in dict; return false
    //If repeated words; Reduce count by 1
    for(const auto &r_note : ransom)
        if(magazine_map[r_note] == 0)
            return false;
        else    //else, present so decrement magazine map counter of that string key
            magazine_map[r_note] --;

    //Value exists if reaches here, so returns true
    return true;
}

int main()
{
    int m, n;

    cin >> m >> n;

    vector<string> magazine(m);

    for(int magazine_i = 0; magazine_i < m; magazine_i++)
        cin >> magazine[magazine_i];

    vector<string> ransom(n);

    for(int ransom_i = 0; ransom_i < n; ransom_i++)
        cin >> ransom[ransom_i];

    if(ransom_note(magazine, ransom))
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}
