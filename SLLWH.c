#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} Node;

typedef struct header{
    int count;
    Node *head;
} Header;

/* Initialize the header structure */
void initList(Header *list){
    list->count = 0;
    list->head = NULL;
}

/* Insert at beginning */
void insertAtBeginning(Header *list, int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("Memory Allocation Failed\n");
        return;
    }
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    list->count++;
}

/* Insert at end */
void insertAtEnd(Header *list, int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("Memory Allocation Failed\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if(list->head == NULL){
        list->head = newNode;
        list->count++;
        return;
    }

    Node *temp = list->head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    list->count++;
}

/* Insert at position (1-based) */
void insertAtPosition(Header *list, int data, int position){
    if(position < 1 || position > list->count + 1){
        printf("Invalid Position\n");
        return;
    }

    if(position == 1){
        insertAtBeginning(list, data);
        return;
    }

    Node *newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("Memory Allocation Failed\n");
        return;
    }
    newNode->data = data;

    Node *temp = list->head;
    for(int i = 1; i < position - 1; i++){
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    list->count++;
}

/* Delete from beginning */
void deleteFromBeginning(Header *list){
    if(list->head == NULL){
        printf("List is empty\n");
        return;
    }

    Node *temp = list->head;
    list->head = temp->next;
    free(temp);
    list->count--;
}

/* Delete from end */
void deleteFromEnd(Header *list){
    if(list->head == NULL){
        printf("List is empty\n");
        return;
    }

    if(list->head->next == NULL){
        free(list->head);
        list->head = NULL;
        list->count--;
        return;
    }

    Node *temp = list->head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
    list->count--;
}

/* Delete at position (1-based) */
void deleteAtPosition(Header *list, int position){
    if(position < 1 || position > list->count){
        printf("Invalid Position\n");
        return;
    }

    if(position == 1){
        deleteFromBeginning(list);
        return;
    }

    Node *temp = list->head;
    for(int i = 1; i < position - 1; i++){
        temp = temp->next;
    }

    Node *delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
    list->count--;
}

/* Display the list */
void display(Header *list){
    if(list->head == NULL){
        printf("List is empty\n");
        return;
    }

    Node *temp = list->head;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    printf("Total nodes: %d\n", list->count);
}

/* Main function */
int main(){
    Header myList;
    initList(&myList);

    int ch, n, pos;

    while(1){
        printf("\n--- SINGLY LINKED LIST WITH HEADER STRUCTURE ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete at Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch){
            case 1:
                printf("Enter data: ");
                scanf("%d", &n);
                insertAtBeginning(&myList, n);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &n);
                insertAtEnd(&myList, n);
                break;

            case 3:
                printf("Enter data and position: ");
                scanf("%d%d", &n, &pos);
                insertAtPosition(&myList, n, pos);
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
