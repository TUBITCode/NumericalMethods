//Write a program to implement trapezoidal rule.
//find 2,8{(x^3+2)dx by using single segment trapezoidal rule
#include<stdio.h>
#define f(x) x*x*x+2
int main(){
    int x0,x1,f0,f1,result;
    printf("Funcion f(x) = x*x*x+2\n");
    printf("Enter the value of x0 and x1: ");
    scanf("%d%d",&x0,&x1);
    f0=f(x0);
    f1=f(x1);
    result=(x1-x0)*((f0+f1)/2);
    printf("The value of given intergration using Trapezoidal rule is %d\n",result);

return 0;
}