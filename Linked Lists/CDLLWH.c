#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} Node;

typedef struct header {
    int count;
    Node *head;
} Header;

void initList(Header *list) {
    list->count = 0;
    list->head = NULL;
}

void insertAtBeginning(Header *list, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return;

    newNode->data = data;

    if (list->head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        list->head = newNode;
    } else {
        Node *last = list->head->prev;
        newNode->next = list->head;
        newNode->prev = last;
        last->next = newNode;
        list->head->prev = newNode;
        list->head = newNode;
    }

    list->count++;
}

void insertAtEnd(Header *list, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return;

    newNode->data = data;

    if (list->head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        list->head = newNode;
    } else {
        Node *last = list->head->prev;
        last->next = newNode;
        newNode->prev = last;
        newNode->next = list->head;
        list->head->prev = newNode;
    }

    list->count++;
}

void insertAtPosition(Header *list, int data, int pos) {
    if (pos < 1 || pos > list->count + 1) return;

    if (pos == 1) {
        insertAtBeginning(list, data);
        return;
    }

    if (pos == list->count + 1) {
        insertAtEnd(list, data);
        return;
    }

    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return;

    newNode->data = data;

    Node *temp = list->head;
    for (int i = 1; i < pos - 1; i++)
        temp = temp->next;

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;

    list->count++;
}

void deleteFromBeginning(Header *list) {
    if (list->head == NULL) return;

    if (list->head->next == list->head) {
        free(list->head);
        list->head = NULL;
    } else {
        Node *last = list->head->prev;
        Node *temp = list->head;
        list->head = temp->next;
        list->head->prev = last;
        last->next = list->head;
        free(temp);
    }

    list->count--;
}

void deleteFromEnd(Header *list) {
    if (list->head == NULL) return;

    if (list->head->next == list->head) {
        free(list->head);
        list->head = NULL;
    } else {
        Node *last = list->head->prev;
        Node *secondLast = last->prev;
        secondLast->next = list->head;
        list->head->prev = secondLast;
        free(last);
    }

    list->count--;
}

void deleteAtPosition(Header *list, int pos) {
    if (pos < 1 || pos > list->count) return;

    if (pos == 1) {
        deleteFromBeginning(list);
        return;
    }

    if (pos == list->count) {
        deleteFromEnd(list);
        return;
    }

    Node *temp = list->head;
    for (int i = 1; i < pos; i++)
        temp = temp->next;

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);

    list->count--;
}

void display(Header *list) {
    if (list->head == NULL) return;

    Node *temp = list->head;
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != list->head);

    printf("(head)\n");
}

int main() {
    Header myList;
    initList(&myList);

    int ch, data, pos;

    while (1) {
        printf("\n1.Insert Begin\n2.Insert End\n3.Insert Pos\n4.Delete Begin\n5.Delete End\n6.Delete Pos\n7.Display\n8.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
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
                return 0;
        }
    }
}
