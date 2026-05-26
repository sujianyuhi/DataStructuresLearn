/*
Created by SUJIANYU on 2026/5/26.
对长度为n的顺序表L，编写一个时间复杂度为 O（n）、
空间复杂度 O(1)的算法，该算法删除顺序表中所有值为x的数据元素
*/
// 包含输入输出流库，用于使用 cout 打印输出
#include<iostream>
// 使用标准命名空间，这样可以直接写 cout 而不是 std::cout
using namespace std;

// 定义顺序表的最大容量为50，代表最多能存储50个元素
#define MAXSIZE 50

// 给 int 类型起别名 ElemType，代表顺序表中元素的数据类型
// 好处：以后想改成 double、char 只需要改这一行
typedef int ElemType;

// 定义顺序表结构体（最核心的数据结构）
typedef struct {
    // 数组：真正用来存放数据的容器
    ElemType data[MAXSIZE];
    // length：当前顺序表里实际有多少个元素
    int length;
} SqList;

// ====================== 核心算法 ======================
// 函数功能：删除顺序表中所有值等于 x 的元素
// 参数说明：L 是顺序表的引用（&代表直接修改原表，不复制）
// 时间复杂度：O(n)，只遍历一次数组
// 空间复杂度：O(1)，只使用了常数个变量
void DelAllX(SqList &L, ElemType x) {
    // j 用来记录：新的、删除后的顺序表，元素应该存放的下标位置
    // j 从 0 开始
    int j = 0;

    // 遍历整个顺序表，i 从 0 到 最后一个元素
    for (int i = 0; i < L.length; i++) {
        // 如果当前元素**不等于**要删除的值 x，就保留它
        if (L.data[i] != x) {
            // 把这个需要保留的元素，放到新位置 j 上
            L.data[j] = L.data[i];
            // 新位置下标 j 向后移动一位
            j++;
        }
        // 如果元素等于 x，什么都不做，直接跳过，实现删除
    }

    // 遍历完成后，j 的值就是删除后新表的元素个数
    // 更新顺序表的长度
    L.length = j;
}

// 打印函数：输出顺序表所有元素
void Print(SqList L) {
    // 遍历整个顺序表
    for (int i = 0; i < L.length; i++) {
        // 输出每个元素，后面加空格隔开
        cout << L.data[i] << " ";
    }
    // 换行，让输出更整洁
    cout << endl;
}

// 主函数：程序入口，用于测试算法
int main() {
    // 定义一个顺序表 L
    SqList L;
    // 给顺序表赋值，当前有 6 个元素
    L.length = 6;
    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.data[3] = 2;
    L.data[4] = 4;
    L.data[5] = 2;

    // 输出原始表
    cout << "原表：";
    Print(L);

    // 调用删除函数，删除所有值为 2 的元素
    DelAllX(L, 2);

    // 输出删除后的表
    cout << "删除后：";
    Print(L);

    // 程序正常结束
    return 0;
}
