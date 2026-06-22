/*
Created by SUJIANYU on 2026/5/30.
【2019统考真题20】带头结点单链表，原地重排为 L'=(a1,an,a2,an-1,a3,an-2...)，空间O(1)。
1）算法思想：
① 快慢指针找到链表中点；
② 后半段链表原地逆置；
③ 交替合并前半段、逆置后半段结点，完成重排。全程仅临时指针，无额外数组。
2）复杂度：时间O(n)、空间O(1)
*/
#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct node{
    int data;
    struct node *next;
}NODE,*PNODE;

void CreateList(PNODE &h,int arr[],int n)
{
    h=(NODE*)malloc(sizeof(NODE));
    h->next=NULL;
    PNODE r=h;
    for(int i=0;i<n;i++)
    {
        NODE *s=(NODE*)malloc(sizeof(NODE));
        s->data=arr[i];
        s->next=NULL;
        r->next=s;
        r=s;
    }
}

void PrintList(PNODE h)
{
    NODE *p=h->next;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

void RearrangeList(PNODE h)
{
    if(h->next==NULL || h->next->next==NULL) return;
    NODE *p=h,*q=h;
    // 快慢指针找中点
    while(q->next!=NULL && q->next->next!=NULL)
    {
        p=p->next;
        q=q->next->next;
    }
    // 拆分前后两段，后半段头q
    q=p->next;
    p->next=NULL;
    // 逆置后半段
    NODE *pre=NULL,*cur=q,*nxt;
    while(cur!=NULL)
    {
        nxt=cur->next;
        cur->next=pre;
        pre=cur;
        cur=nxt;
    }
    q=pre; // q指向逆置后的后半段表头
    // 交替合并两段
    NODE *s=h->next,*t;
    while(q!=NULL)
    {
        t=q->next;
        q->next=s->next;
        s->next=q;
        s=q->next;
        q=t;
    }
}

int main()
{
    int arr[]={1,2,3,4,5,6};
    int n=6;
    PNODE head;
    CreateList(head,arr,n);
    cout<<"原链表：";PrintList(head);
    RearrangeList(head);
    cout<<"重排后：";PrintList(head);
    return 0;
}
/*
运行结果：
原链表：1 2 3 4 5 6
重排后：1 6 2 5 3 4
*/