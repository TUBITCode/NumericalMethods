// program to calculate the roots of non linear equation using secant method
#include <stdio.h>
#include <math.h>
#define f(x) x *x - 4 * x - 10//4,2
#define error 0.001
int main()
{
    int i = 0;
    float x1, x2, x3, f1, f2, f3;
    printf("enter the value of x1 and x2\n");
    scanf("%f%f", &x1, &x2);

    do
    {
        f1 = f(x1);
        f2 = f(x2);
        x3 = x2 - (f2 * (x2 - x1)) / (f2 - f1);
        f3=f(x3);
        x1 = x2;
        x2 = x3;
        i++;
        printf("Iteration=%d\n", i);
        printf("root approximation to the given equation is %f\n", x3);
        printf("functional value =%f\n", f3);
        printf("\n");
    }
    while(fabs(f3)>error);
}