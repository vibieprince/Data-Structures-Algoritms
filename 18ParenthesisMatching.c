#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
    int top;
    int size;
    char *arr;
};
int isEmpty(struct stack *ptr){
    if(ptr->top == -1)
       return 1;
    else 
       return 0;
}
int isFull(struct stack *ptr){
    if(ptr->top == ptr->size-1)
       return 1;
    else
       return 0;
}
void push(struct stack *ptr,char val){
    if(isFull(ptr))
       printf("Stack overflow! cannot push %c into the stack\n",val);
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
char pop(struct stack *ptr){
    if(isEmpty(ptr))
      printf("Stack Underflow! Cannot pop\n");
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int parenthesis(char *str){
    struct stack *sp;
    sp->size = strlen(str);
    sp->top = -1;
    sp->arr = (char*)malloc(sp->size*sizeof(char));
    int i=0;
    while(str[i]!='\0'){
        if(str[i]=='(')
           push(sp,'(');
        else if(str[i]==')'){
            if(isEmpty(sp))
               return 0;
            pop(sp);
        }
        i++;
    }
    if(isEmpty(sp))
       return 1;
    else
       return 0;
}
int main(){
    char *str = "(3*(2-(8+1)))";
    if(parenthesis(str))
       printf("Parenthesis Matches");
    else
       printf("Parenthesis doesn't matches");
}