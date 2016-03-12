#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* create heap data stracture*/
int * heapCreate(int size){
	int* tmp = malloc(sizeof(int)*(size+1));
	tmp[0]=0;
	return tmp;
}

/* destroy heap data stracture*/
int * heapDestroy(int * head){
	free(head);
	return NULL;
} 

/* Insert element in to the heap */
int heapInsert(int item,int * head){
	head[head[0]+1]=item;
	head[0]++;
	heapShiftUp(head);
	return 0;
}

/* Remove element from the heap */
int heapRemove(int * head){
	int tmp = head[1];
	head[1] = head[head[0]];
	head[0]--;
	heapShiftDown(head);
	return tmp;
}


int heapShiftUp(int * head){
	int i = head[0];
	while((int)floor(log(i)/log(2)) > 0){
		if(head[i/2]<head[i]){
			int temp = head[i];
			 head[i] = head[i/2];
			head[i/2]= temp;
			i/=2; 
		}else
			break;
	}
	return 0;
} 

int heapShiftDown(int * head){
	int max = head[0];
	int i=1;
	while(((int)floor(log(i)/log(2)) < (int)floor(log(max)/log(2))) && (2*i <= head[0]) ){
		if(head[i*2]>head[i*2+1] && head[i]<head[i*2]){
				int temp = head[i];
				head[i] = head[i*2];
				head[i*2]= temp;
				i*=2;
		}else if(head[i*2]<head[(i*2)+1] && head[i]<head[(i*2)+1]){
				int temp1 = head[i];
				head[i] = head[(i*2)+1];
				head[(i*2)+1]= temp1;
				i=(i*2)+1;		
		}else if(head[0]==2 && head[i*2]>head[i]){
				int temp = head[i];
				head[i] = head[i*2];
				head[i*2]= temp;
				i*=2;
		}else if(head[i]<head[i*2] && (2*i <= head[0])){
				int temp = head[i];
				head[i] = head[i*2];
				head[i*2]= temp;
				i*=2;
		}else
			break;
	}
	return 0;
}

/* print heap */
void heapPrint(int * head){
	int max =head[0];
	int i;
	for(i=1;i<=max;i++){
		printf("items of level %d element %d : %d\n",(int)floor(log(i)/log(2)),i,head[i] );
	}
		
}

/* convert array in to heap */
int * heapify(int arr[],int size){
	int * head = heapCreate(size);
	int i;
	for(i=0;i<size;i++)
		heapInsert(arr[i],head);
	return head;
}

/*heap sort Implimentation*/
int heapSort(int arr[],int size){
	int * tmp = heapify (arr,size);
	int i;

	for(i=size-1;i>=0;i--){
		int k =heapRemove(tmp);
		arr[i]=k;
	}		
	tmp = heapDestroy(tmp);
	return 0;
}

/*print an array*/
void print(int arr[], int size){
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n\n");
}