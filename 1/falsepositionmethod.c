#include<stdio.h>
#define E 0.0001

double func(double x){
    return x*x*x - x*x + 2;
}
 
void falsep(double a, double b){
    if (func(a) * func(b) >= 0){
        printf("invalid a & b !");
        return;
    }
    double c = a;
    int i;
    for(i=0;i<100000;i++){
        c = (a*func(b) - b*func(a))/ (func(b) - func(a));
 
        if (func(c)==0)
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
    printf("Function : x^3 - x^2 + 2\n");
	printf("Enter a & b :\n");
	scanf("%f%f",&a,&b);
    falsep(a, b);
    return 0;
}
