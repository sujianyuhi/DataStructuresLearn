cmake_minimum_required(VERSION 4.2)
project(DataStructuresLearn)

set(CMAKE_CXX_STANDARD 20)

add_executable(DataStructuresLearn Start/Fibonac.cpp
        "LinearList/SeqList/01MinValueDel.cpp"
        LinearList/SeqList/02ListReverser.cpp
        LinearList/SeqList/03DelAllX.cpp
        LinearList/SeqList/04DeleteBetweenRange.cpp
        LinearList/SeqList/05RemoveDuplicate.cpp
        LinearList/SeqList/06MergeTwoOrderedList.cpp
        LinearList/SeqList/07SwapTwoList.cpp
        LinearList/SeqList/08SearchAndInsert.cpp)
