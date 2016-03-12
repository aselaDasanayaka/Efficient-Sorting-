#include<stdio.h>
#include<time.h> 
#include "heap.h"

/*Test average running time for heap sort*/
int main(){

    int ary[1000000];
    int i,j;
    srand(time(NULL));

    clock_t start, end;
    double cpu_time_used;
    double avg_time;

    for(j=0;j<30;j++){ 

        for(i=0;i<1000000;i++)
        ary[i] = rand();

        start = clock();
        heapSort(ary,1000000);
        end = clock();

        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Time for one sort : %f\n",cpu_time_used );
        avg_time+=cpu_time_used;
    }
 	printf("Average time for one sort out of 30 : %f\n",avg_time/30 );
    
    return 0;
}