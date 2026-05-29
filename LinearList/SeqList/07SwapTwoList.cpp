/*
 Created by SUJIANYU on 2026/5/28.
在一维数组 A[m+n] 中，依次存放两个线性表 (a₁,a₂,…,aₘ) 和 (b₁,b₂,…,bₙ)，
编写函数将两者位置互换，即把 b 表放到 a 表前面，最终数组为 (b₁,b₂,…,bₙ,a₁,a₂,…,aₘ)。
*/
// 引入输入输出库，用于控制台打印
#include<iostream>
using namespace std;

// 定义顺序表数组最大容量
#define MAXSIZE 100
// 自定义元素类型，统一管理
typedef int ElemType;

// 顺序表结构体定义
typedef struct
{
 // 存储数据的数组
 ElemType data[MAXSIZE];
 // 顺序表当前有效元素总个数
 int length;
} SqList;

/**
 * @brief 区间逆置函数：将顺序表中 [left, right] 下标范围内的元素翻转
 * @param L 待操作的顺序表
 * @param left 区间左边界下标
 * @param right 区间右边界下标
 */
void ReverseRange(SqList &L, int left, int right)
{
 // 左指针小于右指针时，持续交换元素
 while (left < right)
 {
  // 临时变量，用于交换两个元素
  ElemType temp;
  // 交换左右指针指向的元素
  temp = L.data[left];
  L.data[left] = L.data[right];
  L.data[right] = temp;

  // 左指针向右移动一位
  left = left + 1;
  // 右指针向左移动一位
  right = right - 1;
 }
}

/**
 * @brief 核心函数：互换同一数组内两段连续线性表
 * @param L 存储两段线性表的顺序表
 * @param m 第一段线性表（前半段）的元素个数
 * @param n 第二段线性表（后半段）的元素个数
 * 原结构：[A段(m个) , B段(n个)]
 * 目标结构：[B段(n个) , A段(m个)]
 */
void ExchangeTwoPart(SqList &L, int m, int n)
{
 // 第一步：逆置整个数组，范围 0 ~ (总长度-1)
 ReverseRange(L, 0, m + n - 1);

 // 第二步：逆置原B段（现在处于数组前n位），范围 0 ~ (n-1)
 ReverseRange(L, 0, n - 1);

 // 第三步：逆置原A段（现在处于数组后m位），范围 n ~ (m+n-1)
 ReverseRange(L, n, m + n - 1);
}

// 打印函数：遍历并输出顺序表所有元素
void PrintList(SqList L)
{
 for (int i = 0; i < L.length; i++)
 {
  cout << L.data[i] << " ";
 }
 // 打印完所有元素后换行
 cout << endl;
}

// 主函数：程序入口，用于测试功能
int main()
{
 // 定义顺序表变量
 SqList L;
 // 第一段元素个数 m，第二段元素个数 n
 int m = 3;
 int n = 3;
 // 设置顺序表总长度 = m + n
 L.length = m + n;

 // 初始化：前m个元素为A段 [1,2,3]
 L.data[0] = 1;
 L.data[1] = 2;
 L.data[2] = 3;
 // 初始化：后n个元素为B段 [4,5,6]
 L.data[3] = 4;
 L.data[4] = 5;
 L.data[5] = 6;

 cout << "交换前（A段在前，B段在后）：";
 PrintList(L);

 // 调用函数，互换两段区间
 ExchangeTwoPart(L, m, n);

 cout << "交换后（B段在前，A段在后）：";
 PrintList(L);

 return 0;
}
