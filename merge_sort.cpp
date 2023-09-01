#include<stdio.h>
#include<stdlib.h>
void merge(int arr[],int l,int m,int r){
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    int L[n1],R[n2];
    for(i=0;i<n1;i++){
        L[i]=arr[l+i];
    }
    for(j=0;j<n2;j++){
        R[j]=arr[m+1+j];
    }
    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }
}

void mergesort(int arr[],int l,int r){
    if(l<r){
        int m=l+(r-l)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}
int main(){
    int flag=0,n,arr[100],i;
    printf("Enter size of array :");
    scanf("%d",&n);
    printf("Enter elements of array :");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    mergesort(arr,0,n-1);
        printf("the sorted array is :");
        for(i=0;i<n;i++){
            printf("%d ",arr[i]);
        }
        for(i=1;i<n;i++){
            if(arr[i]==arr[i-1]){
                printf("\nDuplicate elements found\n");
                flag=1;
                break;
            }
        }
        if(flag==0)
        printf("\nNo duplicate element found");
        return 0;
}
