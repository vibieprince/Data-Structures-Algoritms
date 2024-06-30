#include<stdio.h>
#include<stdlib.h>
struct Node*top = NULL;
struct Node{
    int data;
    struct Node *next;
};
void LinkedListTraversal(struct Node*ptr){
    while(ptr!=NULL){
        printf("Element : %d\n",ptr->data);
        ptr=ptr->next;
    }
}
int peek(int pos){
    struct Node*ptr = top;
    for(int i=1;(i<pos && ptr!=NULL);i++){
        ptr = ptr->next;
    }
    if(ptr!=NULL)
      return ptr->data;
    else
       return -1;
}
int isEmpty(struct Node*ptr){
    if(top==NULL)
       return 1;
    else
       return 0;
}
int isFull(struct Node*ptr){
    struct Node*n = (struct Node*)malloc(sizeof(struct Node));
    if(n==NULL)
       return 1;
    else
       return 0;
}
struct Node* push(struct Node*top,int x){
    if(isFull(top))
       printf("Stack Overflow\n");
    else{
        struct Node* n = (struct Node *)malloc(sizeof(struct Node)); // nayi node banayi
        n->data = x; //data allocate kardiya
        n->next = top; // top change ki
        top = n; // nayi node se point karwa diya
        return top;
    }
}
int pop(struct Node* tp){
    if(isEmpty(tp))
       printf("Stack Underflow\n");
    else{
        struct Node* n = tp;
        top =  tp->next;
        int x = n->data; 
        free(n);
        return x;
    }
}
int main(){
    top = push(top,48);
    top = push(top,9);
    top = push(top,12);
    top = push(top,30);
    LinkedListTraversal(top);
    printf("Value at position %d is %d",1,peek(1));
    
}