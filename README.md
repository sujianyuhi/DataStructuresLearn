# DataStructuresLearn

王道计算机考研 408 数据结构课程练习题代码实现。

## 项目结构

```
DataStructuresLearn/
├── Start/              # 入门练习
│   └── Fibonac.cpp     # 斐波那契数列（递归 vs 迭代性能对比）
├── LinearList/         # 线性表
│   └── MinValueDel.cpp # 删除顺序表中最小值元素
├── CMakeLists.txt      # CMake 构建配置
└── .gitignore          # Git 忽略规则
```

## 环境要求

- **编译器**：支持 C++20 的编译器（GCC 10+ / Clang 12+ / MSVC 2019+）
- **构建工具**：CMake 4.2+
- **IDE**：CLion（推荐）或 VS Code

## 构建与运行

### 使用 CMake

```bash
# 创建构建目录
mkdir build && cd build

# 生成构建文件
cmake ..

# 编译
make

# 运行
./DataStructuresLearn
```

### 使用 CLion

直接用 CLion 打开项目根目录，IDE 会自动识别 `CMakeLists.txt` 并配置构建环境。

## 题目列表

### Start — 入门

| 文件 | 题目 | 知识点 |
|------|------|--------|
| [Fibonac.cpp](Start/Fibonac.cpp) | 斐波那契数列 | 递归 vs 迭代、时间复杂度对比、性能测试 |

### LinearList — 线性表

| 文件 | 题目 | 知识点 |
|------|------|--------|
| [MinValueDel.cpp](LinearList/MinValueDel.cpp) | 删除顺序表最小值元素 | 顺序表、查找最小值、删除操作 |

## 代码风格

- 使用 **顺序表（SqList）** 实现线性表，基于静态数组
- 算法实现与测试代码分离，便于复用
- 包含基础输入输出验证

## 参考

- 王道论坛：《数据结构》考研复习指导
- 408 计算机学科专业基础综合考试大纲
