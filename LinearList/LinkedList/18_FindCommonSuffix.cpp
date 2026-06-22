/*
Created by SUJIANYU on 2026/5/30.
【2012统考真题18】两个单词带头结点字符链表，找公共后缀起始结点。
1）算法思想：
① 分别求两链表长度len1、len2；
② 长链表指针先走长度差步，使两指针到尾部距离相等；
③ 同步遍历，首个相等结点即为公共后缀起点。
2）复杂度：O(len1+len2)，空间O(1)
*/
#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct SNode{
    char data;
    struct SNode *next;
}SNode,*StrLink;

// 创建字符链表
void CreateStrList(StrLink &L,char str[])
{
    L=(SNode*)malloc(sizeof(SNode));
    L->next=NULL;
    SNode *r=L;
    for(int i=0;str[i]!='\0';i++)
    {
        SNode *s=(SNode*)malloc(sizeof(SNode));
        s->data=str[i];
        s->next=NULL;
        r->next=s;
        r=s;
    }
}

// 获取链表长度
int GetStrLen(StrLink head)
{
    int len=0;
    SNode *p=head->next;
    while(p!=NULL)
    {
        len++;
        p=p->next;
    }
    return len;
}

// 寻找公共后缀起始结点
SNode* FindCommonSuffix(StrLink str1,StrLink str2)
{
    int m=GetStrLen(str1);
    int n=GetStrLen(str2);
    SNode *p=str1->next,*q=str2->next;
    // 长链表先走差值
    if(m>n)
        for(int i=0;i<m-n;i++) p=p->next;
    else
        for(int i=0;i<n-m;i++) q=q->next;
    // 同步遍历找相同结点
    while(p!=NULL && q!=NULL && p!=q)
    {
        p=p->next;
        q=q->next;
    }
    return p;
}

int main()
{
    char s1[]="loading",s2[]="being";
    StrLink str1,str2;
    CreateStrList(str1,s1);
    CreateStrList(str2,s2);
    SNode *ans=FindCommonSuffix(str1,str2);
    if(ans) cout<<"公共后缀首字符："<<ans->data;
    else cout<<"无公共后缀";
    return 0;
}
/*
运行结果：公共后缀首字符：i
*/