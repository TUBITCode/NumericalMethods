//	WAP to implement least square approximationusing exponential least square method.
// Fit a exponential model  to the following data points
// x  0.4  0.8  1.2    1.6    2.0   2.4
// y  75   100  140    200    270   375 answer y=53.32e^0.81x

#include <stdio.h>
#include<math.h>
int main()
{   int i,n;
    float x[10], y[10], sx = 0, sy = 0, s_sq_x = 0, sxlogy = 0, p_sXslogY, s_x_whole_sq = 0;
    float loga, a,b,meanx,meany,result=0;
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    printf("Enter the values of X data: ");
    for (i = 1; i <= n; i++)
    {
        scanf("%f", &x[i]);
    }

    printf("Enter the values of y data: ");
    for (i = 1; i <= n; i++)
    {
        scanf("%f", &y[i]);
    }
    for(i=1;i<=n;i++){
     result=result+log(y[i]);
    }
    for (i = 1; i <= n; i++)
    {
        
        sx = sx + x[i];
        sy = sy + y[i];
        sxlogy = sxlogy + x[i] * log(y[i]);
        s_sq_x = s_sq_x + x[i] * x[i];
    }
    p_sXslogY = sx * result;
    s_x_whole_sq = sx * sx;
    printf("Sum of x is %.2f\n", sx);
    printf("Sum of logy is %.2f\n", result);
    printf("Sum of square of x is %.2f\n", s_sq_x);
    printf("Sum of product of sumx and sum logy is %.2f\n", p_sXslogY);
    printf("Sum of product of x and logy is %.2f\n", sxlogy);
    printf("Whole square of sum of  x is %.2f\n", s_x_whole_sq);
    b = (float)(n * sxlogy - p_sXslogY) / (float)(n * s_sq_x - s_x_whole_sq);
    meanx=sx/(float)n;
    meany=result/(float)n;
    loga = meany -b*meanx;
    a=exp(loga);


    printf("The equation of the straight line is y=%.2fe^%.2fx\n", a, b);

    return 0;
}
