// WAP to implement Lagrange’s interpolation to implement Lagrange’s interpolation
//x 0  1       2       3
//y 1  2.7183  7.3891  20.0855 determine with third order polynomial at x=1.2
#include <stdio.h>
float li(int,int, float *x, float *y, float);//float li(int,int, float x[n+1], float y[n+1], float)
float pn(int, float *x, float *y, float);//float pn(int, float x[n+1], float y[n+1], float)
int main()
{
    int i, n; // degree of equation
    float inter_point;
    printf("Enter the degree of the equation: ");
    scanf("%d", &n);
    

    float x[n + 1];
    float y[n + 1];
    printf("Enter the values of x data points : ");
    for (i = 0; i < n + 1; i++)
    {
        scanf("%f", &x[i]);
    }

     printf("Enter the values of Y data points : ");
    for (i = 0; i < n + 1; i++)
    {
        scanf("%f", &y[i]);
    }

  printf("Enter the interpolating point : ");
  scanf("%f",&inter_point);
  
  printf("The value of Y at %f interpolating point is %f\n",inter_point,pn(n,x,y,inter_point));//when we pass array x then only base address is passed so in function defination we have pointer
    
}
float li(int i,int n,float *x,float *y,float p){
    float product=1;
    int j;
    for(j=0;j<n+1;j++){
        if(j!=i){
            product=product*((p-x[j])/(x[i]-x[j]));
        }
        
    }
    return product;

}
float pn (int n,float *x,float *y,float p){
    float sum=0;
    int i;
    for(i=0;i<n+1;i++){
        sum=sum+(li(i,n,x,y,p)*y[i]);
    }
    return sum;
}