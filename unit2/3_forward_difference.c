//	WAP to implement Newton’s forward difference formula.
// Estimate the value of sin(theta) at theta =25 using Newton forward difference interpolation
// thita        10      20      30      40      50
// sinthita     0.1736  0.3420  0.5000  0.6428  0.7660 answer=0.422609
#include <stdio.h>
int main()
{
    int n, i, j, x[10], h;
    float y[10], dd[10], p, s, value, sterm = 1;
    printf("Enter the number of  data points : ");
    scanf("%d", &n);

    printf("Enter the interpolating point: ");
    scanf("%f", &p);

    printf("Enter the values of the X data points:\n");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &x[i]);
    }

    printf("Enter the values of the Y data points:\n");
    for (i = 1; i <= n; i++)
    {
        scanf("%f", &y[i]);
    }
    h = x[2] - x[1];
    s = (p - x[1]) / h;
    value = y[1];
    for (i = 1; i <= n - 1; i++)
    {
        for (j = 1; j <= n - 1; j++)
        {

            y[j] = y[j + 1] - y[j];
        }

        sterm = (sterm * (s - i + 1)) / i;
        value = value + sterm * y[1];
    }
    printf("The value of f(%f)is %f\n", p, value);
}
