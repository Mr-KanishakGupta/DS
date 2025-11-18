#include<stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct Node* head = NULL;
struct Node* temp = NULL;
struct Node* last = NULL;
struct Node* prev = NULL;


struct Node* createNode(int data) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}


void push_at_begin(int data) {
    struct Node* newnode = createNode(data);

    newnode->next = head;
    head = newnode;

    printf("\nNode inserted at beginning.\n");
}


void insert_at_end(int data) {
    struct Node* newnode = createNode(data);

    if (head == NULL) {
        head = newnode;
    } else {
        last = head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newnode;
    }

    printf("Node inserted at end.\n");
}


void insert_at_pos(int data, int p) {
    if (p < 1) {
        printf("Invalid position!\n");
        return;
    }

    if (p == 1) {
        push_at_begin(data);
        return;
    }

    struct Node* newnode = createNode(data);
    temp = head;


    for (int i = 1; i < p - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;

    printf("Node inserted at position %d.\n", p);
}

void del_beg()
{
    if(head == NULL)
        printf("Empty list");
    else if(head->next == NULL){
        free(head);
        head = NULL;
    }
    else{
        temp = head;
        head = head->next;
        free(temp);
        temp = NULL;
        printf("Deletion from beginning");

    }

    return;
}
void del_end()
{
    if(head == NULL)
    {
        printf("Empty List");
    }
    else if(head->next == NULL){
        free(head);
        head = NULL;
    }
    else{
        temp = head;
        while(temp-> next ==NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        free(temp);
        prev->next = NULL;
        printf("Deletion from end");

    }

    return;
}

void del_pos(int pos){
    if(pos<1){
        printf("Invalid position");
        return;
    }
    if(pos == 1){
        del_beg();
    }
    else if(head == NULL)
    {
        printf("Empty List");
    }
    else if(head->next == NULL){
        free(head);
        head = NULL;
    }
    else{
        temp = head;
        for(int i = 0; i<pos;i++)
        {
            prev = temp;
            temp = temp->next;

        }
        prev->next = temp->next;
        free(temp);
    }
    return;
}


void display() {
    if (head == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    temp = head;
    printf("\nLinked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, data, p;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at Position\n");
        printf("3. Insert at End\n");
        printf("4. Deletion From Beginning\n");
        printf("5. Deletion from End\n");
        printf("6. Deletion from Position\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &data);
            push_at_begin(data);
            break;

        case 2:
            printf("Enter the data: ");
            scanf("%d", &data);
            printf("Enter the position: ");
            scanf("%d", &p);
            insert_at_pos(data, p);
            break;

        case 3:
            printf("Enter the data: ");
            scanf("%d", &data);
            insert_at_end(data);
            break;

        case 4:
            del_beg();
            break;
        case 5:
            del_end();
            break;
        case 6:
            printf("Enter the position: ");
            scanf("%d", &p);
            del_pos(p);
            printf("Deletion from position:%d", p);
            break;
        case 7:
            display();
            break;

        case 8:
            printf("\nExiting...\n");
            exit(0);

        default:
            printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}


