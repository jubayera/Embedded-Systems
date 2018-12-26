/* Read several lines of text and determine the average number of characters per line */
#include <stdio.h>

int sum = 0;    //total number of characters
int lines = 0;  //total number of lines

int linecount(void);

int main(int argc, char const *argv[])
{
    int n;  //number of chars in given line
    float avg;  //average number of chars per line

    printf("Enter the text below\n");

    //read a line of text and update the cumulative counters
    while((n = linecount()) > 0)
    {
        sum += n;
        ++lines;
    }

    avg = (float) sum / lines;
    printf("\nAverage number of characters per line: %5.2f", avg);

    return 0;
}

//read a line of text and count the number of characters
int linecount(void)
{
    char line[80];
    int count = 0;

    while((line[count] = getchar()) != '\n')
        ++count;

    return (count);
}
