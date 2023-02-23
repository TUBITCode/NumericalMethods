// Write a program to implement Simpson’s 3/8rule
// find 0,1{(sqrt(1-x^2))dx by using single segment trapezoidal rule
#include <stdio.h>
#include <math.h>
#define f(x) sqrt(1-x*x)
int main()
{
    float x0, x3, f0, f3, result, h, x1, f1, x2, f2;

    printf("f(x) = sqrt(1-x*x)\n");
    printf("Enter the value of x0 and x3 : ");
    scanf("%f%f", &x0, &x3);

    h = (x3 - x0) / 3;
    printf("h=%.3f\n",h);

    x1 = x0 + h;
    printf("x1=%.3f\n", x1);
    f1 = f(x1);
    printf("f(x1)=%.3f\n", f1);

    x2 = x0 + 2 * h;
    printf("x2=%.3f\n", x2);

    f2 = f(x2);
    printf("f(x2)=%.3f\n", f2);

    f0 = f(x0);
    f3 = f(x3);
    result = ((3 * h) / 8) * (f0 + 3 * f1 + 3 * f2 + f3);
    printf("The value of given intergration using simpson 3/8 rule is %.3f\n", result);

    return 0;
}