/* https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=warmup&h_r=next-challenge&h_v=zen*/
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the jumpingOnClouds function below.
int jumpingOnClouds(vector<int> c) {

  int jumps = 0;

  for (int i = 0; i < c.size(); i++) {
    if (i + 2 < c.size() && !c[i + 2]) {
      jumps++;
      i++;
    } else if (i + 1 < c.size() && !c[i + 1]) {
      jumps++;
    }
  }

  return jumps;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<int> c(n);

    for (int i = 0; i < n; i++) {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int result = jumpingOnClouds(c);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

#include <vector>
#include <iostream>
#include <algorithm>

int main(){
    int n; std::cin >> n;
    std::vector<bool> clouds(n);
    unsigned int tmp;
    for (auto c : clouds) {
        std::cin >> tmp;
        c = tmp == 1;
    }
    
    int jumps = 0;
    for (int i = 0; i < n; i++) {
        if (i+2 < n && !clouds[i+2]) {
            jumps++;
            i++;
        } else if (i+1 < n && !clouds[i+1]) {
            jumps++;
        }
    }
    
    std::cout << jumps << std::endl;
    
    return 0;
}
