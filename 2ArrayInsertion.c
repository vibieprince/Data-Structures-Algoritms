#include<stdio.h>
void printArray(int *arr,int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int IndexInsert(int *arr,int size,int element,int capacity,int index){
    if(size>=capacity)
       return -1; // insertion unsuccessful
    for(int i=size-1;i>=index;i--){
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    return 1;
}
int main(){ //Modification 
    int arr[100] = {7,8,12,27,88};
    int size=5, k = IndexInsert(arr,5,45,100,3);
    if(k==-1)
       printf("Array Insertion unsuccessful");
    else{
        printf("Insertion Success!\n");
        size += 1;
        printArray(arr,size);
    }
}
