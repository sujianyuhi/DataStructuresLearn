/*
Created by SUJIANYU on 2026/5/28.
题目描述：
线性表(a₁, a₂, a₃, …, aₙ)中的元素递增有序且按顺序存储于计算机内。
要求设计一个算法，完成用最少时间在表中查找数值为x的元素，
若找到，则将其与后继元素位置相交换，
若找不到，则将其插入表中并使表中元素仍然递增有序。
*/
// 引入输入输出库，用于控制台打印
#include<iostream>
using namespace std;

// 定义顺序表最大容量
#define MAXSIZE 100
// 自定义元素类型，统一管理
typedef int ElemType;

// 顺序表结构体定义
typedef struct
{
    // 存储数据的数组
    ElemType data[MAXSIZE];
    // 顺序表当前有效元素个数
    int length;
} SqList;

/**
 * @brief 折半查找（二分查找）函数，在有序顺序表中查找元素x
 * @param L 待查找的有序顺序表
 * @param x 要查找的目标值
 * @return 找到返回下标，未找到返回插入位置（low）
 */
int BinarySearch(SqList &L, ElemType x)
{
    // 左边界
    int low = 0;
    // 右边界
    int high = L.length - 1;

    // 当左边界不大于右边界时，持续查找
    while (low <= high)
    {
        // 计算中间位置下标
        int mid = (low + high) / 2;

        // 找到目标元素
        if (L.data[mid] == x)
        {
            return mid;
        }
        // 目标元素比中间元素大，在右半部分查找
        else if (x > L.data[mid])
        {
            low = mid + 1;
        }
        // 目标元素比中间元素小，在左半部分查找
        else
        {
            high = mid - 1;
        }
    }

    // 未找到元素，返回插入位置low（此时low>high）
    return low;
}

/**
 * @brief 核心函数：查找x，找到则与后继交换；未找到则插入并保持有序
 * @param L 待操作的有序顺序表
 * @param x 目标值
 */
void SearchAndInsert(SqList &L, ElemType x)
{
    // 调用折半查找，获取结果下标
    int pos = BinarySearch(L, x);

    // ------------------- 情况1：找到元素 -------------------
    if (pos < L.length && L.data[pos] == x)
    {
        // 不是最后一个元素，才与后继交换
        if (pos != L.length - 1)
        {
            // 临时变量用于交换
            ElemType temp;
            // 交换当前元素与后继元素
            temp = L.data[pos];
            L.data[pos] = L.data[pos + 1];
            L.data[pos + 1] = temp;
        }
        cout << "找到元素 " << x << "，已与后继元素交换位置" << endl;
    }
    // ------------------- 情况2：未找到元素，需要插入 -------------------
    else
    {
        // 从表尾到插入位置，元素依次后移，腾出位置
        for (int i = L.length; i > pos; i--)
        {
            L.data[i] = L.data[i - 1];
        }

        // 插入x到正确位置
        L.data[pos] = x;
        // 表长加1
        L.length = L.length + 1;
        cout << "未找到元素 " << x << "，已插入表中并保持有序" << endl;
    }
}

// 打印顺序表所有元素
void PrintList(SqList L)
{
    for (int i = 0; i < L.length; i++)
    {
        cout << L.data[i] << " ";
    }
    cout << endl;
}

// 主函数：程序入口，测试功能
int main()
{
    // 定义顺序表变量
    SqList L;
    // 初始化表长
    L.length = 5;
    // 初始化有序顺序表：1 3 5 7 9
    L.data[0] = 1;
    L.data[1] = 3;
    L.data[2] = 5;
    L.data[3] = 7;
    L.data[4] = 9;

    cout << "初始有序表：";
    PrintList(L);

    // 测试1：查找已存在的元素5
    // cout << "\n--- 测试查找已存在元素 5 ---" << endl;
    // SearchAndInsert(L, 5);
    // cout << "操作后表：";
    // PrintList(L);

    // 测试2：查找不存在的元素6
    cout << "\n--- 测试查找不存在元素 6 ---" << endl;
    SearchAndInsert(L, 6);
    cout << "操作后表：";
    PrintList(L);

    return 0;
}