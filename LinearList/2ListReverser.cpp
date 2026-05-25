//
// Created by SUJIANYU on 2026/5/25.
//设计一个高效的算法，将顺序表 L 所有元素你只，要求空间复杂度为 O(1)
//
#include<iostream>
using namespace std;

#define MAXSIZE 50
typedef int ElemType;

typedef struct {
    ElemType data[MAXSIZE];
    int length;
} SqList;

// ✅ 顺序表逆置，空间 O(1)
void ReverseList(SqList &L) {
    ElemType temp;        // 仅用1个临时变量
    int i = 0;            // 左指针
    int j = L.length - 1; // 右指针

    // 两边往中间交换
    while (i < j) {
        // 交换 L.data[i] 和 L.data[j]
        temp = L.data[i];
        L.data[i] = L.data[j];
        L.data[j] = temp;

        i++;  // 左指针右移
        j--;  // 右指针左移
    }
}

// 打印
void Print(SqList L) {
    for (int k = 0; k < L.length; k++)
        cout << L.data[k] << " ";
    cout << endl;
}

// 测试
int main() {
    SqList L;
    L.length = 5;
    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.data[3] = 4;
    L.data[4] = 5;

    cout << "原表：";
    Print(L);

    ReverseList(L); // 逆置

    cout << "逆置：";
    Print(L);
    return 0;
}
