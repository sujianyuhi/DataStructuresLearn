/*
Created by SUJIANYU on 2026/5/30.
【题目完整原文 链表综合题02】
带头结点单链表，删除唯一最小值结点，高效算法。
1）算法思想：
一趟遍历链表，用minp记录最小值结点、minpre记录其前驱；遍历结束修改前驱指针跳过最小值结点，释放空间。
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

LinkList DelMinNode(LinkList &L)
{
    if(L->next==NULL) return L;
    LNode *pre=L,*p=L->next;
    LNode *minpre=pre,*minp=p;
    while(p!=NULL)
    {
        if(p->data < minp->data)
        {
            minp=p;
            minpre=pre;
        }
        pre=p;
        p=p->next;
    }
    minpre->next=minp->next;
    free(minp);
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
    int n=5;
    ElemType arr[]={9,2,7,1,4};
    LinkList L;
    CreateList(L,arr,n);
    cout<<"原链表：";
    PrintList(L);
    DelMinNode(L);
    cout<<"删除最小值后：";
    PrintList(L);
    return 0;
}
/*
运行结果：
原链表：9 2 7 1 4
删除最小值后：9 2 7 4
*/