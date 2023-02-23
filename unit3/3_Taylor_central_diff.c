// Write a program to calculate the derivative using central difference approximation
// using Taylor series.
//find the value of derivatives at x=1 for a function f(x)=x^2 use h=0.2
#include <stdio.h>
#define f(x) x *x

int main()
{
    float A,a, X, h, result,b,c;
    printf("Equation : x*x\n");
    printf("Enter the value of X for the function f(x): ");
    scanf("%f", &X);
    printf("Enter the value of h : ");
    scanf("%f", &h);
    b=X-h;
    c=X+h;
    a = f(b);
    A=f(c);
    printf("The value of f(x+h)=%.2f\n",A);
    printf("The value of f(x-h)=%.2f\n",a);
    result = (A-a) / (2*h);
    printf("The derivative of given fucntion at x=%.1f is %.2f\n", X, result);
    return 0;
}