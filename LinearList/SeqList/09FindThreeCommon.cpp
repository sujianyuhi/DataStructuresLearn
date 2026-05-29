/*
Created by SUJIANYU on 2026/5/29.
【题目完整原文】
题号：09 顺序表习题
已知三个整型数组A、B、C，三个数组长度均为n，数组严格递增有序、内部无重复元素。
设计时间尽可能高效的算法，输出同时出现在三个数组中的全部公共元素。
样例：
A={1,2,3}，B={2,3,4}，C={-1,0,2}
输出：2
要求：
1.写出算法设计思想；
2.C++实现代码加注释；
3.给出时间、空间复杂度。

【算法设计思想（答案）】
采用三指针法：
1.定义i,j,k三个下标指针，初始全部从0开始，分别遍历A、B、C；
2.若A[i]==B[j]==C[k]：当前是公共元素，打印，三个指针全部+1；
3.否则三个值中最小的那个不可能是公共值，对应数组指针+1；
4.循环终止条件：任意指针越界(i>=n || j>=n || k>=n)；
【复杂度（答案）】
时间复杂度：O(n)，三个指针最多各自遍历一遍数组，线性遍历；
空间复杂度：O(1)，只使用i,j,k三个临时变量，不开辟额外数组。
*/
#include <iostream>
using namespace std;
#define MAXSIZE 50
typedef int ElemType;

// 查找三个有序数组公共元素函数
void FindCommon(ElemType A[], ElemType B[], ElemType C[], int n)
{
    // i:A下标，j:B下标，k:C下标，起始都在数组首位
    int i = 0, j = 0, k = 0;
    // 任意数组遍历完毕就结束循环
    while (i < n && j < n && k < n)
    {
        // 三数相等，找到公共元素
        if (A[i] == B[j] && B[j] == C[k])
        {
            cout << A[i] << " ";
            // 全部后移
            i++;
            j++;
            k++;
        }
        // A当前值最小，A指针右移
        else if (A[i] < B[j] && A[i] < C[k])
        {
            i++;
        }
        // B当前值最小，B指针右移
        else if (B[j] < A[i] && B[j] < C[k])
        {
            j++;
        }
        // C当前值最小，C指针右移
        else
        {
            k++;
        }
    }
}

int main()
{
    // 题目样例数据
    int n = 3;
    ElemType A[MAXSIZE] = {1, 2, 3};
    ElemType B[MAXSIZE] = {2, 3, 4};
    ElemType C[MAXSIZE] = {-1, 0, 2};

    cout << "三个数组公共元素：";
    FindCommon(A, B, C, n);
    return 0;
}
/*
运行结果：
三个数组公共元素：2
*/

