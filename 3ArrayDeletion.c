#include<stdio.h>
int printArray(int *arr,int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int IndexDelete(int arr[],int index,int n){
    for(int i=index;i<n-1;i++){
        arr[i] = arr[i+1];
    }
}
int main(){
    int arr[] = {3,6,3,67,97,34};
    int size = 6;
    printArray(arr,size);
    IndexDelete(arr,1,size);
    size--;
    printArray(arr,size);
}