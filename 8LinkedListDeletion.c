#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void linkedlistTraversal(struct Node*head){
    while(head!=NULL){
        printf("Element : %d\n",head->data);
        head = head->next;
    }
}
struct Node * deleteFirst(struct Node *head){
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
};
struct Node *deleteAtIndex(struct Node*head,int index){
    struct Node *p = head;
    struct Node *q = head->next;
    for(int i=0;i<index-1;i++){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
};
struct Node*deleteAtLast(struct Node*head){
    struct Node*p = head;
    struct Node*q = head->next;
    while(q->next!=NULL){
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
};
struct Node*deleteByValue(struct Node*head,int data){
    struct Node*p = head;
    struct Node*q = head->next;
    while(q->data!= data && q!=NULL){
        p = p->next;
        q = q->next;
    }
    if(q->data == data){
        p->next = q->next;
        free(q);
    }
    return head;
}
int main(){
    struct Node*head = (struct Node*)malloc(sizeof(struct Node));
    struct Node*second = (struct Node*)malloc(sizeof(struct Node));
    struct Node*third = (struct Node*)malloc(sizeof(struct Node));
    struct Node*fourth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 89;
    head->next = second;

    second->data = 49;
    second->next = third;

    third->data = 57;
    third->next = fourth;

    fourth->data = 38;
    fourth->next = NULL;

    linkedlistTraversal(head);
    // head = deleteFirst(head);
    // head = deleteAtIndex(head,2);
    // head = deleteAtLast(head);
    head = deleteByValue(head,57);
    printf("\nDeletion done\n\n");
    linkedlistTraversal(head);
}