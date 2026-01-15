#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

Node *head=NULL;

void insertAtBeginning(int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("Memory Allocation Failed.\n");
        return;
    }
    newNode->data=data;
    if(head==NULL){
        newNode->next=newNode;
        head=newNode;
        return;
    }
    Node * temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next=head;
    head= newNode;
}
void insertAtEnd(int data){
    Node *newNode =(Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("Memory Allocation Failed.\n");
        return;
    }
    newNode->data=data;
    if(head==NULL){
        newNode->next=newNode;
        head = newNode;
        return;
    }
    Node * temp = head;
    while(temp->next!=head){
        temp = temp->next;

    }
    temp->next = newNode;
    newNode->next = head;
}

void insertAtPosition(int data,int pos){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("Memory Allocation Failed.\n");
        return;
    }
    newNode->data=data;
    newNode->next=NULL;
    if(head==NULL){
        if(pos==1){
            newNode->next=newNode;
            head=newNode;
        }else{
            printf("Position out of range.\n");
            free(newNode);
        }
        return;
    }
    if(pos==1){
        Node * temp = head;
        while(temp->next!=head){
            temp = temp->next;
        }
        newNode->next = head;
        temp->next=newNode;
        head = newNode;
    }
    Node *temp = head;
    for(int i=1;i<pos-1&& temp->next!=head;i++){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void deleteFromBeginning(){
    if(head ==NULL){
        printf("List is empty.\n");
        return;
    }
    if(head->next==head){
        free(head);
        head = NULL;
        return;
    }
    Node * temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }
    Node *oldHead = head;
    temp ->next=head->next;
    head = temp->next;
    free(oldHead);
}
void deleteFromEnd(){
    if(head==NULL){
        printf("List is empty.\n");
        return;
    }
    if(head->next==head){
        free(head);
        head=NULL;
        return;
    }
    Node * temp = head;
    while(temp->next->next!=head){
        temp = temp->next;
    }
    free(temp->next);
    temp->next=head;
}
void deleteAtPosition(int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1) {
        deleteFromBeginning();
        return;
    }

    Node *temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;


    if (temp->next == head) {
        printf("Position out of range\n");
        return;
    }

    Node *del = temp->next;
    temp->next = del->next;
    free(del);
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node *temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(head)\n");
}

int main() {
    int choice, data, pos;

    while (1) {
        printf("\n===== Circular Singly Linked List Menu =====\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete at Position\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtPosition(data, pos);
                break;
            case 4:
                deleteFromBeginning();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
