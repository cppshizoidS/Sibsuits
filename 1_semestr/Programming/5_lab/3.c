//Найти и вывести простые числа и  их количество в диапазоне от 2 до n, n ввести с клавиатуры
#include <stdlib.h> 
#include <stdio.h> 
#include <math.h> 

int main(){
    long int n,i=2,del,q;
	printf("n = ");
	scanf("%ld",&n);
	printf("--------------------------------\n");
	while (i<=n){
		del=0;
			for (int k=1; k<=i; k++){
				if (i % k==0) del++;
			}
		if (del==2){
			printf("%ld  ",i);
			q++;
		}
		i++;
	
	}
	printf("\nq=%ld ",q);
	printf("\n");
}