#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

void count_table(void)
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for(int i = 1; i <= 10; i++)
        cout << n << " x " << i << " = " << n*i << endl;
}

void printEvenIndexChar(string strparam, int len) {
  for (int i = 0; i < len; i++) {
    if (i % 2 == 0) {
      cout << strparam[i];
    }
  }
}

void printOddIndexChar(string strparam, int len) {
  for (int i = 0; i < len; i++) {
    if (i % 2 != 0) {
      cout << strparam[i];
    }
  }
}

int main() {

  count_table();

  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int T;
  cin >> T;

  string str;

  while (T > 0) {
    cin >> str;
    int length = str.length();

    printEvenIndexChar(str, length);
    cout << " ";
    printOddIndexChar(str, length);
    cout << endl;

    T--;
  }

  return 0;
}
