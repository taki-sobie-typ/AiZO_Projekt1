#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "DynamicArray.h"
#include <iostream>
#include <cmath>

template<typename T>
class QuickSort {
public:
    static void sort(DynamicArray<T>& arr);
private:
    static int partition(DynamicArray<T>& arr, int low, int high);
    static void quickSort(DynamicArray<T>& arr, int low, int high);
};

#endif // QUICKSORT_H
