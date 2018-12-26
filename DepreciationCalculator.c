/* Calculate depreciation using one of three different methods */
#include <stdio.h>
#include <ctype.h>

void sl(float val, int n);
void ddb(float val, int n);
void syd(float val, int n);
void writeoutput(int year, float depreciation, float value);

int main(int argc, char const *argv[])
{
    int n, choice = 0;
    float val;
    char answer1 = 'Y', answer2 = 'Y';

    while(toupper(answer1) != 'N') 
    {
        //read input data
        if(toupper(answer2) != 'N') {
            printf("\nOriginal value: ");
            scanf("%f", &val);
            printf("Number of years: ");
            scanf("%d", &n);
        }
        printf("\nMethod: (1-SL 2-DDB 3-SYD) ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:     //straight-line method
                printf("\nStraight-Line Method\n\n");
                sl(val, n);
                break;
            case 2:     //double-declining-balance method
                printf("\nDouble-Declining-Balance Method\n\n");
                ddb(val, n);
                break;
            case 3:     //sum-of-the-years'-digits method
                printf("\nSum-Of-The-Years\'-Digits Method\n\n");
                syd(val, n);
        }

        printf("\n\nAnother calculation? (Y/N) ");
        scanf("%1s", &answer1);
        if(toupper(answer1) != 'N') {
            printf("Enter a new set of data? (Y/N) ");
            scanf("%1s", &answer2);
        }
    }

    return 0;
}

void sl(float val, int n) //straight-line method
{
    float deprec;
    int year;

    deprec = val/n;
    for(year = 1; year <= n; ++year) 
    {
        val -= deprec;
        writeoutput(year, deprec, val);
    }

    return;
}

void ddb(float val, int n) //double-declining-balance method
{
    float deprec;
    int year;
    for(year = 1; year <= n; ++year)
    {
        deprec = 2*val/n;
        val -= deprec;
        writeoutput(year, deprec, val);
    }
    return;
}

void syd(float val, int n) //sum-of-the-years'-digits method
{
    float tag, deprec;
    int year;

    tag = val;
    for(year = 1; year <= n; ++year)
    {
        deprec = (n - year + 1) * tag / (n*(n+1)/2);
        val -= deprec;
        writeoutput(year, deprec, val);
    }
    return;
}

void writeoutput(int year, float depreciation, float value) //display output data
{
    printf("End of Year %2d,    Depreciation: %7.2f    Current Value: %8.2f\n", year, depreciation, value);
}
