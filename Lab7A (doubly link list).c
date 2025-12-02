#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    struct Node *next;
    struct Node *prev;
}Node;
Node *head=NULL,*temp,*newNode,*n;
Node * create(int value)
{
    newNode=malloc(sizeof(Node));
    newNode->val=value;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}
void insert_left(int v,int data)
{
    n=create(v);
    if(head==NULL){
        head=n;
    }
    else{
            temp=head;
    while(temp->val!=data)
    {

        if(temp->next==NULL )
        {

            printf("Invalid"); return 0;
        }
        temp=temp->next;
    }
    n->next=temp->next;
    n->prev=temp;
    temp->next=n;
    temp=n->next;
    temp->prev=n;
    }
}
void delete(int v)
{

    if(head==NULL)
    {

        printf("Empty"); return 0;
    }
    else{
            temp=head;
    while(temp->val!=v)
    {

        if(temp->next==NULL)
        {

            printf("invalid");
            return 0;

        }
        temp=temp->next;

    }
    }
}
void display()
{

    if(head==NULL)
    {

        printf("Empty"); return 0;
    }
    else{
        temp=head;
        while(temp!=NULL)
        {
            printf("%d\t",temp->val);
            temp=temp->next;

        }
}
}
int main()
{
    int c, v, p;
    do {
        printf("\n1.insert\n2.delete\n3. display\n4. exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &c);

        switch (c) {
            case 1:
                printf("Enter value and target: ");
                scanf("%d%d", &v,&c);
                insert_left(v,c);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &v);
                delete(v);
                break;
            case 3:
                display();
                break;

        }
    } while (c != 4);

    return 0;
}
