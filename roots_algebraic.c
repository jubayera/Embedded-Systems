/* determine the roots of an algebraic equation using an iterative procedure */
#include <stdio.h>
#include <math.h>
#define TRUE 1
#define FALSE 0

int main(int argc, char const *argv[])
{
    int flag = TRUE, count = 0;
    float guess, root, test, error;

    //read input parameters
    printf("Initial guess: ");
    scanf("%f", &guess);

    while(flag) {
        ++count;
        if(count == 50)
            flag = FALSE;

        test = 10. - 3. * guess * guess;

        if(test > 0) {
            root = pow(test, 0.2);
            printf("\nIteration number: %2d", count);
            printf("    x= %7.5f", root);
            error = fabs(root - guess);

            if(error > 0.00001)
                guess = root;   //repeat the calculation
            else {
                flag = FALSE;
                printf("\n\nRoot= %7.5f", root);
                printf("   No. of iterations= %2d", count);
            }
        }
        else {
            flag = FALSE;
            printf("\nNumbers out of range - try another initial guess");
        }
    }

    if((count == 50) && (error > 0.00001))  //another error message
        printf("\n\nConvergence not obtained after 50 iterations");

    return 0;
}
/*
 gcc -g roots_algebraic.c -lm -o roots
 Initial guess: 1

Iteration number:  1    x= 1.47577
Iteration number:  2    x= 1.28225
Iteration number:  3    x= 1.38344
Iteration number:  4    x= 1.33613
Iteration number:  5    x= 1.35951
Iteration number:  6    x= 1.34826
Iteration number:  7    x= 1.35375
Iteration number:  8    x= 1.35109
Iteration number:  9    x= 1.35238
Iteration number: 10    x= 1.35175
Iteration number: 11    x= 1.35206
Iteration number: 12    x= 1.35191
Iteration number: 13    x= 1.35198
Iteration number: 14    x= 1.35195
Iteration number: 15    x= 1.35196
Iteration number: 16    x= 1.35195

Root= 1.35195   No. of iterations= 16 */
