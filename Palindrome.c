//Search for a palindrome
#include <stdio.h>
#include <ctype.h>

#define EOL '\n'
#define TRUE 1
#define FALSE 0

int main(int argc, char const *argv[])
{
    char letter[80];
    int tag, count, countback, flag, loop = TRUE;

    //main loop
    while(loop) {
        flag = TRUE;

        //read the text
        printf("Please enter a word, phrase or sentence below:\n");

        for(count = 0; (letter[count] = getchar()) != EOL; ++count)
            ;

        if((toupper(letter[0]) == 'E') && (toupper(letter[1]) == 'N') && (toupper(letter[2]) == 'D'))
            break;

        tag = count - 1;

        //carry out the palindrome search
        for((count = 0, countback = tag); count <= tag/2; (++count, --countback))
        {
            if(letter[count] != letter[countback])
            {
                flag = FALSE;
                break;
            }
        }

        //display message
        for(count = 0; count <= tag; ++count)
            putchar(letter[count]);

        if(flag) printf(" IS a palindrome\n\n");
        else printf(" is NOT a palindrome\n\n");
    }

    return 0;
}
/*
Please enter a word, phrase or sentence below:
TOOT
TOOT IS a palindrome

Please enter a word, phrase or sentence below:
FALSE
FALSE is NOT a palindrome

Please enter a word, phrase or sentence below:
PULLUP
PULLUP IS a palindrome

Please enter a word, phrase or sentence below:
ABLE WAS I ERE I SAW ELBA
ABLE WAS I ERE I SAW ELBA IS a palindrome

Please enter a word, phrase or sentence below:
END
*/
