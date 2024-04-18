#ifndef SORTER_H
#define SORTER_H

#include "DynamicArray.h"
#include "InsertionSort.h"
#include "BinaryInsertionSort.h"
#include "HeapSort.h"
#include "QuickSort.h"
#include <iostream>
#include <string>

template<typename T>
class Sorter {
public:
    void sortArray(DynamicArray<T>& arr, const std::string& algorithm);
private:
    InsertionSort<T> insertionSort;
    BinaryInsertionSort<T> binaryInsertionSort;
    HeapSort<T> heapSort;
    QuickSort<T> quickSort;
};

template<typename T>
void Sorter<T>::sortArray(DynamicArray<T>& arr, const std::string& algorithm) {
    if (algorithm == "InsertionSort") {
        insertionSort.sort(arr);
    } else if (algorithm == "BinaryInsertionSort") {
        binaryInsertionSort.sort(arr);
    } else if (algorithm == "HeapSort") {
        heapSort.sort(arr);
    } else if (algorithm == "QuickSort") {
        quickSort.sort(arr);
    } else {
        std::cerr << "Unknown sorting algorithm: " << algorithm << std::endl;
    }
}

#endif // SORTER_H
