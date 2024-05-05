// Binary Search is used when array is sorted
#include<stdio.h>
void selectionSort(int arr[],int size){
    int minIndex,temp;
    for(int i=0;i<size-1;i++){
        minIndex = i;
        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[minIndex])
               minIndex = j;
        }
        // we are swapping the numbers after finding the lesser number
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}
int BinarySearch(int arr[],int size,int search){
    selectionSort(arr,size);
    int low=0,mid,high=size;
    //keep searching umtil high and low converges
    while(low<=high){
        mid = (low+high)/2;
        if(arr[mid]==search)
           return mid;
        if(arr[mid]<search)
           low = mid+1;
        else 
            high = mid-1;
    }
    return -1;
}
int main(){
    int arr[] = {5,635,6,45,7,55};
    int size = 6,search = 635;
    int k = BinarySearch(arr,size,search);
    if(k==-1)
       printf("%d is not present in the array",search);
    else
       printf("%d is present at the index %d",search,k);
}