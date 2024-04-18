#include "../header/DynamicArray.h"

template<typename T>
DynamicArray<T>::DynamicArray(int n) {
    size = n; // Inicjalizacja rozmiaru tablicy
    data = new T[size]; // Dynamiczna alokacja pamięci dla tablicy
}

// Konstruktor kopiujący
template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray& other) : size(other.size) {
    data = new T[size]; // Alokacja pamięci dla nowej tablicy
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i]; // Skopiowanie danych
    }
}

// Operator przypisania
template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& other) {
    if (this != &other) { // Sprawdzenie czy nie przypisujemy samego siebie
        delete[] data; // Zwolnienie starej pamięci
        size = other.size;
        data = new T[size]; // Alokacja nowej pamięci
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i]; // Skopiowanie danych
        }
    }
    return *this;
}

// Destruktor
template<typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] data; // Zwolnienie pamięci
}

// Metoda wypełniająca tablicę losowymi liczbami z określonego zakresu
template<typename T>
void DynamicArray<T>::fillRandom(T min, T max) {
    srand(time(nullptr)); // Inicjalizacja generatora liczb losowych aktualnym czasem
    for (int i = 0; i < size; ++i) {
        if constexpr (std::is_integral_v<T>) {
            // Dla typów całkowitoliczbowych
            T randomNumber = min + static_cast<T>(rand()) % (max - min + 1);
            data[i] = randomNumber;
        } else {
            // Dla typów zmiennoprzecinkowych
            double randomFraction = static_cast<double>(rand()) / RAND_MAX;
            T randomNumber = min + static_cast<T>(randomFraction * (max - min));
            data[i] = randomNumber;
        }
    }
}

// Metoda zwracająca wartość z określonego indeksu
template<typename T>
T DynamicArray<T>::getValue(int index) {
    if (index >= 0 && index < size) {
        return data[index]; // Zwrócenie wartości z tablicy
    } else {
        throw std::out_of_range("Index out of bounds!"); // Rzucenie wyjątku w przypadku indeksu spoza zakresu
    }
}

// Metoda ustawiająca wartość na określonym indeksie
template<typename T>
void DynamicArray<T>::setValue(int index, T value) {
    if (index >= 0 && index < size) {
        data[index] = value; // Ustawienie wartości w tablicy
    } else {
        throw std::out_of_range("Index out of bounds!"); // Rzucenie wyjątku w przypadku indeksu spoza zakresu
    }
}

// Metoda wyświetlająca tablicę
template<typename T>
void DynamicArray<T>::display() {
    std::cout << "Array: ";
    if (size > 0) {
        std::cout << data[0];
        for (int i = 1; i < size; ++i) {
            std::cout << ", " << data[i]; // Wyświetlenie elementów oddzielonych przecinkiem
        }
    }
    std::cout << std::endl;
}

// Metoda zwracająca rozmiar tablicy
template<typename T>
int DynamicArray<T>::getSize() {
    return size;
}

// Metoda wczytująca dane z pliku tekstowego i wypełniająca nimi tablicę
template<typename T>
void DynamicArray<T>::readFromFile(const std::string& filename) {
    std::ifstream file(filename); // Utworzenie strumienia plikowego
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl; // Komunikat o błędzie w przypadku nieudanego otwarcia pliku
        return;
    }

    file >> size; // Pierwsza liczba w pliku określa rozmiar tablicy
    delete[] data; // Zwolnienie istniejącej pamięci
    data = new T[size]; // Alokacja nowej pamięci na podstawie rozmiaru z pliku

    for (int i = 0; i < size; ++i) {
        file >> data[i]; // Odczytanie każdej liczby z pliku do tablicy
    }

    file.close(); // Zamknięcie pliku
}

// DynamicArray dla potrzebnych typów
template class DynamicArray<int>;
template class DynamicArray<float>;
template class DynamicArray<char>;
