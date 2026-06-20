/*
Created by SUJIANYU on 2026/5/30.
【题目完整原文 链表综合题03】
带头结点单链表原地逆置，辅助空间O(1)。
1）算法思想（头插法）：
断开头结点后继，逐个取出原链表结点，头插插入到头结点后方，完成逆置，仅临时指针无额外空间。
2）复杂度：时间O(n)、空间O(1)
*/
#include<iostream>
#include<cstdlib>
using namespace std;
typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

void CreateList(LinkList &L,ElemType arr[],int n)
{
    L=(LNode*)malloc(sizeof(LNode));
    L->next=NULL;
    LNode *r=L;
    for(int i=0;i<n;i++)
    {
        LNode *s=(LNode*)malloc(sizeof(LNode));
        s->data=arr[i];
        s->next=NULL;
        r->next=s;
        r=s;
    }
}

LinkList ReverseList(LinkList L)
{
    LNode *p=L->next,*r;
    L->next=NULL;
    while(p!=NULL)
    {
        r=p->next;
        p->next=L->next;
        L->next=p;
        p=r;
    }
    return L;
}

void PrintList(LinkList L)
{
    LNode *p=L->next;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int main()
{
    int n=4;
    ElemType arr[]={1,2,3,4};
    LinkList L;
    CreateList(L,arr,n);
    cout<<"原链表：";
    PrintList(L);
    ReverseList(L);
    cout<<"逆置后：";
    PrintList(L);
    return 0;
}
/*
运行结果：
原链表：1 2 3 4
逆置后：4 3 2 1
*/