#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
    int top;
    int size;
    char *str;
};
int isEmpty(struct stack *ptr){
    if(ptr->top==-1)
      return 1;
    else
      return 0;
}
int isFull(struct stack *ptr){
    if(ptr->top==ptr->size-1)
       return 1;
    else 
       return 0;
}
int stackTop(struct stack *ptr){
    return ptr->str[ptr->top];
}
void push(struct stack *ptr,char str){
    if(isFull(ptr))
       printf("Stack Overflow! Cannot push %c",str);
    else{
        ptr->top++;
        ptr->str[ptr->top] = str;
    }
}
char pop(struct stack *ptr){
    if(isEmpty(ptr))
       printf("Stack Underflow! cannot pop");
    else{
        char c = ptr->str[ptr->top];
        ptr->top--;
        return c;
    }
}
char operator(char ch){
    if((ch =='/') ||(ch =='*') ||(ch =='+') || (ch =='=') || (ch =='-') || (ch=='%'))
       return 1;
    else
       return 0;
}
int precedence(char ch){
    if(ch=='*' || ch=='/')
       return 3;
    if(ch=='+' || ch=='-')
       return 2;
    else
       return 0;
}
char *InfixToPostfix(char *str){
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->top = -1;
    sp->size = strlen(str);
    sp->str = (char *)malloc(sp->size*sizeof(char));
    char *postfix = (char *)malloc((strlen(str)+1)*sizeof(char));
    int i = 0; // Tracks infix traversal
    int j = 0; // Tracks Postfix addition
    while(str[i]!='\0'){
        if(!operator(str[i])){
           postfix[j] = str[i];
           j++;
           i++;
        }
        else{
            if(precedence(str[i])>precedence(stackTop(sp))){
                push(sp,str[i]);
                i++;
            }
            else{
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while(!isEmpty(sp)){
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}
int main(){
    char *str = "x-y/z-k*d";
    // char *str = "a-b+t/6";
    // char *str = "a-b";
    printf("Postfix is %s",InfixToPostfix(str));
}