// Linked Lists creation and traversal
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node * next;
};
void LinkedListTraversal(struct Node *ptr){
    while(ptr != NULL){
        printf("Element : %d\n",ptr->data);
        ptr = ptr->next;
    }
}
int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    //Allocation memory for nodes in the linked list in Heap
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

    //Links first and second notes
    head->data = 7;
    head->next = second;

    //Links second and third node
    second->data = 11;
    second->next = third;

    //Links third and fourth node
    third->data = 13;
    third->next = fourth;

    //Terminate the list at the fourth node
    fourth->data = 56;
    fourth->next = NULL;

    LinkedListTraversal(head);
    return 0;
}