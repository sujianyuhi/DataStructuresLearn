// 包含输入输出流
#include<iostream>
using namespace std;

// 顺序表最大长度
#define MAXSIZE 50

// 元素类型
typedef int ElemType;

// 顺序表结构体定义
typedef struct {
    ElemType data[MAXSIZE];  // 数据数组
    int length;              // 当前元素个数
} SqList;

// ===================== 核心算法 =====================
// 功能：删除有序顺序表中重复的元素，使所有元素唯一
// 前提：顺序表有序（王道408此题默认有序）
// 时间复杂度：O(n)
// 空间复杂度：O(1)
void RemoveDuplicate(SqList &L) {
    // 如果表空，直接返回
    if (L.length == 0) {
        cout << "顺序表为空！" << endl;
        return;
    }

    // j 指向新表最后一个元素的位置（从第一个元素开始）
    int j = 0;

    // i 从第二个元素开始遍历，和前一个比较
    for (int i = 1; i < L.length; i++) {
        // 如果当前元素 不等于 新表最后一个元素 → 保留
        if (L.data[i] != L.data[j]) {
            j++;                // 新表位置后移
            L.data[j] = L.data[i];  // 把不重复的元素放进来
        }
        // 相等 → 跳过（删除）
    }

    // 新表长度 = j + 1
    L.length = j + 1;
}

// 打印函数
void Print(SqList L) {
    for (int i = 0; i < L.length; i++) {
        cout << L.data[i] << " ";
    }
    cout << endl;
}

// 测试
int main() {
    // 有序顺序表：1 2 2 3 3 3 4 5 5
    SqList L;
    L.length = 9;
    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 2;
    L.data[3] = 3;
    L.data[4] = 3;
    L.data[5] = 3;
    L.data[6] = 4;
    L.data[7] = 5;
    L.data[8] = 5;

    cout << "原表：";
    Print(L);

    RemoveDuplicate(L);  // 删除重复元素

    cout << "去重后：";
    Print(L);

    return 0;
}