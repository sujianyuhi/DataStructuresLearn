/*
Created by SUJIANYU on 2026/5/29.
【题目完整原文 2010统考真题 题号10】
设将n(n>1)个整数存放到一维数组R中。设计一个在时间和空间两方面都尽可能高效的算法。
将R中保存的序列循环左移p(0<p<n)个位置，
即将(X₀,X₁,⋯,X_{n−1})变换为(Xₚ,X_{p+1},⋯,X_{n−1},X₀,X₁,⋯,X_{p−1})。
要求：
1）给出算法的基本设计思想；
2）采用C/C++描述算法，关键之处给出注释；
3）说明你所设计算法的时间复杂度和空间复杂度。

【1.算法设计思想（标准答案：三次逆置法）】
核心思路：分段逆置，原地翻转，不开额外数组
1. 将数组前p个元素整体逆置：[X₀~X_{p−1}] 反转
2. 将数组后n-p个元素整体逆置：[Xₚ~X_{n−1}] 反转
3. 将整个n长度数组全部逆置
举例：原[1,2,3,4,5],p=2
①前2位逆置→[2,1,3,4,5]
②后3位逆置→[2,1,5,4,3]
③整体逆置→[3,4,5,1,2]，完成左移2位

【3.复杂度结论】
时间复杂度：O(n)，三次逆置总共遍历数组2n次，线性时间
空间复杂度：O(1)，仅交换用临时变量，原地修改数组，无额外数组开辟
*/
#include<iostream>
using namespace std;
#define MAXSIZE 100
typedef int ElemType;

// 辅助函数：逆置数组R中[left,right]下标区间的元素
void Reverse(ElemType R[], int left, int right)
{
    ElemType temp;
    // 左右指针向中间靠拢，两两交换
    while(left < right)
    {
        temp = R[left];
        R[left] = R[right];
        R[right] = temp;
        left = left + 1;
        right = right - 1;
    }
}

// 核心函数：数组循环左移p位
void LeftShift(ElemType R[], int n, int p)
{
    // 第一步：逆置前p个元素 [0 ~ p-1]
    Reverse(R, 0, p-1);
    // 第二步：逆置后面n-p个元素 [p ~ n-1]
    Reverse(R, p, n-1);
    // 第三步：整体逆置全部元素 [0 ~ n-1]
    Reverse(R, 0, n-1);
}

// 打印数组
void Print(ElemType R[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout << R[i] << " ";
    }
    cout << endl;
}

int main()
{
    // 测试样例：n=5，左移p=2
    int n = 5, p = 2;
    ElemType R[MAXSIZE] = {1,2,3,4,5};
    cout << "原数组：";
    Print(R,n);

    LeftShift(R,n,p);
    cout << "左移"<<p<<"位后：";
    Print(R,n);
    return 0;
}
/*
运行结果：
原数组：1 2 3 4 5
左移2位后：3 4 5 1 2
*/
