cmake_minimum_required(VERSION 3.29)
project(DS2024A)

set(CMAKE_CXX_STANDARD 14)

# 包含实验 2 和实验 3 的文件夹
include_directories(exp2)
include_directories(exp3)
include_directories(Mylab)

# 实验 2 的可执行目标
add_executable(exp2_main
        exp2/main.cpp
        Mylab/List.h
        Mylab/Stack.h
        Mylab/Vector.h
        Mylab/ListNode.h
)

# 实验 3 的可执行目标
add_executable(exp3_main
        exp3/main.cpp
        exp3/Bitmap.h
        exp3/HuffCode.h
        Mylab/List.h
        Mylab/Stack.h
        Mylab/Vector.h
        Mylab/ListNode.h
        Mylab/Bintree.h
        Mylab/HuffTree.h
)
