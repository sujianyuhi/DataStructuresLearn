/*
Created by SUJIANYU on 2026/5/30.
【题目完整原文 2025统考真题 题号15】
给定等长n的数组A、res；对每个下标i(0≤i≤n−1)，res[i]=max{A[i]×A[j] | i≤j≤n−1}
样例：A={1,4,-9,6} → res={6,24,81,36}
【你的思路：二重遍历，固定i，j从i到末尾逐个相乘，记录最大值】
1）算法思想：
外层i遍历每个位置，初始化当前最大值=A[i]*A[i]；内层j=i~n-1，逐个算A[i]*A[j]，更大就刷新最大值，循环结束存入res[i]
2）复杂度：时间O(n²)、空间O(1)
*/
#include<iostream>
using namespace std;
#define MAXSIZE 100
typedef int ElemType;

//题目规定函数名 calMulMax
void calMulMax(int A[],int res[],int n)
{
    for(int i=0;i<n;i++)
    {
        //初始：i和自己相乘
        int max_tmp = A[i] * A[i];
        //j从i往后全部遍历
        for(int j=i+1;j<n;j++)
        {
            int mul = A[i] * A[j];
            if(mul > max_tmp)
                max_tmp = mul;
        }
        res[i] = max_tmp;
    }
}

int main()
{
    int n=4;
    ElemType A[MAXSIZE]={1,4,-9,6};
    ElemType res[MAXSIZE];
    calMulMax(A,res,n);

    cout<<"res数组：";
    for(int i=0;i<n;i++){
        cout<<res[i]<<" ";
    }
    return 0;
}
/*
运行结果：res数组：6 24 81 36
*/