#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    int *arr;
};
int isFull(struct stack *ptr){
    if(ptr->top == ptr->size-1)
       return 1;
    else
       return 0;
}
int isEmpty(struct stack *ptr){
    if(ptr->top == -1)
       return 1;
    else 
        return 0;
}
void push(struct stack *ptr,int val){
    if(isFull(ptr))
       printf("Stack Overflow : Can't push %d\n",val);
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
int pop(struct stack *ptr){
    if(isEmpty(ptr)){
       printf("Stack Underflow! Can't pop\n");
       return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
// top se aap jitna aap niche jana chahte ho whi element aap find karna chahre ho 
int peek(struct stack *ptr,int i){
    int arrInd = ptr->top-i+1;
    if(arrInd<0){
        printf("Not a valid position");
        return -1; // Assuming -1 will not be in the array.
    }
    else
        return ptr->arr[arrInd];
}
int main(){
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int*)malloc(s->size*sizeof(int));
    printf("Stack has been created succesfully\n");

    printf("Before Pushing : %d\n",isFull(s));
    printf("After Pushing : %d\n",isEmpty(s));
    push(s,56);
    push(s,67);
    push(s,53);
    push(s,35);
    push(s,24);
    push(s,5);
    push(s,96);
    push(s,90);                        
    push(s,52);
    push(s,58); // ----> Pushed 10 values
    push(s,96); // ----> Stack overflow since the size of the stack is 10
    printf("After Pushing Full : %d\n",isFull(s));
    printf("After Pushing Empty : %d\n",isEmpty(s));

    printf("Popped %d from the stack\n",pop(s));
    printf("Popped %d from the stack\n",pop(s));
    printf("Popped %d from the stack\n",pop(s));
    printf("Popped %d from the stack\n",pop(s));

    //printing values from the stack
    for(int j=0;j<s->top+1;j++){
        printf("The value at position %d is %d\n",j,peek(s,j));
    }
    
}