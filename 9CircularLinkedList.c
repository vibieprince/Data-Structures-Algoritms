#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
void linkedListTraversal(struct Node*head){
    struct Node*ptr = head;
    do{
        printf("Element : %d\n",ptr->data);
        ptr = ptr->next;
    }while(ptr!=head);
}
struct Node*insertAtFirst(struct Node* head,int data){
    struct Node*ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data; //ptr is the insertion node here
    struct Node *p = head->next;
    while(p->next!=head){
        p = p->next;
    }
    // here p is pointing at last node
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}
int main(){
    struct Node*head = (struct Node*)malloc(sizeof(struct Node));
    struct Node*second = (struct Node*)malloc(sizeof(struct Node));
    struct Node*third = (struct Node*)malloc(sizeof(struct Node));
    struct Node*fourth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 67;
    head->next = second;

    second->data = 90;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 29;
    fourth->next = head;

    linkedListTraversal(head);
    head = insertAtFirst(head,80);
    printf("\nInsertion Done\n\n");
    linkedListTraversal(head);
    return 0;
}