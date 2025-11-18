#include<stdio.h>
#include<conio.h>
#define Size 10
int stack[Size];
int top = -1;
void push(int);
void pop();
void display();
void push(int value)
{
    if(top == Size -1)
    {
        printf("\n Stack is Full!! overflow");
    }
    else{
        top++;
        stack[top] = value;
        printf("\n Insertion successful, %d is added to stack",value);
    }
}
void pop()
{
    if(top == -1)
        printf("The stack is empty!! Underflow");
    else
    {
        printf("\n Deleted :%d", stack[top]);
        top--;
    }
}
void display()
{
    if(top == -1)
        printf("The stack is empty!!");
    else{
        printf("The elements in stack are:\n");
        for(int i =top;i>=0;i--)
            printf("%d\n",stack[i]);
    }
}
void main()
{
    int value, choice;
    while(1){
        printf("\n\n******* MENU *******\n");
        printf("\n 1 for push");
        printf("\n 2 for pop");
        printf("\n 3 for display");
        printf("\n 4 for exit");
        printf("\n Enter the choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\n Enter the value to be inserted:");
            scanf("%d",&value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\n Wrong choice! Please re-enter!!");
        }
    }
}

