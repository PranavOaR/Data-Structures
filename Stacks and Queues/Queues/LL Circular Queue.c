#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int x) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;

    if (front == NULL) {
        front = rear = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = front;
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    if (front == rear) {
        printf("Deleted: %d\n", front->data);
        free(front);
        front = rear = NULL;
    } else {
        struct Node *temp = front;
        printf("Deleted: %d\n", temp->data);
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

void display() {
    if (front == NULL) {
        printf("Queue is Empty\n");
        return;
    }

    struct Node *temp = front;
    printf("Queue elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    return 0;
}
