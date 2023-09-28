#include <stdlib.h> 
#include <stdio.h> 
#include <math.h> 


float y(float a,float b,float c,float x){
	return ((a*pow(x,2)+b*x+c)*sin(x));
}


int main() {
	//2. Найти наибольшее и наименьшее значение функции 
    //y= (a*x^2+b*x+c)*sin(x) 
    //при изменении x от xнач  до xкон  с шагом h.  
    //Вывести значения y. Исходные данные:
    //a  = 2.14;  b= - 4.21;  c = 3.25; xнач= -4.5; xкон = -13.5;
    //h= 0.5 .
    //(ответ min=-361.783, max=308.497)
	float a,b ,c,x ,xn,xk,h,min,max;
	printf("a,b,c = ");
	scanf("%f %f %f",&a,&b,&c);
	printf("--------------------------------\n");
	printf("x nachal'noe = ");
	scanf("%f",&xn);
	printf("x konechnoe = ");
	scanf("%f",&xk);
	printf("--------------------------------\n");
	printf("shag = ");
	scanf("%f",&h);
	printf("--------------------------------\n");
	min=max=y(a,b,c,xn);
	x=xn;

	while (x<=xk){
		printf("x= %.3f    y=%.3f\n\n",x,y(a,b,c,x));
		if (min>y(a,b,c,x)) min=y(a,b,c,x);
		if (max<y(a,b,c,x)) max=y(a,b,c,x);
		x+=h;
	}

	printf("--------------------------------\n");
	printf("Ymin= %.3f\n",min);
	printf("Ymax= %.3f\n",max);
	printf("--------------------------------\n");
} 
