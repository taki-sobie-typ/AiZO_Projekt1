#include "../header/InsertionSort.h"

template<typename T>
void InsertionSort<T>::sort(DynamicArray<T>& arr) {
    for (int i = 1; i < arr.getSize(); ++i) {
        T key = arr.getValue(i); // Wartość aktualnie analizowanego elementu.
        int j = i; // Zmienna pomocnicza do poruszania się po tablicy.
        while (j > 0 && arr.getValue(j - 1) > key) { // Pętla while wykonuje przesunięcia elementów w tablicy w celu wstawienia elementu w odpowiednie miejsce.
            arr.setValue(j, arr.getValue(j - 1)); // Przesuń elementy w prawo, aby zrobić miejsce dla aktualnego elementu.
            --j; // Przesuń się w lewo po tablicy.
        }
        arr.setValue(j, key); // Wstaw aktualny element w odpowiednie miejsce.
    }
}

template class InsertionSort<int>;
template class InsertionSort<float>;
template class InsertionSort<char>;
