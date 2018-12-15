#include <bits/stdc++.h>

using namespace std;

// Complete the solve function below.
void solve(double meal_cost, int tip_percent, int tax_percent) {

  double tip_total = meal_cost * tip_percent / 100;
  double tax_total = meal_cost * tax_percent / 100;

  long total_cost = round(meal_cost + tip_total + tax_total);

  cout << total_cost << endl;
}

void even_number_Day3()
{
    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if(N%2 != 0) {
        cout << "Weird\n";
    }
    else if(N%2 == 0 && (N>=2 && N<=5)) {
        cout << "Not Weird\n";
    } else if (N % 2 == 0 && (N >= 6 && N <= 20)) {
      cout << "Weird\n";
    } else if (N % 2 == 0 && (N > 20)) {
      cout << "Not Weird";
    }
}


int main()
{
    double meal_cost;
    cin >> meal_cost;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int tip_percent;
    cin >> tip_percent;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int tax_percent;
    cin >> tax_percent;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    solve(meal_cost, tip_percent, tax_percent);
  
    even_number_Day3();

    return 0;
}
