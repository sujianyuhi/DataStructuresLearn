#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;

//递归
int fib_recursion(int n)
{
    if (n<=0)
        return 0;
    if (n==1)
        return 1;
    else return fib_recursion(n-1) + fib_recursion(n-2);
}

//非递归
int fib_iterative(int n) {
    if (n<=0)
        return 0;
    if (n==1)
        return 1;
    int a = 0, b = 1;
    int res;
    for (int i=2; i<=n; i++) {
        res = a + b;
        a = b;
        b = res;
    }
    return res;
}

int main() {
    int n;
    cout << "请输入 n：";
    cin >> n;
    cout << fixed << setprecision(6);

    // ======================
    // 先算 非递归 → 立刻输出
    // ======================
    clock_t start1 = clock();
    int res1 = fib_iterative(n);
    clock_t end1 = clock();
    double time1 = (double)(end1 - start1) / CLOCKS_PER_SEC;

    cout << "\n非递归结果：" << res1 << endl;
    cout << "非递归耗时：" << time1 << " 秒\n" << endl;

    // ======================
    // 再算 递归 → 算完再输出
    // ======================
    clock_t start2 = clock();
    int res2 = fib_recursion(n);
    clock_t end2 = clock();
    double time2 = (double)(end2 - start2) / CLOCKS_PER_SEC;

    cout << "递归结果：" << res2 << endl;
    cout << "递归耗时：" << time2 << " 秒\n" << endl;

    return 0;
}