#include<stdio.h>
#include<conio.h>

int a[10],size=10,lastindex=-1;

int isFull()
{
    return lastindex==size-1?1:0;
}

int isEmpty()
{
    return lastindex==-1?1:0;
}

void insertFront(int d)
{
    int i=lastindex;
    if(isFull())
    {
        printf("array is full\n");
        return;
    }
    for(i=lastindex;i>=0;i--)
        a[i+1]=a[i];
    a[0]=d;
    lastindex++;
}

void insertRear(int d)
{
    if(isFull())
    {
        printf("array is full\n");
        return;
    }
    a[++lastindex]=d;
}

void deleteFront()
{
    int i;
    if(isEmpty())
    {
        printf("array is empty\n");
        return;
    }
    for(i=1;i<=lastindex;i++)
        a[i-1]=a[i];
    lastindex--;
}

void deleteRear()
{
    if(isEmpty())
    {
        printf("array is empty\n");
        return;
    }
    lastindex--;
}

void reverse()
{
    if(isEmpty()||lastindex==0)
        return;
    int i=0,j=lastindex,temp;
    while(i<j)
    {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        i++;
        j--;
    }
}

void insertPos(int d,int p)
{
    if(isFull())
    {
        printf("array is full\n");
        return;
    }
    if(p<1||p>lastindex+2)
    {
        printf("invalid position\n");
        return;
    }
    int i;
    for(i=lastindex;i>=p-1;i--)
        a[i+1]=a[i];
    a[p-1]=d;
    lastindex++;
}

void deletePos(int p)
{
    if(isEmpty())
    {
        printf("array is empty\n");
        return;
    }
    if(p<1||p>lastindex+1)
    {
        printf("invalid position\n");
        return;
    }
    for(int i=p-1;i<lastindex;i++)
        a[i]=a[i+1];
    lastindex--;
}

void display()
{
    if(isEmpty())
    {
        printf("array is empty\n");
        return;
    }
    printf("array is: ");
    for(int i=0;i<=lastindex;i++)
        printf("%d ",a[i]);
}

void menu()
{
    printf("\n\n1. insertFront\n");
    printf("2. insertRear\n");
    printf("3. deleteFront\n");
    printf("4. deleteRear\n");
    printf("5. reverse\n");
    printf("6. insert by position\n");
    printf("7. delete by position\n");
    printf("8. display\n");
}

int main()
{
    int d,p,c;
    while(1)
    {
        menu();
        printf("enter the choice:");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            printf("enter the data:");
            scanf("%d",&d);
            insertFront(d);
            break;
        case 2:
            printf("enter the data:");
            scanf("%d",&d);
            insertRear(d);
            break;
        case 3:
            deleteFront();
            break;
        case 4:
            deleteRear();
            break;
        case 5:
            reverse();
            break;
        case 6:
            printf("enter the data:");
            scanf("%d",&d);
            printf("enter the position:");
            scanf("%d",&p);
            insertPos(d,p);
            break;
        case 7:
            printf("enter the position:");
            scanf("%d",&p);
            deletePos(p);
            break;
        case 8:
            display();
            break;
        default:
            printf("wrong choice entry\n");
        }
    }

}
