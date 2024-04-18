#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include "DynamicArray.h" // Dołączanie pliku nagłówkowego DynamicArray.h, który zawiera definicję klasy DynamicArray.
#include <iostream> // Dołączanie biblioteki iostream dla obsługi strumieni wejścia/wyjścia.

template<typename T>
class InsertionSort {
public:
    // Metoda sortująca tablicę za pomocą algorytmu sortowania przez wstawianie.
    static void sort(DynamicArray<T>& arr);
};

#endif // INSERTIONSORT_H
