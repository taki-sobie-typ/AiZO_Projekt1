#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "DynamicArray.h" // Dołączanie pliku nagłówkowego DynamicArray.h, który zawiera definicję klasy DynamicArray.
#include <iostream> // Dołączanie biblioteki iostream dla obsługi strumieni wejścia/wyjścia.
#include <cmath> // Dołączanie biblioteki cmath dla funkcji matematycznych.

template<typename T>
class HeapSort {
public:
    // Metoda sortująca tablicę za pomocą algorytmu sortowania przez kopcowanie.
    static void sort(DynamicArray<T>& arr);

private:
    // Metoda do przesiewania w dół kopca.
    static void heapifyDown(DynamicArray<T>& arr, int n, int i);
};

#endif // HEAPSORT_H