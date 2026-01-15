#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int x) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }

    struct Node *temp = top;
    printf("Popped element: %d\n", temp->data);
    top = top->next;
    free(temp);
}

void display() {
    struct Node *temp = top;
    if (temp == NULL) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements: ");
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
        push(x);
    }

    display();

    printf("Popping elements:\n");
    for (int i = 0; i < n; i++)
        pop();

    display();
    return 0;
}
