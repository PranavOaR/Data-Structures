#include <stdio.h>
#include <stdlib.h>

/* DLL Node structure */
typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} Node;

/* Header structure */
typedef struct header {
    int count;
    Node *head;
} Header;

/* Initialize list */
void initList(Header *list) {
    list->count = 0;
    list->head = NULL;
}

/* Insert at beginning */
void insertAtBeginning(Header *list, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory Allocation Failed\n");
        return;
    }

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = list->head;

    if (list->head != NULL)
        list->head->prev = newNode;

    list->head = newNode;
    list->count++;
}

/* Insert at end */
void insertAtEnd(Header *list, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory Allocation Failed\n");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        newNode->prev = NULL;
        list->head = newNode;
        list->count++;
        return;
    }

    Node *temp = list->head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
    list->count++;
}

/* Insert at position (1-based) */
void insertAtPosition(Header *list, int data, int pos) {
    if (pos < 1 || pos > list->count + 1) {
        printf("Invalid Position\n");
        return;
    }

    if (pos == 1) {
        insertAtBeginning(list, data);
        return;
    }

    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory Allocation Failed\n");
        return;
    }

    newNode->data = data;

    Node *temp = list->head;
    for (int i = 1; i < pos - 1; i++)
        temp = temp->next;

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
    list->count++;
}

/* Delete from beginning */
void deleteFromBeginning(Header *list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node *temp = list->head;
    list->head = temp->next;

    if (list->head != NULL)
        list->head->prev = NULL;

    free(temp);
    list->count--;
}

/* Delete from end */
void deleteFromEnd(Header *list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (list->head->next == NULL) {
        free(list->head);
        list->head = NULL;
        list->count--;
        return;
    }

    Node *temp = list->head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);
    list->count--;
}

/* Delete at position */
void deleteAtPosition(Header *list, int pos) {
    if (pos < 1 || pos > list->count) {
        printf("Invalid Position\n");
        return;
    }

    if (pos == 1) {
        deleteFromBeginning(list);
        return;
    }

    Node *temp = list->head;
    for (int i = 1; i < pos; i++)
        temp = temp->next;

    temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    list->count--;
}

/* Display DLL */
void display(Header *list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node *temp = list->head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    printf("Total nodes: %d\n", list->count);
}

/* Main function */
int main() {
    Header myList;
    initList(&myList);

    int choice, data, pos;

    while (1) {
        printf("\n===== DOUBLY LINKED LIST WITH HEADER =====\n");
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
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(&myList, data);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(&myList, data);
                break;

            case 3:
                printf("Enter data and position: ");
                scanf("%d%d", &data, &pos);
                insertAtPosition(&myList, data, pos);
                break;

            case 4:
                deleteFromBeginning(&myList);
                break;

            case 5:
                deleteFromEnd(&myList);
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPosition(&myList, pos);
                break;

            case 7:
                display(&myList);
                break;

            case 8:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }
}
