/*
Created by SUJIANYU on 2026/5/30.
【题目完整原文 2020统考真题 题号14】
三元组距离D=|a−b|+|b−c|+|c−a|，化简：设x、y、z为三个数的最小、中间、最大值，D=2*(z−x)
给定升序数组S1、S2、S3，a∈S1,b∈S2,c∈S3，求最小D、输出对应三元组(a,b,c)。
样例：S1={-1,0,9},S2={-25,-10,10,11},S3={2,9,17,30,41}，最小D=2，三元组(9,10,9)。
要求：
1）算法设计思想；
2）C++代码+注释；
3）时空复杂度。

【1.算法设计思想（三指针i,j,k，O(n+m+p)最优）】
1. 公式化简：D=2*(max(a,b,c)-min(a,b,c))，求最小D等价求「三个数最大值-最小值最小」
2. i/j/k分别指向S1、S2、S3起始下标，初始全=0；
3. 计算当前三元组的max、min，更新全局最小差值；
4. 将**最小值所在数组的指针+1**（想缩小极差，只能移动最小元素）；
5. 任意指针越界则结束循环，最后输出最小差值对应的三元组。

【3.复杂度说明】
设三数组长度n,m,p；时间O(n+m+p)，每个指针最多遍历一次；空间O(1)，仅指针与临时变量。
*/
#include<iostream>
#include<cmath>
#define MAXSIZE 50
using namespace std;
typedef int ElemType;

// 获取三个数最大值
int getMax(int x,int y,int z){
    int t=x>y?x:y;
    return t>z?t:z;
}
// 获取三个数最小值
int getMin(int x,int y,int z){
    int t=x<y?x:y;
    return t<z?t:z;
}

// 三指针找最小距离三元组
void FindMinTri(ElemType S1[],int n,ElemType S2[],int m,ElemType S3[],int p,
                int &res_a,int &res_b,int &res_c)
{
    int i=0,j=0,k=0; //三个数组起始指针
    int minD = 0x7fffffff; //初始化最小距离为极大值

    while(i<n && j<m && k<p)
    {
        int a=S1[i],b=S2[j],c=S3[k];
        int mx=getMax(a,b,c);
        int mn=getMin(a,b,c);
        int D=2*(mx-mn); //距离公式化简结果

        // 更新最小值与答案三元组
        if(D < minD)
        {
            minD=D;
            res_a=a; res_b=b; res_c=c;
        }

        // 最小元素所在指针右移
        if(mn == a) i++;
        else if(mn == b) j++;
        else k++;
    }
}

int main()
{
    //题目样例数据
    int n=3,m=4,p=5;
    ElemType S1[MAXSIZE]={-1,0,9};
    ElemType S2[MAXSIZE]={-25,-10,10,11};
    ElemType S3[MAXSIZE]={2,9,17,30,41};
    int ra,rb,rc;
    FindMinTri(S1,n,S2,m,S3,p,ra,rb,rc);
    cout<<"最小距离对应三元组：("<<ra<<","<<rb<<","<<rc<<")";
    return 0;
}
/*
运行输出：最小距离对应三元组：(9,10,9)
*/