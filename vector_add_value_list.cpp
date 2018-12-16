#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



// Complete the oddNumbers function below.
vector<int> oddNumbers(int l, int r) { 
    
    std::vector<int> odd_numer_vector;

    for(int i = l; i <= r; i++)
    {
        if(i%2 != 0)
        {
          odd_numer_vector.push_back(i);
        }
    } 

    return odd_numer_vector;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string l_temp;
    getline(cin, l_temp);

    int l = stoi(ltrim(rtrim(l_temp)));

    string r_temp;
    getline(cin, r_temp);

    int r = stoi(ltrim(rtrim(r_temp)));

    vector<int> res = oddNumbers(l, r);

    for (int i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
