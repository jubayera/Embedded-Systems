/* Cartesian product of two or more lists.
Show one or more idiomatic ways of generating the Cartesian product of two arbitrary lists.
Demonstrate that function returns:
	{1,2} * {3,4} = {(1,3), (1,4), (2,3), (2,4)}
and, in contrast:
	{3,4} * {1,2} = {(3,1), (3,2), (4,1), (4,2)}
And demonstrate, using your function, that the product of an empty list with any other list is empty.
	{1,2} * {} = {}
	{} * {1,2} = {}
Write a function returning the n-ary product of an arbitrary number of lists, each of arbitrary length.
The function might, for example, accept a single argument which is itself a list of lists, and return the
n-ary product of those lists. Use your n-ary Cartesian product function to show the folowing products:
	{1776, 1789} * {7, 12} * {4, 14, 23} * {0, 1}
	{1, 2, 3} * {30} * {500, 100}
	{1, 2, 3} * {} * {500, 100}

Below is a Recursive implementation for computing the Cartesian product of lists. In the pursuit of making it 
as interactive as possible, the parsing function ended up taking the most space. The product set expression must
be supplied enclosed by double quotes. Prints out usage on incorrect invocation. */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void cartesianProduct(int** sets, int* setLengths, int* currentSet, int numSets, int times)
{
	int i, j;

	if(times == numSets) {
		printf("(");
		for(i = 0; i < times; i++) {
			printf("%d,", currentSet[i]);
		}
		printf("\b),");
	}
	else {
		for(j = 0; j < setLengths[times]; j++) {
			currentSet[times] = sets[times][j];
			cartesianProduct(sets, setLengths, currentSet, numSets, times+1);
		}
	}
}

void printSets(int** sets, int* setLengths, int numSets)
{
	int i, j;
	
	printf("\nNumber of sets: %d", numSets);

	for(i = 0; i < numSets+1; i++) {

		printf("\nSet %d : ", i+1);

		for(j = 0; j < setLengths[i]; j++) {
			
			printf(" %d ", sets[i][j]);
			
		}
	}
}

void processInputString(char* str)
{
	int **sets, *currentSet, *setLengths, setLength, numSets = 0, i, j, k, l, start, counter = 0;
	char *token, *holder, *holderToken;

	for(i = 0; str[i] != 00; i++)
		if(str[i] == 'x')
			numSets++;

	if(numSets == 0) {
		printf("\n%s", str);
		return;
	}

	currentSet = (int*) calloc(sizeof(int), numSets+1);

	setLengths = (int*) calloc(sizeof(int), numSets+1);

	sets = (int**) malloc((numSets + 1) * sizeof(int *));

	token = strtok(str, "x");

	while(token != NULL) 
	{
		holder = (char *) malloc(strlen(token) * sizeof(char));

		j = 0;

		for(i = 0; token[i] != 00; i++) {
			if(token[i] >= '0' && token[i] <= '9')
				holder[j++] = token[i];
			else if(token[i] == ',')
				holder[j++] =  ' ';
		}
		holder[j] = 00;

		setLength = 0;

		for(i = 0; holder[i] != 00; i++)
			if(holder[i] == ' ')
				setLength++;

		if(setLength == 0 && strlen(holder) == 0) {
			printf("\n{}");
			return;
		}

		setLengths[counter] = setLength + 1;

		sets[counter] = (int *) malloc((1 + setLength) * sizeof(int));

		k = 0;

		start = 0;

		for(l = 0; holder[l] != 00; l++) {
			if(holder[l+1] == ' ' || holder[l+1] == 00) {
				holderToken = (char *) malloc((l+1-start) * sizeof(char));
				strncpy(holderToken, holder+start, l+1-start);
				sets[counter][k++] = atoi(holderToken);
				start = l+2;
			}
		}

		counter++;
		token = strtok(NULL, "x");
	}

	printf("\n{");

	cartesianProduct(sets, setLengths, currentSet, numSets+1, 0);

	printf("\b}");

	printf("\n");
}

int main(int argc, char* argv[])
{
	if(argc != 2)
		printf("Usage: %s <Set product expression enclosed in double quotes>", argv[0]);
	else
		processInputString(argv[1]);

	return 0;
}

Output:
------
jubayer@embed-prog:~/work-prog$ ./cartesian_product_lists "{1,2} x {3,4}"

{(1,3),(1,4),(2,3),(2,4)}
jubayer@embed-prog:~/work-prog$ ./cartesian_product_lists "{3,4} x {1,2}"

{(3,1),(3,2),(4,1),(4,2)}
jubayer@embed-prog:~/work-prog$ ./cartesian_product_lists "{1,2} x {}"

{}jubayer@embed-prog:~/work-prog./cartesian_product_lists "{} x {1,2}"

{}jubayer@embed-prog:~/work-prog./cartesian_product_lists "{1776, 1789} x {7, 12} x {4, 14, 23} x {0, 1}"

{(1776,7,4,0),(1776,7,4,1),(1776,7,14,0),(1776,7,14,1),(1776,7,23,0),(1776,7,23,1),(1776,12,4,0),(1776,12,4,1),(1776,12,14,0),(1776,12,14,1),(1776,12,23,0),(1776,12,23,1),(1789,7,4,0),(1789,7,4,1),(1789,7,14,0),(1789,7,14,1),(1789,7,23,0),(1789,7,23,1),(1789,12,4,0),(1789,12,4,1),(1789,12,14,0),(1789,12,14,1),(1789,12,23,0),(1789,12,23,1)}
jubayer@embed-prog:~/work-prog$ ./cartesian_product_lists "{1, 2, 3} x {30} x {500, 100}"

{(1,30,500),(1,30,100),(2,30,500),(2,30,100),(3,30,500),(3,30,100)}
jubayer@embed-prog:~/work-prog$ ./cartesian_product_lists "{1, 2, 3} x {} x {500, 100}"

{}
