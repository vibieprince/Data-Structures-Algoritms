#include<stdlib.h>
#include<stdio.h>
struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};
void DoublyLLtraversal(struct Node*ptr){
    while(ptr!=NULL){
        printf("Element : %d\n",ptr->data);
        ptr = ptr->next;
    }
}
void reversedLLtraversal(struct Node*ptr){
    while(ptr!=NULL){
        printf("Element : %d\n",ptr->data);
        ptr = ptr->prev;
    }
}
void insertAtFirst(struct Node*ptr){
    struct Node*ptr = (struct Node*)malloc(sizeof(struct Node));
}
int main(){
    struct Node*head = (struct Node*)malloc(sizeof(struct Node));
    struct Node*second = (struct Node*)malloc(sizeof(struct Node));
    struct Node*third = (struct Node*)malloc(sizeof(struct Node));
    struct Node*fourth = (struct Node*)malloc(sizeof(struct Node));

    head->prev = NULL;
    head->data = 59;
    head->next = second;    

    second->prev = head;
    second->data = 90;
    second->next = third;

    third->prev = second;
    third->data = 29;
    third->next = fourth;

    fourth->prev = third;
    fourth->data = 78;
    fourth->next = NULL;

    DoublyLLtraversal(head);
    printf("\n\n");
    reversedLLtraversal(fourth);
}