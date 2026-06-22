/*
Created by SUJIANYU on 2026/5/30.
【题目完整原文 链表综合题16】
偶数长度不带头结点单链表，孪生和：第i个与第n-i-1个结点之和，求最大孪生和。
1）算法思想：
快慢指针找到链表中点；原地逆置后半段链表；双指针分别遍历前半、逆置后半，计算孪生和更新最大值；空间O(1)。
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

// 原地逆置链表
LNode* Reverse(LNode *head)
{
    LNode *pre=NULL,*cur=head,*nxt;
    while(cur!=NULL)
    {
        nxt=cur->next;
        cur->next=pre;
        pre=cur;
        cur=nxt;
    }
    return pre;
}

int MaxTwinSum(LinkList L)
{
    if(L==NULL) return 0;
    LNode *fast=L->next,*slow=L;
    // 快慢指针找中点
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    // 后半段逆置
    LNode *half2=Reverse(slow->next);
    slow->next=NULL;
    LNode *p=L,*q=half2;
    int maxSum=0;
    while(p!=NULL && q!=NULL)
    {
        int sum=p->data+q->data;
        if(sum>maxSum) maxSum=sum;
        p=p->next;
        q=q->next;
    }
    return maxSum;
}

int main()
{
    int n=4;
    ElemType arr[]={5,4,2,1};
    LinkList L;
    CreateNoHead(L,arr,n);
    int ans=MaxTwinSum(L);
    cout<<"最大孪生和："<<ans;
    return 0;
}
/*
运行结果：最大孪生和：6
解析：(5+1)=6，(4+2)=6
*/