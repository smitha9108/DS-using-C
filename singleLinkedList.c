#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *next;
};

int c=0;
typedef struct node node;

node* insertFront(node *start,int d)
{
    node *n=(node*)malloc(sizeof(node));
    n->info=d;
    n->next=start;
    c++;
    return n;
}

node* insertRear(node *start,int d)
{
    node *n=(node*)malloc(sizeof(node)),*p=start;
    n->info=d;
    n->next=NULL;
    c++;
    if(p==NULL)
        return n;
    while(p->next!=NULL)
        p=p->next;
    p->next=n;
    return start;
}

node* deleteFront(node *start)
{
    if(start==NULL)
    {
        printf("list is empty\n");
        return start;
    }
    c--;
    node *p=start;
    start=start->next;
    free(p);
    return start;
}

node* deleteRear(node *start)
{
    if(start==NULL)
    {
        printf("list is empty\n");
        return start;
    }
    c--;
    if(start->next==NULL)
    {
        free(start);
        return NULL;
    }
    node *p=start,*q;
    while(p->next->next!=NULL)
        p=p->next;
    q=p->next;
    p->next=NULL;
    free(q);
    return start;
}

void display(node *start)
{
    if(start==NULL)
    {
        printf("list is empty\n");
        return;
    }
    while(start!=NULL)
    {
        printf("%d ",start->info);
        start=start->next;
    }
}

node* reverse(node *start)
{
    if(start==NULL||start->next==NULL)
        return start;
    node *prev=NULL,*cur=start,*next;
    while(cur!=NULL)
    {
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    return prev;
}

node* insertPos(node *start,int d,int p)
{
    node *q=start,*n=(node*)malloc(sizeof(node));
    n->info=d;
    if(p<1||p>c+1)
    {
        printf("invalid position\n");
        return start;
    }
    if (p==1)
        return insertFront(start,d);
    int i=2;
    while(i<p)
    {
        q=q->next;
        i++;
    }
    n->next=q->next;
    q->next=n;
    c++;
    return start;
}

node* deletePos(node *start,int p)
{
    if(start==NULL)
    {
        printf("list is empty\n");
        return start;
    }
    if(p<1||p>c+1)
    {
        printf("invalid position\n");
        return start;
    }
    if(p==1)
        return deleteFront(start);
    int i=2;
    node *q=start,*n;
    while(i<p)
    {
        q=q->next;
        i++;
    }
    n=q->next;
    q->next=n->next;
    free(n);
    c--;
    return start;
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
    int d,p,ch;
    node *start=NULL;
    while(1)
    {
        menu();
        printf("enter the choice:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("enter the data:");
            scanf("%d",&d);
            start=insertFront(start,d);
            break;
        case 2:
            printf("enter the data:");
            scanf("%d",&d);
            start=insertRear(start,d);
            break;
        case 3:
            start=deleteFront(start);
            break;
        case 4:
            start=deleteRear(start);
            break;
        case 5:
            start=reverse(start);
            break;
        case 6:
            printf("enter the data:");
            scanf("%d",&d);
            printf("enter the position:");
            scanf("%d",&p);
            start=insertPos(start,d,p);
            break;
        case 7:
            printf("enter the position:");
            scanf("%d",&p);
            start=deletePos(start,p);
            break;
        case 8:
            display(start);
            break;
        default:
            printf("wrong choice entry\n");
        }
    }

}
