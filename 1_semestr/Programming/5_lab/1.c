//    1. Вычислить приближенно значение числа Пи c помощью ряда лейбница с точностью до e=0.00001, где
//Pi=4*(1-1/3+1/5-1/7+1/9….)
#include <stdlib.h> 
#include <stdio.h> 
#include <math.h> 

int main() {
    double Pi=1,x=1,e=0.00001;
	int n=1;
		while (fabs(x)>= e){
			x=(pow((-1),n)/(2*n+1));
			Pi+=x;
			n+=1;
		}
	printf("Pi= %.6f \n",(4*Pi));
    }
    float y(float a,float b,float c,float x){
	    return ((a*pow(x,2)+b*x+c)*sin(x));
}
