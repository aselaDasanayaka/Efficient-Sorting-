#include<stdlib.h>
#include<stdio.h>
#include <time.h>
#include "quick.h"

/*Test average running time of QuickInSort() algorithm against the threshold value*/
int main()
{
    int ary[1000000];
    int i,j,k;
    srand(time(NULL));

    clock_t start, end;
    double cpu_time_used;
    double avg_time;

    for(k=8;k<=50;k++){
         for(j=0;j<30;j++){ 

            for(i=0;i<1000000;i++)
            ary[i] = rand();

            start = clock();
            QuicksortT(ary, 0, 1000000-1,k);
            end = clock();

            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            //printf("Time for one sort : %f\n",cpu_time_used );
            avg_time+=cpu_time_used;
        }
        printf("Average time for one sort when threshod is %d : %f\n",k,avg_time/30 );       
    }
    return 0;
}
