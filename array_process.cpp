#include <iostream>
#include <vector>
using namespace std;

//Generates number (from 1 - 100). Print number of occurrences of each number.
void number_of_occurrence()
{
	const int DIFFERENT_NUMBERS = 100;

	int totalNumbers;
	//prompt for and read number of games
	cout << "Provide number of integers: ";
	cin >> totalNumbers;

	vector<int> numbers ( DIFFERENT_NUMBERS + 1 );

	//Initialize the vector to zeros.
	for(unsigned int i=0; i < numbers.size(); i++)
		numbers[i] = 0;

	//Generate the numbers
	for(int j = 0; j < totalNumbers; j++)
		numbers[ rand() % DIFFERENT_NUMBERS + 1]++;

	//Output the summary
	for(int k = 1; k <= DIFFERENT_NUMBERS; k++)
		cout << k << " occurs " << numbers[k] << " time(s) \n";

}

/*Read an unlimited number of ints with no attempts at error recovery; fill the vector parameter with the data;
its size after the return tells how many items were read*/
void getInts( vector<int> & array )
{
	unsigned int itemsRead = 0;
	int inputVal;

	cout << "Enter any number of integers: ";
	while( cin >> inputVal )
	{
		if( itemsRead == array.size() )
			array.resize( array.size() * 2 + 1 );

		array[ itemsRead++ ] = inputVal;
	}
	array.resize( itemsRead );
}

//Code to read an unlimited number of ints and write them out, using array-doubling
void read_ints_any_number_times(void)
{
	vector<int> array;

	getInts( array );

	for(unsigned int i = 0; i < array.size(); i++)
		cout << array[i] << endl;
}

int main()
{
	number_of_occurrence();

	read_ints_any_number_times();

	return 0;
}
