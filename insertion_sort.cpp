#include<stdio.h>
void insertionsort(int arr[],int n,int *compcount,int *shiftcount){
	int i;
    for(i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        (*shiftcount)++;
        while(j>=0 && arr[j]>key){
            (*compcount)++;
            arr[j+1]=arr[j];
                j--;
                (*shiftcount)++;
            }
            arr[j+1]=key;
            (*shiftcount)++;
    }
}
int main(){
    int compcount=0,shiftcount=0,n,arr[100],i;
    printf("Enter size of array :");
    scanf("%d",&n);
    printf("Enter elements of array :");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    insertionsort(arr,n,&compcount,&shiftcount);
        printf("the sorted array is :");
        for(i=0;i<n;i++){
            printf("%d ",arr[i]);
        }
        printf("\nNumber of comparison : %d\n",compcount);
        printf("Number of shifts : %d",shiftcount);
        return 0;
}
