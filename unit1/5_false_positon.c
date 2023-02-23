// program to find a root of non linear equation using false positon method
#include <stdio.h>
#include <math.h>
#define f(x) x *x - x - 2 // 1 3
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
        if (f1 * f2 < 0)
        {
            x3 = x1 - ((f1 * (x2 - x1)) / (f2 - f1));
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
            printf("iteration=%d\n", i);
            printf("root approximation to the function is %f\n", x3);
            printf("the functional value is %f\n", f3);
            printf("\n");
        }
        else
        {
            printf("root doesnot lies in range\n");
        }

    } while (fabs(f3) > error);
}