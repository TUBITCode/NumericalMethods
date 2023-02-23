//	WAP to implement least square approximationusing Linear least square method.
// Fit a straight line to the following data points
// x  1 2 3 4  5
// y  3 5 7 10 12
#include <stdio.h>

int main()
{
    int x[10], y[10], i, n, sx = 0, sy = 0, s_sq_x = 0, sxy = 0, p_sXsY, s_x_whole_sq = 0;
    float a, b,meanx,meany;
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    printf("Enter the value of X data : ");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &x[i]);
    }

    printf("Enter the value of y data : ");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &y[i]);
    }
    for (i = 1; i <= n; i++)
    {

        sx = sx + x[i];
        sy = sy + y[i];
        sxy = sxy + x[i] * y[i];
        s_sq_x = s_sq_x + x[i] * x[i];
    }
    p_sXsY = sx * sy;
    s_x_whole_sq = sx * sx;
    printf("Sum of x = %d\n", sx);
    printf("Sum of y = %d\n", sy);
    printf("Sum of square of x = %d\n", s_sq_x);
    printf("Sum of product of sumx and sum y = %d\n", p_sXsY);
    printf("Sum of product of x and y = %d\n", sxy);
    printf("Whole square of sum of  x = %d\n", s_x_whole_sq);
    b = (float)(n * sxy - p_sXsY) / (float)(n * s_sq_x - s_x_whole_sq);
    meanx=sx/(float)n;
    meany=sy/(float)n;
    a = meany -b*meanx;

    printf("The equation of the straight line is y=%.1fx+(%.1f)\n", b, a);

    return 0;
}
