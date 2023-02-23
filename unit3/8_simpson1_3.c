//Write a program to implement Simpson’s 1/3 rule 
//find 0,1{(sqrt(1-x^2))dx by using single segment trapezoidal rule
#include<stdio.h>
#include<math.h>
#define f(x) sqrt(1-x*x)
int main(){
    float x0,x2,f0,f2,result,h,x1,f1;
    printf("f(x) = sqrt(1-x*x)\n");
    printf("Enter the value of x0 and x2 : ");
    scanf("%f%f",&x0,&x2);
    h=(x2-x0)/2;
    x1=x0+h;
   f1=f(x1);
   f0=f(x0);
   f2=f(x2);
   result=h/3*(f0+4*f1+f2);
   printf("The value of given intergration using simpson 1/3 rule is %f\n",result);

return 0;
}