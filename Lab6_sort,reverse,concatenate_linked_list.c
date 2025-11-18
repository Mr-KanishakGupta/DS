#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}


void insert_at_end(struct Node** head, int data) {
    struct Node* newnode = createNode(data);

    if (*head == NULL) {
        *head = newnode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
}
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

struct Node* reverse(struct Node* head) {
    struct Node *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;   
}

struct Node* sort(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct Node *i, *j;
    int temp;

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    return head;
}

struct Node* concatenate(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct Node* temp = head1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    return head1;
}

int main() {
    struct Node *list1 = NULL, *list2 = NULL;
    int choice, data;

    while (1) {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert into List 1\n");
        printf("2. Display List 1\n");
        printf("3. Sort List 1\n");
        printf("4. Reverse List 1\n");
        printf("5. Create List 2 & Concatenate with List 1\n");
        printf("6. Display List 2\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insert_at_end(&list1, data);
                break;

            case 2:
                display(list1);
                break;

            case 3:
                list1 = sort(list1);
                printf("List sorted.\n");
                break;

            case 4:
                list1 = reverse(list1);
                printf("List reversed.\n");
                break;

            case 5:
                printf("Enter elements for List 2 (-1 to finish):\n");
                while (1) {
                    scanf("%d", &data);
                    if (data == -1) break;
                    insert_at_end(&list2, data);
                }
                list1 = concatenate(list1, list2);
                printf("Lists concatenated.\n");
                break;

            case 6:
                display(list2);
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
