//Horner's evaluation of polynomial equation
#include <stdio.h>

int main()
{
    int deg, i;
    float a[20], x, sum = 0;
    printf("enter the degree of the polynomial equation \n");
    scanf("%d", &deg);
    printf("\n");
    for (i = deg; i >= 0; i--)
    {
        printf("x to the power %d index coffecient of the polynomial equation\n", i);
        scanf("%f", &a[i]);
    }

    printf("enter the value at which you want to evaluate polynomial equation\n");
    scanf("%f", &x);

    for (i = deg; i > 0; i--)
    {
        sum = (sum + a[i]) * x;
    }
    sum = sum + a[0];
    printf("the functional value at %f is %f\n", x, sum);
}