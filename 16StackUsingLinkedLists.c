// Implementation of stack using linked list 
#include<stdio.h>
#include<stdlib.h>
struct Node *top = NULL;
struct Node{
    int data;
    struct Node *next;
};
void LinkedListTraversal(struct Node *ptr){
    while(ptr != NULL){
        printf("Element : %d\n",ptr->data);
        ptr = ptr->next;
    }
}
int isEmpty(struct Node *top){
    if(top==NULL)
       return 1;
    else
        return 0;
}
int isFull(struct Node *top){
    struct Node*p = (struct Node *)malloc(sizeof(struct Node));
    if(p==NULL)
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
// int pop(struct Node**top){
//     if(isEmpty(*top))
//        printf("Stack Underflow\n");
//     else{
//         struct Node* n = *top;
//         *top =  (*top)->next;
//         int x = n->data; 
//         free(n);
//         return x;
//     }
// }
// to get rid of this ** and & things, declare top as a global variable
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
    top = push(top,78);
    top = push(top,98);
    top = push(top,34);
    LinkedListTraversal(top);
    int element = pop(top);
    printf("Popped out element : %d\n",element);
    LinkedListTraversal(top);
}