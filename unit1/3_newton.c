// program to find root of non linear equation using Newton Raphson method
#include <stdio.h>
#include <math.h>
#define f(x) x *x - 3 * x + 2//0
#define d(x) 2 * x - 3
#define error 0.00001
int main()
{
    float x0, x1, f0, d0, f1;
    int i = 0;
    printf("enter the value of x0\n");
    scanf("%d", &x0);
    do
    {
        f0 = f(x0);
        d0 = d(x0);
        x1 = x0 - (f0 / d0);
        f1 = f(x1);
        x0 = x1;
        i++;
        printf("Iteration=%d\n", i);
        printf("root approximation to the given equation is %f\n", x1);
        printf("\n");

    } while (fabs(f1) > error);
}
