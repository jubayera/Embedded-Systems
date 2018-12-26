/* Find the maximum of a function within a specified interval */
#include <stdio.h>
#include <math.h>

#define CNST 0.0001

double a, b, xl, yl, xr, yr;    //global variables

void reduce(void);
double curve(double xl);

int main(int argc, char const *argv[])
{
    double xmax, ymax;

    //read input data (interval end points)

    printf("\na = ");
    scanf("%lf", &a);
    printf("\nb = ");
    scanf("%lf", &b);

    //interval reduction loop
    do
        reduce();
    while ((yl != yr) && ((b-a) > 3 * CNST));

    //calculate xmax and ymax, and display the results
    xmax = 0.5 * (xl + xr);
    ymax = curve(xmax);

    printf("\nxmax = %8.6lf   ymax = %8.6lf\n", xmax, ymax);

    return 0;
}

//interval reduction routine
void reduce(void)
{
    xl = a + 0.5 * (b - a - CNST);
    xr = xl + CNST;
    yl = curve(xl);
    yr = curve(xr);

    if(yl > yr) // retain left interval
    {
        b = xr;
        return;
    }
    if(yl < yr) // retain right interval
    {
        a = xl;
    }
    return;
}

//evaluate the function y = x * cos(x)
double curve(double x)
{
    return (x * cos(x));
}

//gcc -g max_curve.c -o max_curve -lm
