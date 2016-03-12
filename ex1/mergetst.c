#include<stdlib.h>
#include<stdio.h>
#include <time.h>
#include "merge.h"

/*Test program for test merge sort works : genarate 50 random numbers and sorting*/
int main(){

	int arr[50] ;
	int i;
	srand(time(NULL));

	 for(i=0;i<50;i++)
        arr[i] = rand()%50;

	printf("Before Sort\n");
	print(arr,50);
	mergeSort(arr,0,50);
	printf("After Sort\n");
	print(arr,50);	
}