#include<stdio.h>
#include<time.h> 
#include "merge.h"

/*Average runnging time for merge sort*/
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
        mergeSort(ary,0,1000000-1);
        end = clock();

        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Time for one sort : %f\n",cpu_time_used );
        avg_time+=cpu_time_used;
    }

 	printf("\nAverage time for one sort out of 30 : %f\n",avg_time/30 );
    return 0;
}