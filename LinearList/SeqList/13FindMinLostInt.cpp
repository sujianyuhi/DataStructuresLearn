/*
Created by SUJIANYU on 2026/5/30.
【题目完整原文 2018统考真题 题号13】
给定含n(n≥1)个整数的数组，设计高效算法找出数组中未出现的最小正整数。
示例：数组{-5,3,2,3}，未出现最小正整数是1；数组{1,2,3}，未出现最小正整数是4。
要求：
1）给出算法基本设计思想；
2）C++代码+关键注释；
3）分析时间、空间复杂度。

【1.算法设计思想（原地哈希，O(n)时间 O(1)空间）】
原理：答案一定落在[1,n+1]区间内。
1. 遍历数组，将区间[1,n]内的数字x放到下标x-1的位置（原地归位）；负数、大于n的数直接跳过。
2. 再次遍历数组，第一个下标i不满足A[i]==i+1，则i+1就是缺失的最小正整数；
3. 若全部A[i]==i+1，答案为n+1。

【3.复杂度说明】
时间复杂度：O(n)，两轮线性遍历数组；
空间复杂度：O(1)，原地修改数组，无额外辅助数组。
*/
#include<iostream>
using namespace std;
#define MAXSIZE 100
typedef int ElemType;

//寻找未出现的最小正整数
int FindMinMiss(ElemType A[],int n)
{
    //第一轮：把1~n的数放到对应下标x-1处
    for(int i=0;i<n;i++)
    {
        //当前数在[1,n]，且没有放到正确位置时循环交换
        while(A[i]>=1 && A[i]<=n && A[A[i]-1] != A[i])
        {
            //交换A[i]与A[A[i]-1]，把数字归位
            int temp = A[A[i]-1];
            A[A[i]-1] = A[i];
            A[i] = temp;
        }
    }
    //第二轮：逐个检查下标
    for(int i=0;i<n;i++)
    {
        //下标i本该存i+1，缺失则i+1为答案
        if(A[i] != i+1)
            return i+1;
    }
    //1~n全存在，最小缺失是n+1
    return n+1;
}

int main()
{
    //测试用例1：{-5,3,2,3} 输出1
    int n1=4;
    ElemType arr1[MAXSIZE]={-5,3,2,3};
    cout<<"用例1缺失最小正整数："<<FindMinMiss(arr1,n1)<<endl;

    //测试用例2：{1,2,3} 输出4
    int n2=3;
    ElemType arr2[MAXSIZE]={1,2,3};
    cout<<"用例2缺失最小正整数："<<FindMinMiss(arr2,n2)<<endl;
    return 0;
}
/*
运行结果：
用例1缺失最小正整数：1
用例2缺失最小正整数：4
*/