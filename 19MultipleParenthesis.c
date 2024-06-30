#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct stack{
    int top;
    int size;
    char *arr;
};
int isEmpty(struct stack*ptr){
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
void push(struct stack*ptr,char val){
    if(isFull(ptr))
       printf("Stack Overflow! Cannot push %d\n",val);
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
int match(char a,char b){
    if((a=='{' && b=='}') || (a=='(' && b==')') || (a=='[' && b==']'))
      return 1;
 return 0;
}
char pop(struct stack *ptr){
    if(isEmpty(ptr))
      printf("Stack Underflow! cannot pop");
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int MultipleParenthesis(char *str){
    struct stack *sp;
    sp->size = strlen(str);
    sp->top=-1;
    sp->arr = (char *)malloc(sp->size*sizeof(char));
    char popped;
    int i=0;
    while(str[i]!='\0'){
        if(str[i]=='[' || str[i] == '{' || str[i] == '(')
          push(sp,str[i]);
        else if(str[i]=='}' || str[i] == ']' || str[i] == ')'){
            if(isEmpty(sp)){
              return 0;
            }
            popped = pop(sp);
            if(!match(popped,str[i]))
               return 0;
        }
        i++;
    }
    if(isEmpty(sp))
        return 1;
    else
        return 0;
}
int main(){
    char *str = "{7-(3-2)+[8=(99-11)]}";
    // char *str = "(3*((2-(8+1)))";
    if(MultipleParenthesis(str))
       printf("The parenthesis is balanced");
    else
       printf("The parenthesis is not balanced");
       
}