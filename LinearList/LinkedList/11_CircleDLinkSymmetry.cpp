/*
Created by SUJIANYU on 2026/5/30.
【题目完整原文 链表综合题11】
判断带头结点循环双链表是否对称。
1）算法思想：
左指针p从头结点后继向右，右指针q从头结点前驱向左；循环对比结点值，奇数结点相遇、偶数相邻终止，全部相等则对称。
2）复杂度：时间O(n)、空间O(1)
*/
#include<iostream>
#include<cstdlib>
using namespace std;
typedef int ElemType;
typedef struct DNode{
    ElemType data;
    struct DNode *prior,*next;
}DNode,*DLinkList;

// 创建循环双链表（带头结点）
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

int CircleDLinkSymmetry(DLinkList L)
{
    DNode *p=L->next,*q=L->prior;
    while(p!=q && p->next!=q)
    {
        if(p->data != q->data) return 0;
        p=p->next;
        q=q->prior;
    }
    if(p->data != q->data) return 0;
    return 1;
}

int main()
{
    int n=6;
    ElemType arr[]={1,2,3,3,2,1};
    DLinkList L;
    CreateDLink(L,arr,n);
    int res=CircleDLinkSymmetry(L);
    if(res) cout<<"循环双链表对称";
    else cout<<"循环双链表不对称";
    return 0;
}
/*
运行结果：循环双链表对称
*/