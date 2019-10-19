#include <iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef int Status;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
    struct LNode *prior;
} LNode,*LinkList;
LinkList NewLNode(LNode *P,ElemType data)
{
    P=(LNode*)malloc(sizeof(LNode));
    P->data=data;
    P->next=NULL;
    return P;
}
LinkList InitList()
{
    int i,value,n;
    LinkList H=(LinkList)malloc(sizeof(LNode));
    LinkList P=H;
    P->next=NULL;
    do
    {
        printf("请输入链表的长度");
        scanf("%d",&n);
        if(n<=0)
        {
            printf("输入有误\n");
        }

    }while(n<=0);
    printf("请输入各个元素\n");
    for(i=0; i<n; i++)
    {
        scanf("%d",&value);
        LinkList NEW=(LinkList)malloc(sizeof(LNode));
        NEW->data=value;
        P->next=NEW;
        NEW->next=NULL;
        P=NEW;
    }
    printf("链表建立成功\n");
    return H->next;
}
LinkList InsertList(LinkList L,int i,ElemType value)
{
    LinkList h,q,t=NewLNode(t,value);
    int x=0;
    h=q=L;
    if(i==1)
    {
        t->next=h;
        h=t;
    }
    else
    {
        while(x++<i-2)
            q=q->next;
            t->next=q->next;
            q->next=t;
    }
        printf("插入成功\n");
        return h;
}
LinkList DeleteList(LinkList L,int i)
{
    LinkList h,q,de;
    int x=0;
    h=q=L;
    int t;
    if(i==1)
    {
        h=h->next;
    }
    else
    {
        while(x++<i-2)
            q=q->next;
        de=q->next;
        if(de->next==NULL)
        {
            q->next=NULL;
        }
        else q->next=de->next;
    }
    printf("删除成功\n");
    return h;
}
Status LocateList (LinkList L,ElemType value)
{
    LinkList q=L;
    int i=0,t;
    while(q!=NULL)
    {
        i++;
        if(q->data==value)
        {
            printf("该节点在链表的位置为%d个\n",i);
            return OK;
        }
        q=q->next;
    }
    printf("该链表中没有该节点\n");
    return ERROR;
}
Status Print(LinkList L)
{
    LinkList q=L;
    printf("该链表的每个元素为:\n");
    while(q!=NULL)
    {
        printf("%d    ",q->data);
        q=q->next;
    }
    printf("\n");
    return OK;
}
LinkList EmptyList (LinkList L)
{
    LinkList p,q;
    if(L==NULL)
        return 0;
        //p=L->next;
        p=L;
    while(p!=NULL)
    {
        q=p->next;
        free(p);
        p=q;
    }
   L->next=NULL;

    //free(L->next);
    //free(L->data);
   // L->next=NULL;
    printf("清空成功\n");
    return L;
}
LinkList FreeList(LinkList L)
{
   LinkList p;
   LinkList pp;
   pp=L->prior;
    if(L==NULL)
    return 0;
   // L=L->prior;
    while(L!=NULL)
    {
        p=L->next;
     //  p=L;
        free(L);

        L=p;
    }
free(pp);
    printf("释放成功\n");
    //free (L);
    return L;
}
void Pr()
{
    printf("\n1.插入新结点\n");
    printf("2.删除链表中的结点\n");
    printf("3.查找结点\n");
    printf("4.输出链表\n");
    printf("5.清空链表\n");
    printf("6.销毁链表\n");
    printf("7.退出\n");
    printf("请输入要使用的功能:");
}
int main()
{
    LinkList L=InitList();
    int n,i,j;
    Pr();
    scanf("%d",&n);
    while(n>0&&n<7)
    {
        switch(n)
        {
        case 1:
            printf("请输入要插入的结点的值和插入的位置");
            scanf("%d %d",&i,&j);
            InsertList(L,j,i);
            break;
        case 2:
            printf("请输入要删除的位置");
            scanf("%d",&i);
            DeleteList(L,i);
            break;
        case 3:
            printf("请输入要查找的结点");
            scanf("%d",&i);
            LocateList(L,i);
            break;
        case 4:
            Print(L);
            break;
        case 5:
            EmptyList(L);
            break;
        case 6:
            FreeList(L);
            break;
        }
        Pr();
        scanf("%d",&n);
    }
    if(n==7)
        printf("退出成功");
    return 0;
}
