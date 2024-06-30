#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    int *arr;
};
int isFull(struct stack *ptr){
    if(ptr->top==ptr->size-1)
       return 1;
    else
       return 0;
}
int isEmpty(struct stack *ptr){
    if(ptr->top==-1)
       return 1;
    else
       return 0;
}
void push(struct stack *ptr,int value){
    if(isFull(ptr))
       printf("Stack overflow\n");
    else{
        ptr->top++;
        ptr->arr[ptr->top] = value;
        printf("%d pushed IN\n",value);
    }
}
int pop(struct stack*ptr){
    if(isEmpty(ptr))
       printf("Stack Underflow");
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int main(){
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size*sizeof(int));
    push(s,59);
    push(s,90);
    push(s,19);
    printf("Popped out %d\n",pop(s));
    printf("Popped out %d\n",pop(s));
    printf("Popped out %d\n",pop(s));
}