/*
Created by SUJIANYU on 2026/5/30.
【题目完整原文 链表综合题08】
两个递增有序带头结点单链表A、B，不破坏原链表，生成存放公共元素的新链表C。
1）算法思想：
双指针pa、pb同步遍历有序链表；小值指针后移，相等则新建结点尾插进C，直到某链表遍历完毕。
2）复杂度：时间O(lenA+lenB)、空间O(k)（k为公共元素个数，输出不计额外开销）
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

LinkList GetCommonSort(LinkList A,LinkList B)
{
    LinkList C=(LNode*)malloc(sizeof(LNode));
    C->next=NULL;
    LNode *r=C;
    LNode *pa=A->next,*pb=B->next,*s;
    while(pa!=NULL && pb!=NULL)
    {
        if(pa->data < pb->data)
            pa=pa->next;
        else if(pa->data > pb->data)
            pb=pb->next;
        else
        {
            s=(LNode*)malloc(sizeof(LNode));
            s->data=pa->data;
            s->next=NULL;
            r->next=s;
            r=s;
            pa=pa->next;
            pb=pb->next;
        }
    }
    r->next=NULL;
    return C;
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
    ElemType arrA[]={1,3,4,6,8,10},arrB[]={2,3,6,10,12};
    LinkList A,B,C;
    CreateList(A,arrA,6);
    CreateList(B,arrB,5);
    C=GetCommonSort(A,B);
    cout<<"公共元素链表C：";
    PrintList(C);
    return 0;
}
/*
运行结果：公共元素链表C：3 6 10
*/