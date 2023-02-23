#include <stdio.h>

float f(float x){
    //x^3+x-1
    float f = x*x*x + x - 1;
    return f;
}
 
void secant(float x1, float x2, float E){
    float n = 0, xm, x0, c;
    if (f(x1) * f(x2) < 0) {
        do {
            x0 = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
            c = f(x1) * f(x0);
            x1 = x2;
            x2 = x0;

            n++;

            if (c == 0)
                break;
            xm = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
        } while ((xm - x0) >= E);
        printf("Root= %f",x0);
    } else
        printf("Can''t find root !");
}

int main(){
    float x1 = 0, x2 = 1, E = 0.0001;
    printf("Function : x^3+x-1\n");
    printf("Enter x1 & x2 : ");
    scanf("%f%f",&x1,&x2);
    secant(x1, x2, E);
    return 0;
}
