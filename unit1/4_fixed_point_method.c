// program to find root of non linear equation using fixed point method
#include <stdio.h>
#include <math.h>
#define f(x) cos(x) - 3 * x + 1
#define phi(x) (cos(x)+1)/3
#define error 0.0001
int main()
{
    float x0, x1;
    int i = 0;
    printf("enter the value of x0\n");
    scanf("%f", &x0);
    do
    {
        x1 = phi(x0);

        x0 = x1;
        i++;
        printf("Iteration=%d\n", i);
        printf("root approximation to the given equation is %f\n", x1);
        printf("\n");

    } while (fabs(f(x1)) > error);
}
//sir in copy answer come in second iteration but not in this code!!!!!!!!!!!!!
