// Write a program to implement composite Simpson’s 3/8rule
// calculate the integral value of following tabulated function from x=0to 1.8 using simpson 3/8
// 0   0.2   0.4   0.6   0.8   1.0   1.2   1.4  1.6   1.8
// 0   0.24  0.55  0.93  1.63  1.84  2.37  2.95 3.56  4.60
#include <stdio.h>

int main()
{
    int n, k, i;
    float x[15], f[14], h,res,mulof3=0,no_mulof3=0,ans;
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    k = n - 1;
    printf("k=%d\n", k);
    printf("Enter the data points of x: ");
    for (i = 0; i <= k; i++)
    {
        scanf("%f", &x[i]);
        //printf("x%d=%.2f\n",i, x[i]);
        //printf("\n");
    }

    printf("Enter the data points of y: ");
    for (i = 0; i <= k; i++)
    {
        scanf("%f", &f[i]);
        //printf("f%d=%.2f\n", i,f[i]);
        //printf("\n");

    }
    res=f[0]+f[k];

    h = (x[k] - x[0]) / k;
    printf("h=%.4f\n", h);
    for(i=1;i<=k-1;i++){
        if(i%3==0){
            mulof3=mulof3+f[i]*2;

        }
        else{
           no_mulof3=no_mulof3+3*f[i];
        }

    }
    ans=((3*h)/8)*(res+mulof3+no_mulof3);
    printf("The value of integration of given tabulated value using  simpson's 3/8 rule is %.4f\n",ans);
    return 0;
}
