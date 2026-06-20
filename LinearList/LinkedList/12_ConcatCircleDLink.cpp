/*
Created by SUJIANYU on 2026/5/30.
【题目完整原文 链表综合题12】
两个循环双链表h1、h2，将h2链接到h1尾部，保持循环链表结构。
1）算法思想：
分别找到h1、h2尾结点；h1尾->next指向h2头，h2尾->next指向h1；双向指针同步修改，维持循环双链表。
2）复杂度：时间O(len1+len2)、空间O(1)
*/
#include<iostream>
#include<cstdlib>
using namespace std;
typedef int ElemType;
typedef struct DNode{
    ElemType data;
    struct DNode *prior,*next;
}DNode,*DLinkList;

void CreateDLink(DLinkList &L,ElemType arr[],int n)
{
    L=(DNode*)malloc(sizeof(DNode));
    L->prior=L;L->next=L;
    DNode *r=L;
    for(int i=0;i<n;i++)
    {
        DNode *s=(DNode*)malloc(sizeof(DNode));
        s->data=arr[i];
        s->prior=r;
        s->next=L;
        r->next=s;
        r=s;
    }
}

DLinkList ConcatCircleDLink(DLinkList &h1,DLinkList &h2)
{
    DNode *p=h1;
    while(p->next != h1) p=p->next;
    DNode *q=h2;
    while(q->next != h2) q=q->next;
    // 双向链接
    p->next=h2;
    h2->prior=p;
    q->next=h1;
    h1->prior=q;
    return h1;
}

void PrintDLink(DLinkList L)
{
    DNode *p=L->next;
    while(p!=L)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int main()
{
    ElemType arr1[]={1,2,3},arr2[]={4,5,6};
    DLinkList h1,h2;
    CreateDLink(h1,arr1,3);
    CreateDLink(h2,arr2,3);
    ConcatCircleDLink(h1,h2);
    cout<<"合并后循环双链表：";
    PrintDLink(h1);
    return 0;
}
/*
运行结果：合并后循环双链表：1 2 3 4 5 6
*/