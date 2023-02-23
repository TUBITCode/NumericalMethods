// Write a program to implement composite Simpson’s 1/3 rule
// find 0,1{(sqrt(1-x^2))dx by using single segment trapezoidal rule when k=4
#include <stdio.h>
#include <math.h>
#define f(x) sqrt(1 - x * x)
int main()
{
    int k, i;
    float x0, xn, h, x[10], res[10], even = 0, odd = 0, result, f0, fn;
    printf("f(x) = sqrt(1 - x * x)\n");
    printf("Enter the value of the x0 and xn : ");
    scanf("%f%f", &x0, &xn);
    f0 = f(x0);
    printf("The value of f(x0) is %.4f\n", f0);
    fn = f(xn);
    printf("The value of  f(xn) is %.4f\n", fn);
    printf("Enter the value of segments : ");
    scanf("%d", &k);
    h = (xn - x0) / k;
    for (i = 1; i <= k - 1; i++)
    {
        x[i] = x0 + i * h;
        printf("The value of x%d=%.4f\n", i, x[i]);
        res[i] = f(x[i]);
        printf("The value of f(x%d)=%.4f\n", i, res[i]);
    }
    for (i = 1; i <= k - 1; i++)
    {
        if (i % 2 == 0)
        {
            even = even + 2 * res[i];
        }
        else
        {
            odd = odd + 4 * res[i];
        }
    }
    result = h / 3 * (f0 + even + odd + fn);
    printf("The integration of the given funtion using composite simpsom 1/3 rule is %.4f",result);
}