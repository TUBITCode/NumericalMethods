// program to calculate roots of non linear equation using bisection method
#include <stdio.h>
#include <math.h>
#define f(x) x *x - 4 * x - 10 // at -2and -1
#define error 0.001
int main()
{
    float x1, x2, x3, f1, f2, f3;
    int i = 0;
    printf("Enter the value of x1 and x2:\n");
    scanf("%f%f", &x1, &x2);

    do
    {

        f1 = f(x1);
        f2 = f(x2);
        if (f1 * f2 < 0)
        {
            x3 = (x1 + x2) / 2;
            f3 = f(x3);
            if (f1 * f3 < 0)
            {
                x2 = x3;
            }
            else
            {
                x1 = x3;
            }
            i++;
            printf("\nIteration=%d\n", i);
            printf("Root approximation to the given equation is %f\n", x3);
            printf("Functional value =%f\n", f3);
            printf("\n");
        }
        else{
            printf("Root does not lies in the range\n");
        }

    } while (fabs(f3) > error);
}

// fabs is a function that gives absolute value