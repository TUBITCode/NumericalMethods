#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define   f(x)   cos(x)-3*x+1
#define   g(x)   (1+cos(x))/3

int main(){
	 printf("f(x) : cos(x)-3*x+1\ng(x) : (1+cos(x))/3\n");
	 int step=1, N=10000;
	 float x0=-20, x1, e=0.001;
	 do{
		  x1 = g(x0);
		  step = step + 1;
		  if(step>N){
			   printf("Not Convergent.");
			   exit(0);
		  }
		  x0 = x1;
	 }while( fabs(f(x1)) > e);
	 printf("Root= %f",x1);
}
