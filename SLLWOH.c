#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

Node *head =NULL;

void inserAtBeginning(int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("Memory Allocation Failed.\n");
        return;
    }
    newNode->data=data;
    newNode->next=head;
    head=newNode;
}

void insertAtEnd(int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("Memory Allocation Failed.\n");
        return;
    }
    newNode->data=data;
    newNode->next = NULL;
    if(head==NULL){
        head = newNode;
        return;
    }
    Node *temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next=newNode;
}

void insertAtPosition(int data,int position){
    if(position<1){
        printf("Invalid Position");
        return;
    }
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("Memory Allocation Failed.\n");
        return;
    }
    newNode->data=data;
    if(position==1){
        newNode->next =head;
        head=newNode;
        return;
    }
    Node *temp = head;
    for(int i=1;i<position-1 && temp!=NULL;i++){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFromBeginning(){
    if(head==NULL){
        printf("List is empty.\n");
        return;
    }
    Node *temp = head;
    head=head->next;
    free(temp);
}
void deleteFromEnd(){
    if(head==NULL){
        printf("List is empty.\n");
        return;
    }
    if(head->next==NULL){
        free(head);
        head=NULL;
        return;
    }
    Node *temp =head;
    while(temp->next->next!=NULL){
        temp = temp->next;

    }
    free(temp->next);
    temp->next = NULL;
}
void deleteAtPosition(int position){
    if(head==NULL){
        printf("List is empty.\n");
        return;
    }
    if(position<1){
        printf("Invalid Position.\n");
        return;
    }
    if(position==1){
        Node *temp = head;
        head=head->next;
        free(temp);
        return;
    }
    Node *temp = head;
    for(int i=1;i<position-1 && temp!=NULL;i++){
        temp = temp->next;
    }
    Node * delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
}
void display(){
    if(head==NULL){
        printf("List is empty.\n");
        return;
    }
    Node *temp = head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL.\n");
}
int main(){
    int ch,n,pos;
    while(1){
        printf("---SINGLY LINKED LIS---\n1.Insert Start\n2.Insert End\n3.Insert Postion\n4.Delete Start\n5.Delete End\n6.Delete Position\n7.Display\n8.Exit\nChoice:\n");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                printf("Enter data to insert at start:\n");
                scanf("%d",&n);
                inserAtBeginning(n);
                break;
            case 2:
                printf("Enter data to insert at end:\n");
                scanf("%d",&n);
                insertAtEnd(n);
                break;
            case 3:
                
                printf("Enter data and position to insert:\n");
                scanf("%d%d",&n,&pos);
                insertAtPosition(n,pos);
                break;
            case 4:
                printf("Deleting from begining.\n");
                deleteFromBeginning();
                break;
            case 5:
                printf("Deleting at end.\n");
                deleteFromEnd();
                break;
            case 6:
                printf("Enter position to delete:\n");
                scanf("%d",&pos);
                deleteAtPosition(pos);
                break;
            case 7:
                printf("Displaying SLL Items:\n");
                display();
                break;
            case 8:
                printf("Exiting.\n");
                free(head);
                return 0;
            default:
                printf("Invalid Choice.\n");
        }
    }
}