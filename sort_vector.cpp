//Sorting a vector in C++
//C++ program to sort a vector in non-decreasing (increasing) order
#include <bits/stdc++.h>
using namespace std;

void sort_increasing(void)
{
    vector<int> v{ 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };

    sort(v.begin(), v.end());

    cout << "Sorted \n";

    for(auto x : v) {
        cout << x << " ";
    }
    
    cout << "\n";
}

/* sorting in descending order
  sort() takes a third parameter that is used to specify the order in which elements are to be sorted. We can pass "greater()" function to sort in descending order.
  This function does comparison in a way that puts greater element before.
*/
void sort_decreasing_order(void)
{
	vector<int> v{ 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };

	sort(v.begin(), v.end(), greater<int>());

        for(auto x : v) {
    	    cout << x << " ";
    	}

	cout << "\n";

}


/* Sorting in a particular order.
We can also write our own comparator function and pass it as a third parameter.
*/
//An interval has start time and end time
struct Interval {
	int start, end;
};

//Compares two intervals according to starting times.
bool compareInterval(Interval i1, Interval i2)
{
	return (i1.start < i2.start);
}

void sort_by_compare()
{
	vector<Interval> v { {6, 8}, {1, 9}, {2, 4}, {4, 7} };

	//sort the intervals in increasing order of start time
	sort(v.begin(), v.end(), compareInterval);

	cout << "Intervals sorted by start time: \n";
	
	for(auto x : v)
		cout << "[" << x.start << ", " << x.end << "] ";
}

int main()
{
    sort_increasing();	

    sort_decreasing_order();

    sort_by_compare();
 
    return 0;
}
