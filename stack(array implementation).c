#include<stdio.h>
#include<conio.h>
#include<stdio.h>

int a[10],size=10,top=-1;

void push(int d)
{
    if(top==size-1)
    {
        printf("stack is full\n");
        return;
    }
    a[++top]=d;
}

void pop()
{
    if(top==-1)
    {
        printf("stack is empty\n");
        return;
    }
    printf("popped item: %d",a[top--]);
}

void display()
{
    if(top==-1)
    {
        printf("stack is empty\n");
        return;
    }
    printf("stack is: ");
    for(int i=0;i<=top;i++)
        printf("%d ",a[i]);
}

void menu()
{
    printf("\n\n1. push\n");
    printf("2. pop\n");
    printf("3. display\n");
}

int main()
{
    int d,ch;
    while(1)
    {
        menu();
        printf("enter the choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("enter the data to be pushed:");
            scanf("%d",&d);
            push(d);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        default:
            printf("wrong choice entry\n");
        }
    }
}
