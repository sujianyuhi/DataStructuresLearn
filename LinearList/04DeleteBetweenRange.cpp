/*
// Created by SUJIANYU on 2026/5/26.
从顺序表中删除其值在给定值s和t之间（包含s和t，要求s<t）的所有元素，
若s或t不合理或顺序表为空，则显示出错信息并退出运行
*/
// 包含输入输出流，用于打印和输入
#include<iostream>
using namespace std;

// 顺序表最大长度
#define MAXSIZE 50

// 元素类型统一用 ElemType，方便修改
typedef int ElemType;

// 顺序表结构体定义
typedef struct {
    ElemType data[MAXSIZE];  // 数组存储元素
    int length;              // 当前元素个数
} SqList;

// ===================== 核心算法 =====================
// 函数功能：删除顺序表中值在 s~t 之间（包含 s、t）的所有元素
// 参数说明：L 顺序表，s 下限，t 上限
// 条件：必须满足 s < t，且表不为空，否则报错退出
void DelBetweenST(SqList &L, ElemType s, ElemType t) {
    // 第一步：判断所有异常情况
    // 1. 表为空
    if (L.length == 0) {
        cout << "错误：顺序表为空！" << endl;
        return;
    }
    // 2. s >= t，区间不合法
    if (s >= t) {
        cout << "错误：s 必须小于 t！" << endl;
        return;
    }

    // 第二步：开始删除（双指针思想，空间 O(1)）
    int j = 0;  // j = 新表下标（保留的元素往这里放）

    // 遍历原表
    for (int i = 0; i < L.length; i++) {
        // 保留：不在 s~t 之间的元素
        if (L.data[i] < s || L.data[i] > t) {
            L.data[j] = L.data[i];
            j++;
        }
        // 在 s~t 之间 → 直接跳过（删除）
    }

    // 更新表长度为保留元素个数 j
    L.length = j;
    cout << "删除成功！" << endl;
}

// 打印顺序表
void Print(SqList L) {
    for (int i = 0; i < L.length; i++) {
        cout << L.data[i] << " ";
    }
    cout << endl;
}

// 测试主函数
int main() {
    SqList L;
    L.length = 6;
    L.data[0] = 1;
    L.data[1] = 3;
    L.data[2] = 5;
    L.data[3] = 7;
    L.data[4] = 9;
    L.data[5] = 4;

    cout << "原表：";
    Print(L);

    // 删除 2~6 之间的数
    DelBetweenST(L, 2, 6);

    cout << "删除后：";
    Print(L);

    return 0;
}
