#include <stdio.h>
#define MAX 5

int queue[MAX], front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1)
        printf("Queue Overflow\n");
    else {
        if (front == -1)
            front = 0;
        queue[++rear] = x;
    }
}

void dequeue() {
    if (front > rear || front == -1)
        printf("Queue Underflow\n");
    else
        printf("Deleted element: %d\n", queue[front++]);
}

void display() {
    if (front > rear || front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
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
