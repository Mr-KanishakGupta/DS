#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;
struct Node *front = NULL, *rear = NULL;

struct Node* create(int value) {
    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

void push(int v) {
    struct Node *new_node = create(v);
    new_node->next = top;
    top = new_node;
}

void pop() {
    if (top == NULL) {
        printf("Underflow\n");
        return;
    }
    struct Node *temp = top;
    top = top->next;
    free(temp);
}

void enqueue(int v) {
    struct Node *new_node = create(v);
    if (rear == NULL) {
        front = rear = new_node;
        return;
    }
    rear->next = new_node;
    rear = new_node;
}

void dequeue() {
    if (front == NULL) {
        printf("Underflow\n");
        return;
    }
    struct Node *temp = front;
    front = front->next;
    if (front == NULL)
        rear = NULL;
    free(temp);
}

void display_s() {
    if (top == NULL) {
        printf("Underflow\n");
        return;
    }
    struct Node *temp = top;
    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void display_q() {
    if (front == NULL) {
        printf("Underflow\n");
        return;
    }
    struct Node *temp = front;
    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int c, v;
    do {
        printf("\n1.Push\n2.Pop\n3.Enqueue\n4.Dequeue\n5.Display Stack\n6.Display Queue\n7.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &c);

        switch (c) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &v);
                push(v);
                break;

            case 2:
                pop();
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &v);
                enqueue(v);
                break;

            case 4:
                dequeue();
                break;

            case 5:
                display_s();
                break;

            case 6:
                display_q();
                break;
        }
    } while (c != 7);

    return 0;
}
