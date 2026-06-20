<div align="center">

# 📚 DataStructuresLearn

**王道 408 数据结构 · 课后习题 C++ 实现仓库**

[![C++20](https://img.shields.io/badge/C++-20-00599C?logo=c%2B%2B)](https://en.cppreference.com/w/cpp/20)
[![CMake](https://img.shields.io/badge/CMake-4.2+-064F8C?logo=cmake)](https://cmake.org/)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
[![Status](https://img.shields.io/badge/状态-持续更新-brightgreen)](https://github.com/sujianyuhi/DataStructuresLearn/commits/main)

</div>

---

## 🎯 项目简介

本仓库是个人备考 **408 计算机学科专业基础综合** 过程中，对 **[王道考研数据结构](https://www.cskaoyan.com/)** 课后习题的 **C++20 代码实现**。

> 代码按照教材章节组织，强调 **思路清晰、注释完整、可独立运行**，适合考研复习、算法面试以及数据结构初学者参考。

涵盖内容：

- ✅ 线性表（顺序表已完成，链表 14 / 20 进行中）
- ⏳ 栈与队列
- ⏳ 字符串
- ⏳ 树与二叉树
- ⏳ 图
- ⏳ 查找
- ⏳ 排序

---

## ✨ 仓库亮点

| 特性 | 说明 |
|------|------|
| 🎓 **考研导向** | 每道题对应王道教材章节，标注统考真题来源 |
| 📝 **思路先行** | 每份源码顶部均包含「题目原文 + 算法思想 + 复杂度分析」 |
| 🧪 **独立可运行** | 每个 `.cpp` 都附带 `main()` 测试用例，可直接编译验证 |
| 🏗️ **CMake 构建** | 使用 CMake 4.2+ 管理，支持命令行与 CLion 一键运行 |
| 🏷️ **难度分级** | 每道题标注 ⭐ ~ ⭐⭐⭐，便于按需学习 |

---

## 📊 学习进度

| 章节 | 题目数 | 进度条 | 状态 |
|:----:|:------:|:-------|:----:|
| 🌱 入门热身 | 1 | `████████████████████████████ 100%` | ✅ 已完成 |
| 📏 顺序表 | 15 | `████████████████████████████ 100%` | ✅ 已完成 |
| 🔗 链表 | 14 / 20 | `████████████████████░░░░░░░░  70%` | ⏳ 进行中 |
| 🥞 栈与队列 | ~12 | `░░░░░░░░░░░░░░░░░░░░░░░░░░░░   0%` | ⏳ 待开始 |
| 🔤 字符串 | ~8 | `░░░░░░░░░░░░░░░░░░░░░░░░░░░░   0%` | ⏳ 待开始 |
| 🌲 树与二叉树 | ~20 | `░░░░░░░░░░░░░░░░░░░░░░░░░░░░   0%` | ⏳ 待开始 |
| 🕸️ 图 | ~15 | `░░░░░░░░░░░░░░░░░░░░░░░░░░░░   0%` | ⏳ 待开始 |
| 🔍 查找 | ~10 | `░░░░░░░░░░░░░░░░░░░░░░░░░░░░   0%` | ⏳ 待开始 |
| 📊 排序 | ~12 | `░░░░░░░░░░░░░░░░░░░░░░░░░░░░   0%` | ⏳ 待开始 |

---

## 📁 题目目录

### 🌱 Start — 入门热身

| 题号 | 题目 | 文件 | 核心知识点 | 难度 |
|:----:|------|:----:|-----------|:----:|
| 1 | 斐波那契数列 | [Fibonac.cpp](Start/Fibonac.cpp) | 递归 vs 迭代、时间复杂度分析、性能测试 | ⭐ |

### 📏 LinearList — 线性表

#### 2.1 顺序表（15 题）

| 题号 | 题目 | 文件 | 核心知识点 | 难度 |
|:----:|------|:----:|-----------|:----:|
| 1 | 删除顺序表最小值元素 | [01MinValueDel.cpp](LinearList/SeqList/01MinValueDel.cpp) | 顺序表遍历、查找最小值、覆盖删除 | ⭐ |
| 2 | 顺序表逆置 | [02ListReverser.cpp](LinearList/SeqList/02ListReverser.cpp) | 双指针交换、原地逆置、空间复杂度 O(1) | ⭐ |
| 3 | 删除所有值为 x 的元素 | [03DelAllX.cpp](LinearList/SeqList/03DelAllX.cpp) | 双指针覆盖、保序删除、时空复杂度 O(n)/O(1) | ⭐ |
| 4 | 删除值在 s~t 之间的所有元素 | [04DeleteBetweenRange.cpp](LinearList/SeqList/04DeleteBetweenRange.cpp) | 区间删除、边界检查、双指针覆盖 | ⭐ |
| 5 | 删除有序顺序表重复元素 | [05RemoveDuplicate.cpp](LinearList/SeqList/05RemoveDuplicate.cpp) | 有序表去重、双指针、原地修改 | ⭐ |
| 6 | 合并两个有序顺序表 | [06MergeTwoOrderedList.cpp](LinearList/SeqList/06MergeTwoOrderedList.cpp) | 双路归并、三指针、有序表合并 | ⭐⭐ |
| 7 | 交换两段线性表的位置 | [07SwapTwoList.cpp](LinearList/SeqList/07SwapTwoList.cpp) | 三次逆置法、区间翻转、原地交换 | ⭐⭐ |
| 8 | 折半查找并插入保持有序 | [08SearchAndInsert.cpp](LinearList/SeqList/08SearchAndInsert.cpp) | 折半查找、插入排序、有序表维护 | ⭐⭐ |
| 9 | 查找三个有序数组的公共元素 | [09FindThreeCommon.cpp](LinearList/SeqList/09FindThreeCommon.cpp) | 三指针法、多路归并、公共元素 | ⭐⭐ |
| 10 | 数组循环左移 p 位（2010 统考真题） | [10LoopLeftShift.cpp](LinearList/SeqList/10LoopLeftShift.cpp) | 三次逆置法、原地翻转、经典真题 | ⭐⭐⭐ |
| 11 | 两个有序数组的中位数（2011 统考真题） | [11TwoArrMid.cpp](LinearList/SeqList/11TwoArrMid.cpp) | 折半查找、区间舍弃、统考真题 | ⭐⭐⭐ |
| 12 | 查找数组中的主元素（2013 统考真题） | [12FindMainNum.cpp](LinearList/SeqList/12FindMainNum.cpp) | 摩尔投票法、候选校验、统考真题 | ⭐⭐⭐ |
| 13 | 未出现的最小正整数（2018 统考真题） | [13FindMinLostInt.cpp](LinearList/SeqList/13FindMinLostInt.cpp) | 原地哈希、下标归位、统考真题 | ⭐⭐⭐ |
| 14 | 三个有序数组的最小距离三元组（2020 统考真题） | [14ThreeArrMinDis.cpp](LinearList/SeqList/14ThreeArrMinDis.cpp) | 三指针、极差最小化、统考真题 | ⭐⭐⭐ |
| 15 | 后缀最大乘积（2025 统考真题） | [15SuffixMaxMul.cpp](LinearList/SeqList/15SuffixMaxMul.cpp) | 二重遍历、后缀最大值、统考真题 | ⭐⭐ |

#### 2.2 链表（14 题）

| 题号 | 题目 | 文件 | 核心知识点 | 难度 |
|:----:|------|:----:|-----------|:----:|
| 1 | 删除所有值为 x 的结点 | [01_DelAllX.cpp](LinearList/LinkedList/01_DelAllX.cpp) | 前驱指针、条件删除、释放结点 | ⭐ |
| 2 | 删除唯一最小值结点 | [02_DelMinNode.cpp](LinearList/LinkedList/02_DelMinNode.cpp) | 遍历找最小、前驱定位、释放结点 | ⭐ |
| 3 | 单链表原地逆置 | [03_ReverseList.cpp](LinearList/LinkedList/03_ReverseList.cpp) | 头插法、原地逆置、空间复杂度 O(1) | ⭐ |
| 4 | 删除值在 minVal~maxVal 之间的所有元素 | [04_DelBetweenVal.cpp](LinearList/LinkedList/04_DelBetweenVal.cpp) | 区间删除、双指针、释放结点 | ⭐ |
| 5 | 查找两个单链表的首个公共结点 | [05_FindCommonNode.cpp](LinearList/LinkedList/05_FindCommonNode.cpp) | 求长度差、同步遍历、Y 型链表 | ⭐⭐ |
| 6 | 链表原地拆分为 A、B 两个子表 | [06_SplitABList.cpp](LinearList/LinkedList/06_SplitABList.cpp) | 奇偶拆分、尾插与头插、原地重组 | ⭐⭐ |
| 7 | 递增有序链表去重 | [07_DelRepeatSort.cpp](LinearList/LinkedList/07_DelRepeatSort.cpp) | 有序链表、相邻重复、保留单个 | ⭐ |
| 8 | 求两个递增有序链表的公共元素（生成新链表 C） | [08_GetCommonSort.cpp](LinearList/LinkedList/08_GetCommonSort.cpp) | 双指针归并、尾插建表、不破坏原表 | ⭐⭐ |
| 9 | 两个递增有序链表求交集（结果存回 A） | [09_GetIntersection.cpp](LinearList/LinkedList/09_GetIntersection.cpp) | 双指针归并、原地复用、释放多余结点 | ⭐⭐ |
| 10 | 判断 B 是否为 A 的连续子序列 | [10_IsSubSequence.cpp](LinearList/LinkedList/10_IsSubSequence.cpp) | 子串匹配、回溯起点、不带头结点 | ⭐⭐ |
| 11 | 判断带头结点循环双链表是否对称 | [11_CircleDLinkSymmetry.cpp](LinearList/LinkedList/11_CircleDLinkSymmetry.cpp) | 循环双链表、首尾双指针、对称判定 | ⭐⭐ |
| 12 | 两个循环双链表拼接为一个 | [12_ConcatCircleDLink.cpp](LinearList/LinkedList/12_ConcatCircleDLink.cpp) | 循环链表、尾结点定位、双向指针修改 | ⭐⭐ |
| 13 | 带访问频域的双链表 Locate 操作 | [13_LocateFreqDLink.cpp](LinearList/LinkedList/13_LocateFreqDLink.cpp) | 双链表、访问频率排序、LRU 思想 | ⭐⭐⭐ |
| 14 | 不带头结点单链表循环右移 k 位 | [14_RightShiftNoHead.cpp](LinearList/LinkedList/14_RightShiftNoHead.cpp) | 成环、断环、不带头结点、原地旋转 | ⭐⭐ |

### 🥞 Stack & Queue — 栈与队列

> ⏳ 待补充...

### 🔤 String — 字符串

> ⏳ 待补充...

### 🌲 Tree — 树与二叉树

> ⏳ 待补充...

### 🕸️ Graph — 图

> ⏳ 待补充...

### 🔍 Search — 查找

> ⏳ 待补充...

### 📊 Sort — 排序

> ⏳ 待补充...

---

## 🛠️ 环境要求

| 依赖 | 版本要求 |
|------|----------|
| 编译器 | GCC 10+ / Clang 12+ / MSVC 2019+ |
| C++ 标准 | **C++20** |
| 构建工具 | CMake 4.2+ |
| 推荐 IDE | CLion / VS Code |

---

## 🚀 快速开始

### 方式一：命令行（CMake）

```bash
# 1. 克隆仓库
git clone https://github.com/sujianyuhi/DataStructuresLearn.git
cd DataStructuresLearn

# 2. 创建构建目录
mkdir build && cd build

# 3. 生成构建文件 & 编译
cmake .. && make

# 4. 运行主程序
./DataStructuresLearn
```

### 方式二：CLion（推荐）

1. 打开 CLion → `File` → `Open`
2. 选择项目根目录，CLion 自动识别 `CMakeLists.txt`
3. 点击右上角 ▶️ 运行按钮即可

### 单独编译某道题目

每道题都是独立可运行的 `.cpp` 文件，也可以单独编译：

```bash
g++ -std=c++20 LinearList/SeqList/10LoopLeftShift.cpp -o 10LoopLeftShift
./10LoopLeftShift
```

---

## 📝 代码规范

- 顺序表基于静态数组实现的 **`SqList`**，链表基于标准 **`LNode` / `DNode`** 结构
- 每份源码顶部包含：**题目原文、算法思想、时间/空间复杂度**
- 算法函数与测试代码分离，便于直接复用
- 关键步骤附带注释，方便对照教材逐行理解

---

## 📖 参考资料

- [王道论坛 — 数据结构考研复习指导](https://www.cskaoyan.com/)
- [408 计算机学科专业基础综合考试大纲](https://www.neea.edu.cn/)
- [cppreference — C++ 中文文档](https://zh.cppreference.com/)

---

## 💬 交流与反馈

本项目为个人考研复习整理，代码和笔记力求准确，但难免存在疏漏。

> 🙏 **如发现代码错误、思路问题或改进建议，欢迎随时提出！**  
> 你可以通过 [Issue](https://github.com/sujianyuhi/DataStructuresLearn/issues) 或 [Pull Request](https://github.com/sujianyuhi/DataStructuresLearn/pulls) 参与共建，一起学习进步！

---

<div align="center">

**⭐ 如果本仓库对你有帮助，欢迎点个 Star 支持一下！**

</div>
