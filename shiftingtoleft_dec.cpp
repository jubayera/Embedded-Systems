/*
A long binary bit string is stored in a char array (size  128), 
write a function, given the char array and a number N, 
return a char array that has the original binary bits shifted by N bits

void shiftArray(char input[], int N)
{
    int i;
    char* sample = (char *) malloc(sizeof(input) - N);

    for ( i = 0; i < sizeof(sample); i++ ){
        sample[i] = input[N + i];
    }
    memset(input, sizeof(input), 0);

    for(i = 0; i < sizeof(sample); i++){
        input[N + i] = sample[i];
        cout << input[N+i];
    }
    cout << endl;

    for(int i = 0; i < strlen(input); i++)
        cout << input[i];

    cout << endl;

    free(sample);
    return;
}
*/

#include <stdio.h>

char *binbin(int n);

int main()
{
    int bshift,x;
    printf("Type a value from 0 to 255: ");
    scanf("%d",&bshift);
    for(x=0;x<8;x++)
    {
        printf("%s\n",binbin(bshift));
        bshift = bshift << 1;
    }
    return(0);
}

char *binbin(int n)
{
    static char bin[9];
    int x;
    for(x=0;x<8;x++)
    {
        bin[x] = n & 0x80 ? '1' : '0';
        n <<= 1;
    }
    bin[x] = '\0';
    return(bin);
}
