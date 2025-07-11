#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;
typedef struct {
    Node* front;
    Node* rear;
}Queue;
void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}
int isEmpty(Queue* q) {
    return q->front ==NULL;
}
Node* createN() {
    Node* newNode = (Node*)malloc(sizeof(Node));
    int value;
    printf("Enter the data: ");
    scanf("%d", &value);
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void enQueue(Queue* q) {
    Node* newNode = createN();
    if (!newNode) {
        printf("Khonng cap phat bo nho duoc!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next=newNode;
        q->rear = newNode;
    }
}
void printQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    Node* temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main() {
    Queue q;
    initQueue(&q);
    enQueue(&q);
    enQueue(&q);
    enQueue(&q);

    printQueue(&q);
}