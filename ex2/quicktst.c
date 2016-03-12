#include<stdlib.h>
#include<stdio.h>
#include <time.h>
#include "quick.h"

/*Test program for test merge sort works : genarate 50 random numbers and sorting*/
int main(){

	int arr[50] ;
	int i;
	srand(time(NULL));

	 for(i=0;i<50;i++)
        arr[i] = rand()%50;

    printf("\n---- Without optimization ----\n\n");
	printf("Before Sort\n");
	print(arr,50);
	Quicksort(arr,0,49);
	printf("After Sort\n");
	print(arr,50);

	printf("\n---- With optimization ----\n\n");
	printf("Before Sort\n");
	print(arr,50);
	QuicksortT(arr,0,49,10);
	printf("After Sort\n");
	print(arr,50);

	return 0;		
}