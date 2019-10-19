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
        printf("����������ĳ���");
        scanf("%d",&n);
        if(n<=0)
        {
            printf("��������\n");
        }

    }while(n<=0);
    printf("���������Ԫ��\n");
    for(i=0; i<n; i++)
    {
        scanf("%d",&value);
        LinkList NEW=(LinkList)malloc(sizeof(LNode));
        NEW->data=value;
        P->next=NEW;
        NEW->next=NULL;
        P=NEW;
    }
    printf("�������ɹ�\n");
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
        printf("����ɹ�\n");
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
    printf("ɾ���ɹ�\n");
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
            printf("�ýڵ��������λ��Ϊ%d��\n",i);
            return OK;
        }
        q=q->next;
    }
    printf("��������û�иýڵ�\n");
    return ERROR;
}
Status Print(LinkList L)
{
    LinkList q=L;
    printf("�������ÿ��Ԫ��Ϊ:\n");
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
    printf("��ճɹ�\n");
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
    printf("�ͷųɹ�\n");
    //free (L);
    return L;
}
void Pr()
{
    printf("\n1.�����½��\n");
    printf("2.ɾ�������еĽ��\n");
    printf("3.���ҽ��\n");
    printf("4.�������\n");
    printf("5.�������\n");
    printf("6.��������\n");
    printf("7.�˳�\n");
    printf("������Ҫʹ�õĹ���:");
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
            printf("������Ҫ����Ľ���ֵ�Ͳ����λ��");
            scanf("%d %d",&i,&j);
            InsertList(L,j,i);
            break;
        case 2:
            printf("������Ҫɾ����λ��");
            scanf("%d",&i);
            DeleteList(L,i);
            break;
        case 3:
            printf("������Ҫ���ҵĽ��");
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
        printf("�˳��ɹ�");
    return 0;
}
