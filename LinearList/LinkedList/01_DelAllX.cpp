/*
Created by SUJIANYU on 2026/5/30.
【题目完整原文 链表综合题01】
在带头结点的单链表L中，删除所有值为x的结点，并释放其空间，值为x的结点不唯一。
1）算法思想：
双指针遍历，pre保存前驱结点，p遍历当前结点；若p->data==x，则删除p、释放空间；否则pre、p同步后移。一趟遍历完成，原地操作。
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

// 创建带头结点单链表
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

// 删除所有值为x的结点
void DelAllX(LinkList &L,ElemType x)
{
    LNode *pre=L,*p=L->next,*q;
    while(p!=NULL)
    {
        if(p->data == x)
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

// 打印链表
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
    ElemType arr[]={2,5,3,5,1,5};
    LinkList L;
    CreateList(L,arr,n);
    cout<<"原链表：";
    PrintList(L);
    DelAllX(L,5);
    cout<<"删除值5后：";
    PrintList(L);
    return 0;
}
/*
运行结果：
原链表：2 5 3 5 1 5
删除值5后：2 3 1
*/