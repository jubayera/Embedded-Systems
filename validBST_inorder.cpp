#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

string isValid(vector<int> a) {
    // Create an empty stack 
    stack<int> s; 
  
    // Initialize current root as minimum possible 
    // value 
    int root = INT_MIN; 
  
    // Traverse given array 
      for (int v : a) {
        // If we find a node who is on right side 
        // and smaller than root, return false 
        if (v < root) 
            return "NO"; 
  
        // If pre[i] is in right subtree of stack top, 
        // Keep removing items smaller than pre[i] 
        // and make the last removed item as new 
        // root. 
        while (!s.empty() && s.top() < v) 
        { 
            root = s.top(); 
            s.pop(); 
        } 
  
        // At this point either stack is empty or 
        // pre[i] is smaller than root, push pre[i] 
        s.push(v); 
    } 
    return "YES";
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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

