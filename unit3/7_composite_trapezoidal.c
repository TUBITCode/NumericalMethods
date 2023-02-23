// compute the integral of -1,1{e^x dx for k=4 using composite trapezoidal rule
#include <stdio.h>
#include <math.h>
#define f(x) exp(x)
int main()
{
    int i, k;
    float x0, xn, h, x[10], b[10], result[10], solution, f0, fn, ans;
    printf("Enter the value of the x0 and xn : ");
    scanf("%f%f", &x0, &xn);
    printf("Enter the value of K : ");
    scanf("%d", &k);
    f0 = f(x0);
    fn = f(xn);
    printf("f0=%f\nfn=%f\n",f0,fn);
    h = (xn - x0) / 4;
    printf("the value of h=%.2f\n",h);
    for (i = 1; i <= k - 1; i++)
    {
        b[i] = x0 + h * i;
        result[i] = f(b[i]);
        printf("The value of f(x%d)=%f\n",i,result[i]);
    }
    solution = f0 + fn;
    for (i = 1; i <= k - 1; i++)
    {
        solution = solution + (2 * result[i]);
    }
    ans = (solution * h) / 2;
    printf("The answer of the given integration is %.3f\n", ans);
}
