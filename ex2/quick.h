#include<stdio.h>

/*Insertion sort for part 2*/
int insertionSort(int arr[], int n){
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;

       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
   return 0;
}

/*For print array*/
void print(int arr[], int size){
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n\n");
}

/*Quick sort : without optimization tecnique*/
void Quicksort(int arr[],int start,int end){  
  if(start >= end)
    return;
  
  int pidx = partition(arr,start,end);
  
  Quicksort(arr,start,pidx-1);// recursively calling quick sort
  Quicksort(arr,pidx+1,end);
}

/*Quick sort : with optimization tecnique*/
void QuicksortT(int arr[],int start,int end,int threshold){  // recursively calling quick sort
  if(start >= end)
    return;
    
  int size = end-start+1;
  int pidx = partition(arr,start,end);

  if(size<=threshold){
      insertionSort(arr, size);
  }else{
      QuicksortT(arr,start,pidx-1,threshold);
      QuicksortT(arr,pidx+1,end,threshold);  
  }  
}

/*partioning array*/
int partition(int arr[], int lo, int hi){  
  int pivot = arr[hi];
  int pidx = lo;
  int i,temp;
  
  for(i=lo;i<hi;i++){
    if(arr[i] <= pivot){
      temp = arr[i];
      arr[i] = arr[pidx];
      arr[pidx] = temp;
      pidx++;
    }
  }
  
  temp = arr[hi];
  arr[hi] = arr[pidx];
  arr[pidx] = temp;
  
  return pidx;
}
