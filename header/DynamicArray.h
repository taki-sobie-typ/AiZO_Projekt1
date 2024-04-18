#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>
#include <fstream> // Dla operacji na plikach
#include <cstdlib> // Dla funkcji rand()
#include <ctime>   // Dla inicjowania ziarna funkcji srand()
#include <chrono>  // Dla pomiaru czasu
#include <type_traits> // Dla cech typów

template<typename T>
class DynamicArray {
private:
    T* data; // Wskaźnik do dynamicznie zaalokowanej tablicy
    int size; // Rozmiar tablicy

public:
    // Konstruktor do inicjalizacji DynamicArray z danym rozmiarem
    explicit DynamicArray(int n);

    // Konstruktor kopiujący
    DynamicArray(const DynamicArray& other);

    // Operator przypisania
    DynamicArray& operator=(const DynamicArray& other);

    // Destruktor do zwolnienia dynamicznie zaalokowanej pamięci
    ~DynamicArray();

    // Funkcja wypełniająca tablicę losowymi liczbami z określonego zakresu
    void fillRandom(T min, T max);

    // Funkcja wyświetlająca tablicę w czytelnej formie
    void display();

    // Funkcja zwracająca rozmiar tablicy
    int getSize();

    // Funkcja zwracająca wartość
    T getValue(int index);

    // Funkcja ustawiająca wartość
    void setValue(int index, T value);

    // Funkcja odczytująca dane z pliku tekstowego i wypełniająca nimi tablicę
    void readFromFile(const std::string& filename);

    // Funkcja zwracająca iterator wskazujący na początek tablicy
    T* begin() {
        return data;
    }

    // Funkcja zwracająca iterator wskazujący na koniec tablicy
    T* end() {
        return data + size;
    }
};

#endif // DYNAMICARRAY_H
