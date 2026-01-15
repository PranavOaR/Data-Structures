#include <stdio.h>
#include <stdlib.h>

/* Node structure */
typedef struct node {
    int data;
    struct node *next;
} Node;

/* Header structure */
typedef struct header {
    int count;
    Node *head;
} Header;

/* Initialize CSLL */
void initList(Header *list) {
    list->count = 0;
    list->head = NULL;
}

/* Insert at Beginning */
void insertAtBeginning(Header *list, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory Allocation Failed.\n");
        return;
    }

    newNode->data = data;

    if (list->head == NULL) {
        newNode->next = newNode;
        list->head = newNode;
    } else {
        Node *temp = list->head;
        while (temp->next != list->head)
            temp = temp->next;

        newNode->next = list->head;
        temp->next = newNode;
        list->head = newNode;
    }

    list->count++;
}

/* Insert at End */
void insertAtEnd(Header *list, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory Allocation Failed.\n");
        return;
    }

    newNode->data = data;

    if (list->head == NULL) {
        newNode->next = newNode;
        list->head = newNode;
    } else {
        Node *temp = list->head;
        while (temp->next != list->head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = list->head;
    }

    list->count++;
}

/* Insert at Position (1-based) */
void insertAtPosition(Header *list, int data, int pos) {
    if (pos < 1 || pos > list->count + 1) {
        printf("Position out of range.\n");
        return;
    }

    if (pos == 1) {
        insertAtBeginning(list, data);
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory Allocation Failed.\n");
        return;
    }

    newNode->data = data;

    Node *temp = list->head;
    for (int i = 1; i < pos - 1; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;

    list->count++;
}

/* Delete from Beginning */
void deleteFromBeginning(Header *list) {
    if (list->head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (list->head->next == list->head) {
        free(list->head);
        list->head = NULL;
    } else {
        Node *temp = list->head;
        while (temp->next != list->head)
            temp = temp->next;

        Node *oldHead = list->head;
        temp->next = oldHead->next;
        list->head = oldHead->next;
        free(oldHead);
    }

    list->count--;
}

/* Delete from End */
void deleteFromEnd(Header *list) {
    if (list->head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (list->head->next == list->head) {
        free(list->head);
        list->head = NULL;
    } else {
        Node *temp = list->head;
        while (temp->next->next != list->head)
            temp = temp->next;

        free(temp->next);
        temp->next = list->head;
    }

    list->count--;
}

/* Delete at Position */
void deleteAtPosition(Header *list, int pos) {
    if (pos < 1 || pos > list->count) {
        printf("Position out of range.\n");
        return;
    }

    if (pos == 1) {
        deleteFromBeginning(list);
        return;
    }

    Node *temp = list->head;
    for (int i = 1; i < pos - 1; i++)
        temp = temp->next;

    Node *delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);

    list->count--;
}

/* Display CSLL */
void display(Header *list) {
    if (list->head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *temp = list->head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != list->head);

    printf("(head)\n");
    printf("Total nodes: %d\n", list->count);
}

/* Main */
int main() {
    Header myList;
    initList(&myList);

    int choice, data, pos;

    while (1) {
        printf("\n===== CSLL WITH HEADER STRUCTURE =====\n");
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
                insertAtBeginning(&myList, data);
                break;
            case 2:
                scanf("%d", &data);
                insertAtEnd(&myList, data);
                break;
            case 3:
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
                printf("Invalid choice!\n");
        }
    }
}
