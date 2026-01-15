#include <stdio.h>
#include <stdlib.h>

/* Node structure */
typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} Node;

/* Global head pointer */
Node *head = NULL;

/* Insert at beginning */
void insertAtBeginning(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory Allocation Failed\n");
        return;
    }

    newNode->data = data;

    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        return;
    }

    Node *last = head->prev;

    newNode->next = head;
    newNode->prev = last;
    last->next = newNode;
    head->prev = newNode;
    head = newNode;
}

/* Insert at end */
void insertAtEnd(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory Allocation Failed\n");
        return;
    }

    newNode->data = data;

    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        return;
    }

    Node *last = head->prev;

    last->next = newNode;
    newNode->prev = last;
    newNode->next = head;
    head->prev = newNode;
}

/* Insert at position (1-based) */
void insertAtPosition(int data, int pos) {
    if (pos < 1) {
        printf("Invalid Position\n");
        return;
    }

    if (pos == 1) {
        insertAtBeginning(data);
        return;
    }

    if (head == NULL) {
        printf("Position out of range\n");
        return;
    }

    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory Allocation Failed\n");
        return;
    }

    newNode->data = data;

    Node *temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;

    if (temp->next == head) {
        insertAtEnd(data);
        free(newNode);   // avoid memory leak
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

/* Delete from beginning */
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    Node *last = head->prev;
    Node *temp = head;

    head = head->next;
    head->prev = last;
    last->next = head;

    free(temp);
}

/* Delete from end */
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    Node *last = head->prev;
    Node *secondLast = last->prev;

    secondLast->next = head;
    head->prev = secondLast;

    free(last);
}

/* Delete at position */
void deleteAtPosition(int pos) {
    if (head == NULL || pos < 1) {
        printf("Invalid Operation\n");
        return;
    }

    if (pos == 1) {
        deleteFromBeginning();
        return;
    }

    Node *temp = head;
    for (int i = 1; i < pos && temp->next != head; i++)
        temp = temp->next;

    if (temp->next == head) {
        printf("Position out of range\n");
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

/* Display CSDLL */
void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node *temp = head;
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(head)\n");
}

/* Main function */
int main() {
    int choice, data, pos;

    while (1) {
        printf("\n===== CIRCULAR DOUBLY LINKED LIST =====\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete at Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scanf("%d", &data);
                insertAtBeginning(data);
                break;

            case 2:
                scanf("%d", &data);
                insertAtEnd(data);
                break;

            case 3:
                scanf("%d%d", &data, &pos);
                insertAtPosition(data, pos);
                break;

            case 4:
                deleteFromBeginning();
                break;

            case 5:
                deleteFromEnd();
                break;

            case 6:
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;

            case 7:
                display();
                break;

            case 8:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }
}
