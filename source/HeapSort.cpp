#include "../header/HeapSort.h"

template<typename T>
void HeapSort<T>::sort(DynamicArray<T>& arr) {
    int n = arr.getSize(); // Liczba elementów w tablicy.

    // Budowanie kopca (przebudowa tablicy)
    for (int i = (n - 1 - 1) / 2; i >= 0; --i)
        heapifyDown(arr, n, i); // Wywołanie funkcji do przesiewania w dół kopca.

    // Iteracyjne pobieranie elementów z kopca
    for (int i = n - 1; i > 0; --i) {
        // Zamiana aktualnego korzenia z ostatnim elementem
        T temp = arr.getValue(0);
        arr.setValue(0, arr.getValue(i));
        arr.setValue(i, temp);

        // Wywołanie przesiewania w dół na zmniejszonym kopcu
        heapifyDown(arr, i, 0);
    }
}

template<typename T>
void HeapSort<T>::heapifyDown(DynamicArray<T>& arr, int n, int i) {
    while (true) {
        int largest = i;  // Inicjalizacja największego elementu jako korzeń
        int l = 2 * i + 1;  // lewy = 2*i + 1
        int r = 2 * i + 2;  // prawy = 2*i + 2

        // Jeśli lewy potomek jest większy niż korzeń
        if (l < n && arr.getValue(l) > arr.getValue(largest))
            largest = l;

        // Jeśli prawy potomek jest większy niż dotychczasowy największy
        if (r < n && arr.getValue(r) > arr.getValue(largest))
            largest = r;

        // Jeśli największy nie jest korzeniem
        if (largest != i) {
            T temp = arr.getValue(i);
            arr.setValue(i, arr.getValue(largest));
            arr.setValue(largest, temp);

            // Przejdź do następnego poziomu
            i = largest;
        } else {
            break;
        }
    }
}

template class HeapSort<int>;
template class HeapSort<float>;
template class HeapSort<char>;
