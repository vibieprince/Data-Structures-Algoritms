#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
void LinkedListTraversal(struct Node *ptr){
    while(ptr!=NULL){
        printf("Element %d\n",ptr->data);
        ptr = ptr->next;
    }
}
struct Node* insertAtIndex(struct Node*head,int data,int index){
    struct Node *newhead = (struct Node*)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i=0;
    while(i!=index-1){
        p = p->next;
        i++;
    }
    newhead->data = data;
    newhead->next = p->next; //p is the purana node and ptr is the insertion node here
    p->next = newhead;
    return head;
}
struct Node* insertAfterNode(struct Node*head,struct Node*node,int data){
    struct Node*newNode= (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = node->next;
    node->next = newNode;
    return head;
}
struct Node *insertAtFirst(struct Node*head,int data){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data; //here new data daldiya gaya in ptr
    return ptr; 
};
struct Node *insertAtEnd(struct Node*head,int data){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node *p = head;
    ptr->data = data;
    while(p->next!=NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}
int main(){
    struct Node *head;
    struct Node *first;
    struct Node *second;
    struct Node *third;

    head = (struct Node*)malloc(sizeof(struct Node));
    first = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    //Link head with first
    head->data = 56;
    head->next = first;

    first->data = 78;
    first->next = second;

    second->data = 90;
    second->next = third;
    
    third->data = 40;
    third->next = NULL;

    LinkedListTraversal(head);
    // head = insertAtFirst(head,89);
    // head = insertAtIndex(head,6,2);
    // head = insertAtEnd(head,49);
    head = insertAfterNode(head,second,67);
    printf("\nInsertion Done\n\n");
    LinkedListTraversal(head);
}