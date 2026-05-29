<div align="center">

# 📚 DataStructuresLearn

**王道计算机考研 408 数据结构课程练习题代码实现**

[![C++20](https://img.shields.io/badge/C++-20-00599C?logo=c%2B%2B)](https://en.cppreference.com/w/cpp/20)
[![CMake](https://img.shields.io/badge/CMake-4.2+-064F8C?logo=cmake)](https://cmake.org/)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)

</div>

---

## ✨ 项目简介

本项目是 [王道计算机考研](https://www.cskaoyan.com/) 408 数据结构课程配套练习题的 **C++ 代码实现**。

涵盖线性表、栈与队列、树与二叉树、图、查找、排序等核心章节，代码力求简洁清晰，适合考研复习与面试准备。

---

## 📋 学习进度

| 章节 | 进度 | 状态 |
|:----:|:----:|:----:|
| 🌱 入门热身 | 1 / 1 | ✅ 已完成 |
| 📏 线性表 | 8 / ~15 | 🚧 进行中 |
| 🥞 栈与队列 | 0 / ~12 | ⏳ 待开始 |
| 🔤 字符串 | 0 / ~8 | ⏳ 待开始 |
| 🌲 树与二叉树 | 0 / ~20 | ⏳ 待开始 |
| 🕸️ 图 | 0 / ~15 | ⏳ 待开始 |
| 🔍 查找 | 0 / ~10 | ⏳ 待开始 |
| 📊 排序 | 0 / ~12 | ⏳ 待开始 |

---

## 📁 项目目录

### 🌱 Start — 入门热身

| 题号 | 题目 | 文件 | 核心知识点 | 难度 |
|:----:|------|:----:|-----------|:----:|
| 1 | 斐波那契数列 | [Fibonac.cpp](Start/Fibonac.cpp) | 递归 vs 迭代、时间复杂度分析、性能测试 | ⭐ |

### 📏 LinearList — 线性表

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

# 4. 运行
./DataStructuresLearn
```

### 方式二：CLion（推荐）

1. 打开 CLion → `File` → `Open`
2. 选择项目根目录，CLion 自动识别 `CMakeLists.txt`
3. 点击右上角 ▶️ 运行按钮即可

---

## 🎯 代码规范

- 数据结构采用 **顺序表（`SqList`）** 实现，基于静态数组
- 算法函数与测试代码分离，便于直接复用
- 关键步骤附带注释，方便对照教材理解

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

**⭐ 如果对你有帮助，欢迎点个 Star 支持一下！**

</div>
