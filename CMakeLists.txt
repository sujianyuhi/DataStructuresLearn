cmake_minimum_required(VERSION 4.2)
project(DataStructuresLearn)

set(CMAKE_CXX_STANDARD 20)

add_executable(DataStructuresLearn Start/Fibonac.cpp
        "LinearList/01MinValueDel.cpp"
        LinearList/02ListReverser.cpp
        LinearList/03DelAllX.cpp
        LinearList/04DeleteBetweenRange.cpp
        LinearList/05RemoveDuplicate.cpp
        LinearList/06MergeTwoOrderedList.cpp
        LinearList/07SwapTwoList.cpp
        LinearList/08SearchAndInsert.cpp)
