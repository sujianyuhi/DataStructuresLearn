/*
Created by SUJIANYU on 2026/5/30.
【2009统考真题17】带头结点单链表，查找倒数第k个结点，一趟遍历，输出data，成功返回1，失败返回0。
1）算法思想：
双指针p、q同时指向首元结点；p先走k步，之后p、q同步后移；p到表尾时q指向倒数第k个结点。仅一趟遍历，高效O(n)。
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

// 查找倒数第k个结点
int FindKFromEnd(LinkList list,int k)
{
    LNode *p=list->next,*q=list->next;
    int cnt=0;
    // p先走k步
    while(p!=NULL)
    {
        if(cnt<k) cnt++;
        else q=q->next;
        p=p->next;
    }
    // k超过链表长度
    if(cnt<k) return 0;
    cout<<"倒数第"<<k<<"个结点值："<<q->data;
    return 1;
}

int main()
{
    int n=6;
    ElemType arr[]={10,20,30,40,50,60};
    LinkList L;
    CreateList(L,arr,n);
    int res=FindKFromEnd(L,3);
    cout<<endl<<"函数返回值："<<res;
    return 0;
}
/*
运行结果：
倒数第3个结点值：40
函数返回值：1
*/