#include<stdlib.h>
#include<stdio.h>

/* Merge sort algorithm : this consists two parts divide two parts and merge two of them */

/* recursively separate 2 pats */
int mergeSort(int arr[], int start, int end)
{
    if(start < end){  
        int mid =(end+start)/2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
 
        merge(arr, start, mid, end);
    }
}

/* Merging two parts */
int merge(int arr[], int start, int mid, int end) 
{
    int i, j, k;
    
    int left[ mid - start + 1], right[end - mid];
 
    for (i = 0; i <( mid - start + 1); i++)  // put them in to 2 separate arrays
        left[i] = arr[start + i];
    for (j = 0; j < (end - mid); j++)
        right[j] = arr[mid + 1+ j];
 
    
    i = 0; 
    j = 0; 
    k = start; 

    while ((i < (mid - start + 1)) && (j < (end - mid))){  // both of two arrays not finished
        if (left[i] <= right[j])
                arr[k++] = left[i++];
        else
                arr[k++] = right[j++];
    }
 
    while (i < (mid - start + 1)) // secound array is over
        arr[k++] = left[i++];

    while (j < (end - mid))  // first array is over
        arr[k++] = right[j++];
}

/* print array for test funtionality*/
void print(int arr[], int size){
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n\n");
}