cmake_minimum_required(VERSION 3.27)
project(AiZO_Projekt1)

set(CMAKE_CXX_STANDARD 17)
MATH(EXPR stack_size "16 * 1024 * 1024")
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--stack,16777216")

#set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(AiZO_Projekt1 main.cpp
        source/DynamicArray.cpp
        header/DynamicArray.h
        source/MainMenu.cpp
        source/MainMenu.cpp
        header/MainMenu.h
        header/MainMenu.h
        header/Sorter.h
        header/InsertionSort.h
        header/HeapSort.h
        header/QuickSort.h
        source/InsertionSort.cpp
        source/HeapSort.cpp
        source/QuickSort.cpp
        source/BinaryInsertionSort.cpp
        source/BinaryInsertionSort.cpp
        header/BinaryInsertionSort.h
)
