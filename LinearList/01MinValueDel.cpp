/*
 *从顺序表中删除具有最小值的元素（假设唯一），并有含数返回被删元素的值。
 *空出的位置由最后一个元素填补，若顺序表为空，则显示出错信息并退出运行
 */
#include<iostream>
using namespace std;
#define MAXSIZE 10
typedef int ElemType;
typedef struct {
    ElemType data[MAXSIZE];
    int Length;
}SqList;

bool Del_Min(SqList &L, ElemType &value) {
    if (L.Length == 0)
        return false;
    value = L.data[0];
    int pos = 0;//假设 0 号元素值最小
    for (int i = 1; i < L.Length; i++)
        if (L.data[i] < value) {
            value = L.data[i];
            pos = i;
        }
    L.data[pos] = L.data[L.Length - 1];
    L.Length--;
    return true;
}
void print(SqList &L) {
    for (int i = 0; i < L.Length; i++)
        cout << L.data[i] << " ";
    cout << endl;

}
int main() {
    SqList L;
    ElemType value;
    L.Length = 6;
    L.data[0] = 5;
    L.data[1] = 2;
    L.data[2] = 8;
    L.data[3] = 1;
    L.data[4] = 9;
    L.data[5] = 3;
    cout << "原表："<< endl;
    print(L);

    if (Del_Min(L,value)) {
        cout << "删除的最小值：" << value << endl;
        cout << "删除后：";
        print(L);
    }else
        cout << "表空，删除失败！" << endl;

    return 0;
}