/*
Created by SUJIANYU on 2026/5/30.
【题目完整原文 链表综合题09】
两递增有序链表代表集合，求交集并存入A链表，释放B全部结点。
1）算法思想：
归并双指针遍历，相等结点保留在A；较小值结点直接释放，遍历结束清空B剩余结点。原地复用A链表，无额外空间。
2）复杂度：时间O(lenA+lenB)、空间O(1)
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

LinkList GetIntersection(LinkList &la,LinkList &lb)
{
    LNode *pa=la->next,*pb=lb->next,*pc=la,*u;
    while(pa && pb)
    {
        if(pa->data == pb->data)
        {
            pc->next=pa;
            pc=pa;
            pa=pa->next;
            u=pb;
            pb=pb->next;
            free(u);
        }
        else if(pa->data < pb->data)
        {
            u=pa;
            pa=pa->next;
            free(u);
        }
        else
        {
            u=pb;
            pb=pb->next;
            free(u);
        }
    }
    // 释放A剩余
    while(pa){u=pa;pa=pa->next;free(u);}
    // 释放B剩余
    while(pb){u=pb;pb=pb->next;free(u);}
    pc->next=NULL;
    free(lb);
    return la;
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
    ElemType arrA[]={1,3,5,7,9},arrB[]={3,5,7,11};
    LinkList A,B;
    CreateList(A,arrA,5);
    CreateList(B,arrB,4);
    GetIntersection(A,B);
    cout<<"交集存入A链表：";
    PrintList(A);
    return 0;
}
/*
运行结果：交集存入A链表：3 5 7
*/