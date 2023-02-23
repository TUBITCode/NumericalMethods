//synthetic division and remainder theorem
//x3-7x2+15x-9 ,divisor = 3
#include <stdio.h>

int main()
{
    int deg, i;
    int a[20],b[20],q;
    printf("enter the degree of the polynomial equation \n");
    scanf("%d", &deg);
    printf("enter the value of divisor\n");
    scanf("%f",&q);
    printf("\n");
    for (i = deg; i >= 0; i--)
    {
        printf("x to the power %d index coffecient of the polynomial equation\n", i);
        scanf("%d", &a[i]);
    }
    for(i=deg;i>=0;i--){
        printf("a[%d]=%d\n",i,a[i]);
    }
    printf("\n");
  b[deg]=0;
  printf("b[%d]=%d\n",deg,b[deg]);
 for(i=deg;i>=0;i--){
    b[i-1]=a[i]+(q*b[i]);
    
  }

  for(i=deg;i>=0;i--){
    printf("b[%d]=%d\n",i-1,b[i-1]);
    
  }
  printf("Remainder is equal to %d\n",a[0]+q*b[0]);
 
}
//problem!!!!!!!!!!!!!!!!!!!