/*
 * Permutations of a given string using STL
A permutation, also called an “arrangement number” or “order”, is a rearrangement of the elements of an ordered list
S into a one-to-one correspondence with S itself. A string of length n has n! permutation.

Below are the permutations of string ABC.
ABC ACB BAC BCA CBA CAB

std::rotate function rotates elements of a vector/string such that the passed middle element becomes first.
For example, if we call rotate for “ABCD” with middle as second element, the string becomes “BCDA” and
if we again call rotate with middle as second element, the string becomes “CDAB”.
 */

// C++ program to print all permutations with duplicates allowed using rotate() in STL

#include <bits/stdc++.h>
using namespace std;

/*
 * Function to print permutations of string str,
 * out is used to store permutations one by one
 */
void permute(string str, string out)
{
    // When size of str becomes 0, out has a
    // permutation (length of out is n)
	if(str.size() == 0)
	{
		cout << out << endl;
		return;
	}

    // One be one move all characters at
    // the beginning of out (or result)
	for(int i = 0; i < str.size(); i++)
	{
		//Remove first character from str and add it to out
		permute(str.substr(1), out + str[0]);

		//Rotate string in a way second character moves to the beginning
		rotate(str.begin(), str.begin() + 1, str.end());
	}
}

int main()
{
	string str = "ABC";

	permute(str, "");

	return 0;
}

/*
ABC
ACB
BCA
BAC
CAB
CBA
*/
