#include "../header/BinaryInsertionSort.h"

template<typename T>
void BinaryInsertionSort<T>::sort(DynamicArray<T>& arr) {
    for (int i = 1; i < arr.getSize(); ++i) {
        T key = arr.getValue(i); // Przechowuje wartość aktualnie analizowanego elementu.
        int left = 0; // Lewy wskaźnik dla wyszukiwania binarnego.
        int right = i - 1; // Prawy wskaźnik dla wyszukiwania binarnego.
        int mid; // Środkowy wskaźnik dla wyszukiwania binarnego.

        // Znajdź odpowiednią pozycję dla elementu key używając wyszukiwania binarnego.
        while (left <= right) {
            mid = left + (right - left) / 2; // Obliczenie środkowego indeksu.
            if (arr.getValue(mid) == key) { // Jeśli znaleziono klucz, przerwij pętlę.
                break;
            } else if (arr.getValue(mid) < key) { // Jeśli wartość w połowie jest mniejsza od klucza, przesuń lewy wskaźnik.
                left = mid + 1;
            } else { // W przeciwnym razie, przesuń prawy wskaźnik.
                right = mid - 1;
            }
        }

        // Jeśli element jest większy od wszystkich elementów w tablicy.
        if (left > right) {
            mid = left; // Ustaw środkowy indeks na lewy, co oznacza wstawienie na koniec tablicy.
        }

        // Przesuń wszystkie elementy większe od key o jedną pozycję w prawo.
        for (int j = i - 1; j >= mid; --j) {
            arr.setValue(j + 1, arr.getValue(j)); // Przesuń element w prawo.
        }

        // Wstaw key na właściwe miejsce.
        arr.setValue(mid, key); // Wstaw klucz na znalezione miejsce.
    }
}


template class BinaryInsertionSort<int>;
template class BinaryInsertionSort<float>;
template class BinaryInsertionSort<char>;
