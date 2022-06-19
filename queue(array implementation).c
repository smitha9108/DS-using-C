#include<stdio.h>
#include<stdlib.h>

int a[10],size=10,lastindex=-1;

void enqueue(int d)
{
    if(lastindex==size-1)
    {
        printf("queue is full\n");
        return;
    }
    a[++lastindex]=d;
}

void dequeue()
{
    if(lastindex==-1)
    {
        printf("queue is empty\n");
        return;
    }
    for(int i=1;i<=lastindex;i++)
        a[i-1]=a[i];
    lastindex--;
}

void display()
{
    if(lastindex==-1)
    {
        printf("queue is empty\n");
        return;
    }
    printf("queue is: ");
    for(int i=0;i<=lastindex;i++)
        printf("%d ",a[i]);
}

void menu()
{
    printf("\n\n1. enqueue\n");
    printf("2. dequeue \n");
    printf("3. display\n");
}

int main()
{
    int ch,d;
    while(1)
    {
        menu();
        printf("enter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
        printf("enter data:");
        scanf("%d",&d);
        enqueue(d);
        break;
    case 2:
        dequeue();
        break;
    case 3:
        display();
        break;
    default:
        printf("wrong choice entry\n");
        }
    }
}
