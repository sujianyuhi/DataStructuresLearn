#include<iostream>
using namespace std;

#define MAXSIZE 100
typedef int ElemType;

// 顺序表结构
typedef struct {
 ElemType data[MAXSIZE];
 int length;
} SqList;

// 合并两个有序表，返回新的有序表
SqList MergeTwoList(SqList L1, SqList L2)
{
 // 新建一个表，用来存放结果
 SqList L3;

 // i 遍历 L1
 int i = 0;
 // j 遍历 L2
 int j = 0;
 // k 遍历新表 L3
 int k = 0;

 // 两个表都没遍历完时
 while (i < L1.length && j < L2.length)
 {
  if (L1.data[i] <= L2.data[j])
  {
   // L1 的元素更小，放进 L3
   L3.data[k] = L1.data[i];
   i = i + 1;    // 下一步
   k = k + 1;    // 下一步
  }
  else
  {
   // L2 的元素更小，放进 L3
   L3.data[k] = L2.data[j];
   j = j + 1;    // 下一步
   k = k + 1;    // 下一步
  }
 }

 // 如果 L1 还有剩下的，全部放进 L3
 while (i < L1.length)
 {
  L3.data[k] = L1.data[i];
  i = i + 1;
  k = k + 1;
 }

 // 如果 L2 还有剩下的，全部放进 L3
 while (j < L2.length)
 {
  L3.data[k] = L2.data[j];
  j = j + 1;
  k = k + 1;
 }

 // 新表的长度
 L3.length = k;

 // 返回合并好的新表
 return L3;
}

// 打印表
void Print(SqList L)
{
 for (int i = 0; i < L.length; i++)
 {
  cout << L.data[i] << " ";
 }
 cout << endl;
}

// 测试
int main()
{
 // 有序表 1
 SqList L1;
 L1.length = 3;
 L1.data[0] = 1;
 L1.data[1] = 3;
 L1.data[2] = 5;

 // 有序表 2
 SqList L2;
 L2.length = 3;
 L2.data[0] = 2;
 L2.data[1] = 4;
 L2.data[2] = 6;

 cout << "L1：";
 Print(L1);
 cout << "L2：";
 Print(L2);

 // 合并
 SqList L3 = MergeTwoList(L1, L2);

 cout << "合并后：";
 Print(L3);

 return 0;
}