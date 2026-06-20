/*
Created by SUJIANYU on 2026/5/30.
【题目完整原文 链表综合题04】
无序带头结点单链表，删除两个参数minVal、maxVal之间所有元素（minVal<maxVal）。
1）算法思想：
pre存前驱，p遍历；若p->data在区间内则删除释放，否则同步后移双指针，一趟遍历。
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

void DelBetweenVal(LinkList &L,ElemType minVal,ElemType maxVal)
{
    LNode *pre=L,*p=L->next,*q;
    while(p!=NULL)
    {
        if(p->data>minVal && p->data<maxVal)
        {
            q=p;
            p=p->next;
            pre->next=p;
            free(q);
        }
        else
        {
            pre=p;
            p=p->next;
        }
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
    int n=6;
    ElemType arr[]={1,3,5,7,9,11};
    LinkList L;
    CreateList(L,arr,n);
    cout<<"原链表：";
    PrintList(L);
    DelBetweenVal(L,3,9);
    cout<<"删除(3,9)之间元素后：";
    PrintList(L);
    return 0;
}
/*
运行结果：
原链表：1 3 5 7 9 11
删除(3,9)之间元素后：1 3 9 11
*/