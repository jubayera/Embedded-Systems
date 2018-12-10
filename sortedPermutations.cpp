/* Print all distinct permutations of a given string with duplicates
Given a string that may contain duplicates, write a function to print all permutations of given string such that no permutation is repeated in output.
Examples:

Input:  str[] = "AB"
Output: AB BA

Input:  str[] = "AA"
Output: AA

Input:  str[] = "ABC"
Output: ABC ACB BAC BCA CBA CAB

Input:  str[] = "ABA"
Output: ABA AAB BAA

Input:  str[] = "ABCA"
Output: AABC AACB ABAC ABCA ACBA ACAB BAAC BACA
        BCAA CABA CAAB CBAA
*/

//Program to print all permutations of a string in sorted order
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//compare function below is needed for qsort() library function
int compare(const void *a, const void *b)
{
	return ( *(char *)a - *(char *)b );
}

//swap two characters a and b
void swap(char* a, char* b)
{
	char t = *a;
	*a = *b;
	*b = t;
}

//This function finds the index of the smallest character which is greater than 'first' and is present in str[l..h]
int findCeil(char str[], char first, int l, int h)
{
	//initialize index of ceiling element
	int ceilIndex = l;

	//iterate through rest of the elements and find the smallest character greater than 'first'
	for(int i = l+1; i <= h; i++)
		if(str[i] > first && str[i] < str[ceilIndex])
			ceilIndex = i;

	return ceilIndex;
}

//print all permutations of str in sorted order
void sortedPermutations(char str[])
{
	//get size of string
	int size = strlen(str);

	//sort the string in increasing order
	qsort(str, size, sizeof( str[0] ), compare);

	//print permutations one by one
	bool isFinished = false;
	while (!isFinished)
	{
		//print this permutation
		static int x = 1;
		printf("%d %s\n", x++, str);

		// Find the rightmost character which is smaller than its next
		// character. Let us call it 'first char'
		int i;
		for(i = size - 2; i >= 0; --i)
			if(str[i] < str[i+1])
				break;

		// If there is no such character, all are sorted in decreasing order,
		// means we just printed the last permutation and we are done.
		if(i == -1)
			isFinished = true;
		else {
			// Find the ceil of 'first char' in right of first character.
			// Ceil of a character is the smallest character greater than it
			int ceilIndex = findCeil(str, str[i], i + 1, size - 1);

			//swap first and second characters
			swap(&str[i], &str[ceilIndex]);

			//sort the string on right of 'first char'
            qsort(str + i + 1, size - i - 1, sizeof(str[0]), compare);
		}

	}
}


int main()
{
	char str[] = "ACBC";
	sortedPermutations( str );
	return 0;
}

/*
1 ABCC
2 ACBC
3 ACCB
4 BACC
5 BCAC
6 BCCA
7 CABC
8 CACB
9 CBAC
10 CBCA
11 CCAB
12 CCBA
*/
