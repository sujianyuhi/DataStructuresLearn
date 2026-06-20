/*
Created by SUJIANYU on 2026/5/30.
【题目完整原文 链表综合题07】
递增有序单链表，删除全部重复元素，仅保留单个。
1）算法思想：
有序链表重复值一定相邻；p遍历，q=p->next，相等则删除q，不等则p后移。一趟遍历。
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

void DelRepeatSort(LinkList &L)
{
    if(L->next==NULL) return;
    LNode *p=L->next,*q;
    while(p->next!=NULL)
    {
        q=p->next;
        if(p->data == q->data)
        {
            p->next=q->next;
            free(q);
        }
        else
            p=p->next;
    }
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
    int n=9;
    ElemType arr[]={7,10,10,21,30,42,42,42,51};
    LinkList L;
    CreateList(L,arr,n);
    cout<<"原有序链表：";
    PrintList(L);
    DelRepeatSort(L);
    cout<<"去重后：";
    PrintList(L);
    return 0;
}
/*
运行结果：
原有序链表：7 10 10 21 30 42 42 42 51
去重后：7 10 21 30 42 51
*/