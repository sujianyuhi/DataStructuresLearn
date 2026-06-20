/*
Created by SUJIANYU on 2026/5/30.
【题目完整原文 链表综合题14】
不带头结点单链表，n个整数循环右移k位(0<k<n)，如{0,1,2,3}k=1→{3,0,1,2}
1）算法思想：
① 遍历求链表长度n，同时找到尾结点，尾->next=表头形成循环；
② 循环前进n-k步，新表头为当前结点，断开循环，尾结点next置NULL；
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

// 不带头结点创建
void CreateNoHead(LinkList &L,ElemType arr[],int n)
{
    L=NULL;
    LNode *r=NULL;
    for(int i=0;i<n;i++)
    {
        LNode *s=(LNode*)malloc(sizeof(LNode));
        s->data=arr[i];
        s->next=NULL;
        if(L==NULL) L=s;
        else r->next=s;
        r=s;
    }
}

LinkList RightShiftNoHead(LinkList &L,int k)
{
    if(L==NULL) return L;
    int n=1;
    LNode *p=L;
    while(p->next!=NULL)
    {
        p=p->next;
        n++;
    }
    p->next=L; // 成环
    // 走n-k步
    for(int i=1;i<=n-k;i++)
        p=p->next;
    L=p->next;
    p->next=NULL;
    return L;
}

void PrintList(LinkList L)
{
    LNode *p=L;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int main()
{
    int n=4,k=1;
    ElemType arr[]={0,1,2,3};
    LinkList L;
    CreateNoHead(L,arr,n);
    cout<<"原链表：";
    PrintList(L);
    RightShiftNoHead(L,k);
    cout<<"循环右移1位：";
    PrintList(L);
    return 0;
}
/*
运行结果：
原链表：0 1 2 3
循环右移1位：3 0 1 2
*/