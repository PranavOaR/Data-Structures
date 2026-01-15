#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

void enqueue(int x) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = NULL;

    if (rear == NULL)
        front = rear = newNode;
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    struct node *temp;

    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    temp = front;
    printf("Deleted element: %d\n", front->data);
    front = front->next;

    if (front == NULL)   // IMPORTANT when last node is deleted
        rear = NULL;

    free(temp);
}

void display() {
    struct node *temp = front;

    if (temp == NULL) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element: ");
        scanf("%d", &x);
        enqueue(x);
    }

    display();

    printf("Deleting elements:\n");
    for (int i = 0; i < n; i++)
        dequeue();

    display();

    return 0;
}
