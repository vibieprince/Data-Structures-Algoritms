#include<stdio.h>
#include<stdlib.h>
struct Queue{
    int size;
    int front;
    int rear;
    int *arr;
};
int isFull(struct Queue *q){
    if(q->rear==q->size-1)
      return 1;
    return 0;
}
int isEmpty(struct Queue *q){
    if(q->front==q->rear)
      return 1;
    return 0;
}
void enqueue(struct Queue *q,int val){
    if(isFull(q))
      printf("Queue Overflow\n");
    else{
      q->rear++;
      q->arr[q->rear] = val;
      printf("Enqued element : %d\n",val);
    }
}
int dequeue(struct Queue *q){
    int a=-1;
    if(isEmpty(q))
       printf("This Queue is Empty\n");
    else{
        q->front++;
        a = q->arr[q->front];
    }
    return a;
}
int main(){
    struct Queue q;
    q.size = 4;
    q.front = q.rear = 0;
    q.arr = (int *)malloc(q.size*sizeof(int));
    enqueue(&q, 90);
    enqueue(&q, 12);
    enqueue(&q, 1);
    printf("%d element dequeued\n",dequeue(&q));
    printf("%d element dequeued\n",dequeue(&q));
    // printf("%d element dequeued\n",dequeue(&q));
    enqueue(&q,45);
    enqueue(&q,45);
    enqueue(&q,45);
    if(isEmpty(&q))
      printf("Queue is empty\n");
    if(isFull(&q))
      printf("Queue is Full\n");
    return 0;
}