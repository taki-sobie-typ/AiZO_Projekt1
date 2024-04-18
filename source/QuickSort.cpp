#include "../header/QuickSort.h"

template<typename T>
void QuickSort<T>::sort(DynamicArray<T>& arr) {
    quickSort(arr, 0, arr.getSize() - 1); // Wywołanie funkcji sortowania szybkiego na całej tablicy.
}

template<typename T>
void QuickSort<T>::quickSort(DynamicArray<T>& arr, int low, int high) {
    if (low >= high) return; // Warunek stopu rekurencji - gdy podtablica zawiera 0 lub 1 element.
    int pi = partition(arr, low, high); // Podział tablicy i uzyskanie indeksu pivotu.
    quickSort(arr, low, pi); // Sortowanie rekurencyjne lewej podtablicy.
    quickSort(arr, pi + 1, high); // Sortowanie rekurencyjne prawej podtablicy.
}

template<typename T>
int QuickSort<T>::partition(DynamicArray<T>& arr, int left, int right) {
    T pivot = arr.getValue(left); // Wybór pierwszego elementu jako pivotu.
    int l = left; // Lewy wskaźnik.
    int r = right; // Prawy wskaźnik.

    while (true) {
        while (arr.getValue(l) < pivot) ++l; // Przesuwanie lewego wskaźnika w prawo, dopóki elementy są mniejsze od pivotu.
        while (arr.getValue(r) > pivot) --r; // Przesuwanie prawego wskaźnika w lewo, dopóki elementy są większe od pivotu.

        if (l < r) { // Jeśli wskaźniki się nie minęły.
            T temp = arr.getValue(l);
            arr.setValue(l, arr.getValue(r)); // Zamiana miejscami elementów wskazywanych przez wskaźniki.
            arr.setValue(r, temp);
            ++l; // Przesunięcie wskaźników.
            --r;
        } else {
            if (r == right) --r; // Jeśli wskaźnik r wskazuje na ostatni element, przesuń go w lewo.
            return r; // Zwrócenie indeksu pivotu po zakończeniu partycjonowania.
        }
    }
}


template class QuickSort<int>;
template class QuickSort<float>;
template class QuickSort<char>;
