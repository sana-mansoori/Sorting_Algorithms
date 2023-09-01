#include<stdio.h>

void swap (int *a,int *b){
	int t=*a;
	*a=*b;
	*b=t;
}
int partition(int arr[],int low,int high,int *swapcount,int *compcount){
	int pivot=arr[high];
	int i=(low-1);
	for(int j=low;j<=high;j++){
		(*compcount)++;
		if(arr[j]<=pivot){
			i++;
			swap(&arr[i],&arr[j]);
			(*swapcount)++;
		}
	}
	swap(&arr[i+1],&arr[high]);
	(*swapcount)++;
	return (i+1);
}
void quicksort(int arr[],int low,int high,int *swapcount,int *compcount){
	if(low<high){
		int pi=partition(arr,low,high,swapcount,compcount);
		quicksort(arr,low,pi-1,swapcount,compcount);
		quicksort(arr,pi+1,high,swapcount,compcount);
	}
}
void printarray(int arr[],int size){
	for(int i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int main(){
	int compcount=0,swapcount=0,n,arr[100],i;
    printf("Enter size of array :");
    scanf("%d",&n);
    printf("Enter elements of array :");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
	quicksort(arr,0,n-1,&swapcount,&compcount);
        printf("the sorted array is :");
        for(i=0;i<n;i++){
            printf("%d ",arr[i]);
        }
        printf("\ntotal swaps %d",swapcount);
        printf("\ntotal compares %d",compcount);
	return 0;
}
