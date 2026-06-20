/*
Created by SUJIANYU on 2026/5/30.
【题目完整原文 链表综合题10】
两整数序列存入单链表，判断B是否为A的连续子序列。
1）算法思想：
外层pre标记A每次匹配起点，p遍历A；q遍历B，匹配失败则pre后移、重置q为B表头；q遍历完毕则匹配成功返回1，A遍历完返回0。
2）复杂度：最坏O(m*n)、空间O(1)
*/
#include<iostream>
#include<cstdlib>
using namespace std;
typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

// 不带头结点链表创建
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

int IsSubSequence(LinkList A,LinkList B)
{
    if(A==NULL || B==NULL) return 0;
    LNode *pre=A,*p,*q;
    while(pre!=NULL)
    {
        p=pre;
        q=B;
        while(p!=NULL && q!=NULL && p->data == q->data)
        {
            p=p->next;
            q=q->next;
        }
        if(q==NULL) return 1;
        pre=pre->next;
    }
    return 0;
}

int main()
{
    ElemType arrA[]={1,2,3,4,5,6},arrB[]={3,4,5};
    LinkList A,B;
    CreateNoHead(A,arrA,6);
    CreateNoHead(B,arrB,3);
    int res=IsSubSequence(A,B);
    if(res) cout<<"B是A的连续子序列";
    else cout<<"B不是A的连续子序列";
    return 0;
}
/*
运行结果：B是A的连续子序列
*/