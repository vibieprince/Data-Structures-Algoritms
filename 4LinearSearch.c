// Linear Search is done by Traversal technique
#include<stdio.h>
int LinearSearch(int *arr,int size,int n){
    for(int i=0;i<size;i++){
        if(arr[i]==n)
           return i;    
    }
    return -1;
}
int main(){
    int arr[] = {5,635,6,45,7,55};
    int size = 6,search = 45;
    int k = LinearSearch(arr,size,search);
    if(k==-1)
       printf("%d is not present in the array!",search);
    else 
        printf("%d is found at index %d",search,k);
    return 0;
}