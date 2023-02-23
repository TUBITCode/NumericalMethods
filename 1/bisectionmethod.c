#include<stdio.h>
#define EPSILON 0.0001

double func(double x){
    return x*x*x - x*x + 2;
}
 
void bisection(double a, double b){
    if (func(a) * func(b) >= 0){
        printf("invalid a & b !");
        return;
    }
 
    double c = a;
    while ((b-a) >= EPSILON){
        c = (a+b)/2;

        if (func(c) == 0.0)
            break;
        else if (func(c)*func(a) < 0)
            b = c;
        else
            a = c;
    }
    printf("Root = %f ",c);
}
 
int main(){
    double a =-200, b = 300;
    printf("Function : x*x*x - x*x + 2\n");
    printf("Enter a & b : ");
    scanf("%f%f",&a,&b);
    bisection(a, b);
    return 0;
}
