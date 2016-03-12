#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include<time.h> 

/*Test program for test heap sort works : genarate 50 random numbers and sorting*/
int main(){
	int arr[50] ;
	int i;
	srand(time(NULL));

	 for(i=0;i<50;i++)
        arr[i] = rand()%50;

	printf("Before Sort\n");
	print(arr,50);
	heapSort(arr,50);
	printf("After Sort\n");
	print(arr,50);	

	return 0;
}