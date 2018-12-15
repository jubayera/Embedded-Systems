#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n;
    cin >>n;

    map<string, string> phonebook;

    string name, id;

    for (int i=0; i<n;i++) {
      cin >> name >> id;
      phonebook[name] = id;
    }

    while(cin >> name) {
        if (phonebook.find(name) != phonebook.end()) {
            cout << phonebook.find(name)->first << "=" << phonebook.find(name)->second << endl; //or just name could be used instead of phonebook.find(name)->first which is the key for phonebook
        } else {
            cout << "Not found" << endl;
        }
    }

    return 0;
}
