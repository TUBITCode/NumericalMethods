#include<stdio.h>
#include<math.h>

#define EPSILON 0.001

double func(double x){
    return x*x*x - x*x + 2;
}
 
double derivFunc(double x){
    return 3*x*x - 2*x;
}
 
void newtonRaphson(double x){
    double h = func(x) / derivFunc(x);
    while (abs(h) >= EPSILON){
        h = func(x)/derivFunc(x);
        x = x - h;
    }
 
    printf("Root= %f",x);
}
 
int main(){
    double x0 = -20;
    printf("Function: x^3 - x^2 + 2\n");
    printf("Enter x0 : ");
    scanf("%f",&x0);
    newtonRaphson(x0);
    return 0;
}
