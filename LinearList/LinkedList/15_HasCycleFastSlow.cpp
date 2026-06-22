/*
Created by SUJIANYU on 2026/5/30.
【题目完整原文 链表综合题15】
判断单链表是否存在环，快慢指针法。
1）算法思想：
fast快指针一次走2步，slow慢指针一次走1步；若链表有环，两指针必然在环内相遇；若fast走到NULL无环。相遇后可进一步求环入口。
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

// 创建带头结点链表
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

// 判断链表是否有环，返回相遇结点，无环返回NULL
LNode* HasCycle(LinkList head)
{
    LNode *fast=head,*slow=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) return slow;
    }
    return NULL;
}

// 获取环入口结点
LNode* GetCycleEntry(LinkList head)
{
    LNode *meet=HasCycle(head);
    if(meet==NULL) return NULL;
    LNode *p1=head,*p2=meet;
    while(p1!=p2)
    {
        p1=p1->next;
        p2=p2->next;
    }
    return p1;
}

int main()
{
    int n=5;
    ElemType arr[]={1,2,3,4,5};
    LinkList L;
    CreateList(L,arr,n);
    // 手动制造环：尾结点指向3号结点(3)
    LNode *p=L->next;
    LNode *loop=NULL;
    while(p->next!=NULL)
    {
        if(p->data==3) loop=p;
        p=p->next;
    }
    p->next=loop;
    LNode *res=GetCycleEntry(L);
    if(res) cout<<"链表存在环，环入口值："<<res->data;
    else cout<<"链表无环";
    return 0;
}
/*
运行结果：链表存在环，环入口值：3
*/