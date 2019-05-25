/*    Maximum Pairwise Product
Find the maximum product of two distinct numbers in a sequence of non-negative integers.
Input: A sequence of non-negative integers.
Output: The maximum value that can be obtained by multiplying two different elements from the sequence.
Given a sequence of non-negative integers a1, ..., an, compute  1<=i != j <= n  MAX ai*aj
Note that i and j should be different, though it may be the case that ai = aj.

Input format: The first line contains an integer n. The next line contains n non-negative integers
			   a1, ...., an
Output format: The maximum pairwise product.
Constraints: 2 <= n <= 2*10^5;  0<= a1, ...., an <= 2*10^5

Sample 1:
Input:
3
1 2 3
Output:
6

Sample 2:
Input:
10
7 5 14 2 8 8 10 1 2 3
Output:
140
*/

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::max;
using std::sort;

typedef long long ll;

//O(n^2)
long long MaxPairwiseProduct_Naive(const vector<ll>& numbers) {
	long long product = 0;
	int n = numbers.size();
	for(int i = 0; i < n; ++i) {
		for(int j = i + 1; j < n; ++j) {
			product = max(product, (long long) numbers[i] * numbers[j]);
		}
	}
	return product;
}

//O(n)
long long MaxPairwiseProduct_Fast(const vector<ll> &numbers) {
	int n = numbers.size();

	int max_index1 = -1;
	for(int i = 0; i < n; ++i)
		if((max_index1 == -1) || (numbers[i] > numbers[max_index1]))
			max_index1 = i;

	int max_index2 = -1;
	for(int j = 0; j < n; ++j)
		if((j != max_index1) && ((max_index2 == -1) || (numbers[j] > numbers[max_index2])))
			max_index2 = j;

	return ((long long) (numbers[max_index1])) * numbers[max_index2];
}

//O(nlongn)
ll MaxPairwiseProduct_Faster(const vector<ll> &numvect) {
	int n = numvect.size();

	ll numbers[n];

	for(int i = 0; i < n; i++)
		numbers[i] = numvect[i];

	sort(numbers, numbers + n); //qsort is O(nlogn) if numbers was an array

	ll last_num1 = numbers[n-1];
	ll last_num2 = numbers[n-2];

	ll first_num1 = numbers[0];
	ll first_num2 = numbers[1];

	ll ans = last_num1*last_num2 > first_num1*first_num2 ? last_num1*last_num2 : first_num1*first_num2;

	return ans;

}

int main()
{
	int n;
	cin >> n;
	vector<ll> numbers(n);
	for(int i = 0; i < n; ++i) {
		cin >> numbers[i];
	}

	//ll product = MaxPairwiseProduct_Naive(numbers);
	//cout << "Naive Solution: " << product << "\n";

	//product = MaxPairwiseProduct_Fast(numbers);
	//cout << "Faster solution O(n): " << product << "\n";

	ll product = MaxPairwiseProduct_Faster(numbers);
	//cout << "Faster solution O(nlogn): " << product << "\n";

	cout << product << "\n";

    return 0;
}
