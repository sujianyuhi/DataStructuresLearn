/*
Created by SUJIANYU on 2026/5/30.
【2015统考真题19】带头结点单链表，|data|≤n，仅保留绝对值首次出现结点，删除其余。
1）算法思想：
开辟辅助标记数组q[0~n]，记录绝对值是否出现；遍历链表，未标记则保留并标记，已标记则删除释放。一趟遍历。
2）复杂度：时间O(m)（m为结点数），空间O(n)
*/
#include<iostream>
#include<cstdlib>
using namespace std;
typedef int ElemType;
typedef struct LNode{
    int data;
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

// 删除绝对值重复结点
void DelAbsDup(LinkList h,int n)
{
    int *tag=(int*)malloc(sizeof(int)*(n+1));
    // 初始化标记数组0：未出现
    for(int i=0;i<=n;i++) tag[i]=0;
    LNode *p=h,*r;
    while(p->next!=NULL)
    {
        int val=abs(p->next->data);
        if(tag[val]==0)
        {
            tag[val]=1;
            p=p->next;
        }
        else
        {
            r=p->next;
            p->next=r->next;
            free(r);
        }
    }
    free(tag);
}

int main()
{
    int n=21; // 最大绝对值21
    ElemType arr[]={21,-15,-15,-7,15};
    LinkList L;
    CreateList(L,arr,5);
    cout<<"原链表：";PrintList(L);
    DelAbsDup(L,n);
    cout<<"删除绝对值重复后：";PrintList(L);
    return 0;
}
/*
运行结果：
原链表：21 -15 -15 -7 15
删除绝对值重复后：21 -15 -7
*/