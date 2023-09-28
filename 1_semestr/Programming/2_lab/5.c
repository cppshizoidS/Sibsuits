#include <stdio.h>
#include <limits.h>

int main()
{
	int n; 
	int min_num=INT_MAX; 
	int num; 
	int i; 

	printf("How many numbers do you want to enter? ");
	scanf("%d", &n); 

	printf("Enter %d numbers one by one: ", n);

	for(i=1; i<=n; i++) {
		scanf("%d", &num); 

		if(num < min_num)  
			min_num = num;
	}

	printf("Minmum number = %d\n", min_num);

	return 0;
}