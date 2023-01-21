#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct
{
    int item[SIZE];
    int rear, front;
} Queue;

// function prototypes
void initQueue(Queue *);
void enqueue(Queue *, int);
int dequeue(Queue *);

void initQueue(Queue *qp)
{
    qp->front = 0;
    qp->rear = 0;
}

void enqueue(Queue *qp, int v)
{
    if (qp->rear ==SIZE){
        printf("Queue overflow\n");
        return;
    }
    qp->item[qp->rear] = v;
    qp->rear++;
}

int dequeue(Queue *qp)
{
    if (qp->rear==qp->front){
        return -9999;
    }
    int v = qp->item[qp->front];
    qp->front++;
    return v;
}

int main(){
    Queue q;
    initQueue(&q);
    enqueue(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 15);
    enqueue(&q, 20);

    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));

    printf("%d\n", dequeue(&q));

    return 0;
}