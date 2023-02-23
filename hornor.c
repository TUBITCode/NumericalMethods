#include <stdio.h>

int horner(int poly[], int n, int x){
    int i,result = poly[0];
 
    for(i=1; i<n; i++)
        result = result*x + poly[i];
        
    return result;
}

int main(){
    printf("Polynomail: 2x3-6x2+2x-1\n");
    int poly[] = {2, -6, 2, -1};
    int x =3;
    int n = sizeof(poly)/sizeof(poly[0]);
    printf("Value of polynomial is %d",horner(poly, n, x));
    return 0;
}
