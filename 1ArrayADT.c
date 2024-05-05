#include<stdio.h>
#include<stdlib.h>
struct myArray{
    int totalSize; // memory to be rservded
    int usedSize; // memory to be used
    int *ptr;
};
void createArray(struct myArray* arr,int tSize,int uSize){
    // (*arr).totalSize = tSize;
    // (*arr).usedSize = uSize;
    // (*arr).ptr = (int *)malloc(tSize*sizeof(int));
    // ---------------------OR-------------------------
    arr->totalSize = tSize;
    arr->usedSize = uSize;
    arr->ptr = (int *)malloc(tSize*sizeof(int));
}
void showArray(struct myArray *arr){
    for(int i=0;i<arr->usedSize;i++){
        printf("%d\n",(arr->ptr)[i]);
    }
}
void setVal(struct myArray* arr){
    for(int i=0;i<arr->usedSize;i++){
        int n;
        printf("Enter the element %d ",i);
        scanf("%d",&n);
        (arr->ptr)[i] = n;
    }
}
int main(){
    struct myArray marks;
    createArray(&marks,100,2); // requests a memeory in a heap
    printf("We are running setVal now\n");
    setVal(&marks);
    printf("We are runnig showArray now\n");
    showArray(&marks);
}