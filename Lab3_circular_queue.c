#include<stdio.h>
#include<stdlib.h>
#define N 4
int queue[N], r=-1,f=-1;

int isFull()
{
    if((r+1)%N==f)
        return 1;
    else
        return 0;
}
int isEmpty()
{
    if(r==-1 &&f==-1)
        return 1;
    else
        return 0;
}
void enqueue(int x)
{
    if(isFull())
    {
        printf("Overflow.\n");
        return;
    }
    else if(isEmpty())
    {
        r=0;
        f=0;
    }
    else
        r=(r+1)%N;
    queue[r] = x;
    printf("%d is inserted.\n",x);
    return;
}
void dequeue()
{
    if(isEmpty())
    {
        printf("Underflow.\n");
        return;
    }
    else if(r==f)
    {
        printf("%d is deleted.\n",queue[f]);
        r=-1;
        f=-1;
    }
    else
    {
        printf("%d is deleted.\n",queue[f]);
        f=(f+1)%N;
    }
    return;
}
void Display()
{
    if(isEmpty())
        printf("Underflow.\n");
    else
    {
        printf("Elements in the queue are :");
        for(int i=f;i<=r;i++)
        {
            printf("%d ,",queue[i]);
        }
    }
    return;
}
void main()
{
    int choice, x;
    while(1)
    {
        printf("\nEnter 1 to enqueue, 2 to dequeue, 3 to Display, 4 to exit :");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter no. to insert :");
            scanf("%d",&x);
            enqueue(x);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            Display();
            break;
        case 4:
            exit(0);
        }
    }
}
