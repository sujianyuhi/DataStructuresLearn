/*
Created by SUJIANYU on 2026/5/30.
【题目完整原文 链表综合题13】
带freq访问频域的非循环双链表L，Locate(x)查找x，freq+1，链表按freq降序、同频最近访问靠前，返回结点指针。
1）算法思想：
① 遍历找到值x结点，freq自增；
② 摘下该结点，向前遍历找到第一个freq>当前结点freq的结点，插入其后；
2）复杂度：最坏O(n)、空间O(1)
*/
#include<iostream>
#include<cstdlib>
using namespace std;
typedef int ElemType;
typedef struct DNode{
    ElemType data;
    int freq;
    struct DNode *prior,*next;
}DNode,*DLinkList;

void CreateDLink(DLinkList &L,ElemType arr[],int n)
{
    L=(DNode*)malloc(sizeof(DNode));
    L->prior=NULL;L->next=NULL;
    DNode *r=L;
    for(int i=0;i<n;i++)
    {
        DNode *s=(DNode*)malloc(sizeof(DNode));
        s->data=arr[i];
        s->freq=0;
        s->prior=r;
        s->next=NULL;
        r->next=s;
        r=s;
    }
}

DNode* Locate(DLinkList &L,ElemType x)
{
    DNode *p=L->next;
    while(p!=NULL && p->data!=x) p=p->next;
    if(!p) return NULL;
    p->freq++;
    // 摘下p结点
    if(p->prior) p->prior->next=p->next;
    if(p->next) p->next->prior=p->prior;
    DNode *q=p->prior;
    // 向前找插入位置
    while(q!=L && q->freq >= p->freq) q=q->prior;
    // 插入q之后
    p->next=q->next;
    if(q->next) q->next->prior=p;
    q->next=p;
    p->prior=q;
    return p;
}

void PrintDLink(DLinkList L)
{
    DNode *p=L->next;
    while(p!=NULL)
    {
        cout<<"("<<p->data<<",freq:"<<p->freq<<") ";
        p=p->next;
    }
    cout<<endl;
}

int main()
{
    int n=4;
    ElemType arr[]={10,20,30,40};
    DLinkList L;
    CreateDLink(L,arr,n);
    Locate(L,30);
    Locate(L,30);
    Locate(L,10);
    cout<<"访问后链表(值,访问次数)：";
    PrintDLink(L);
    return 0;
}
/*
运行结果：访问后链表(值,访问次数)：(30,freq:2) (10,freq:1) (20,freq:0) (40,freq:0)
*/