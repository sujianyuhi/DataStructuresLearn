/*
Created by SUJIANYU on 2026/5/30.
【题目完整原文 链表综合题06】
链表C={a1,b1,a2,b2…an,bn}，原地拆分为A={a1,a2…an}，B={bn…b2,b1}，带头结点。
1）算法思想：
遍历原链表，奇数结点尾插进A；偶数结点头插进B（头插天然逆序），原地拆分无额外空间。
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

LinkList SplitAB(LinkList &C)
{
    LinkList A,B;
    A=(LNode*)malloc(sizeof(LNode));A->next=NULL;
    B=(LNode*)malloc(sizeof(LNode));B->next=NULL;
    LNode *ra=A,*p=C->next,*q;
    while(p!=NULL)
    {
        // 奇数a结点，尾插A
        ra->next=p;
        ra=p;
        p=p->next;
        if(p==NULL) break;
        // 偶数b结点，头插B
        q=p->next;
        p->next=B->next;
        B->next=p;
        p=q;
    }
    ra->next=NULL;
    C->next=A->next;
    free(A);
    return B;
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
    int n=6;
    ElemType arr[]={1,10,2,20,3,30};
    LinkList C;
    CreateList(C,arr,n);
    cout<<"原链表C：";
    PrintList(C);
    LinkList B=SplitAB(C);
    cout<<"拆分后A：";PrintList(C);
    cout<<"拆分后B：";PrintList(B);
    return 0;
}
/*
运行结果：
原链表C：1 10 2 20 3 30 
拆分后A：1 2 3 
拆分后B：30 20 10 
*/