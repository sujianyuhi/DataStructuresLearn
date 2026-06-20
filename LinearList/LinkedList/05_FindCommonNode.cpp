/*
Created by SUJIANYU on 2026/5/30.
【题目完整原文 链表综合题05】
分析两个单链表公共结点查找思想（附带可运行代码实现）
1）算法思想：
① 先遍历两链表求长度len1、len2，求长度差k；
② 长链表先走k步，两指针同步遍历，第一个相等结点即为首个公共结点；
原理：公共结点后全部重合，尾部一定相同，同步遍历可线性找到。
2）复杂度：时间O(len1+len2)、空间O(1)
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

// 获取链表长度
int GetLen(LinkList L)
{
    int cnt=0;
    LNode *p=L->next;
    while(p!=NULL){cnt++;p=p->next;}
    return cnt;
}

// 找首个公共结点
LNode* FindCommonNode(LinkList A,LinkList B)
{
    int lenA=GetLen(A),lenB=GetLen(B);
    LNode *pa=A->next,*pb=B->next;
    // 长链表先走差值
    if(lenA>lenB)
        for(int i=0;i<lenA-lenB;i++) pa=pa->next;
    else
        for(int i=0;i<lenB-lenA;i++) pb=pb->next;
    // 同步遍历
    while(pa!=NULL && pb!=NULL && pa!=pb)
    {
        pa=pa->next;
        pb=pb->next;
    }
    return pa;
}

int main()
{
    // 构造Y型公共链表：A:1 2 5 6 7；B:3 5 6 7 公共结点5
    ElemType arrA[]={1,2,5,6,7},arrB[]={3,5,6,7};
    LinkList A,B;
    CreateList(A,arrA,5);
    CreateList(B,arrB,4);
    // 手动构造公共结点，使B的3后继指向A的5结点
    B->next->next = A->next->next->next;
    LNode *res=FindCommonNode(A,B);
    if(res) cout<<"首个公共结点值："<<res->data;
    else cout<<"无公共结点";
    return 0;
}
/*
运行结果：首个公共结点值：5
*/