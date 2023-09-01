#include<stdio.h>
void selectionsort(int arr[],int n,int *compcount,int *swapcount){
	int i,j;
    for(i=0;i<n-1;i++){
        int min=i;
        for(j=i+1;j<n;j++){
            (*compcount)++;
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        if(min!=i){
            int temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
            (*swapcount)++;
        }
    }
}
int main(){
    int compcount=0,swapcount=0,n,arr[100],i;
    printf("Enter size of array :");
    scanf("%d",&n);
    printf("Enter elements of array :");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    selectionsort(arr,n,&compcount,&swapcount);
        printf("the sorted array is :");
        for(i=0;i<n;i++){
            printf("%d ",arr[i]);
        }
        printf("\nNumber of comparison : %d\n",compcount);
        printf("Number of swaps : %d",swapcount);
        return 0;
}
