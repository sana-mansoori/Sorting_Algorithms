#include<stdio.h>
void bubblesort(int arr[],int n,int *compcount,int *swapcount){
	int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
        	(*compcount)++;
        	if(arr[j]>arr[j+1]){
        		int temp=arr[j];
            	arr[j]=arr[j+1];
            	arr[j+1]=temp;
            	(*swapcount)++;
			}
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
    bubblesort(arr,n,&compcount,&swapcount);
        printf("the sorted array is :");
        for(i=0;i<n;i++){
            printf("%d ",arr[i]);
        }
        printf("\nNumber of comparison : %d\n",compcount);
        printf("Number of swaps : %d",swapcount);
        return 0;
}
