#ifndef MAINMENU_H
#define MAINMENU_H

#include <iostream>
#include <string>
#include "DynamicArray.h"
#include "Sorter.h"
#include <fstream> // Do operacji na plikach
#include <algorithm> // Do używania algorytmów standardowych


class MainMenu {
public:
    MainMenu(); // Konstruktor

    ~MainMenu() = default; // Destruktor

    void startMenu(); // Metoda rozpoczynająca działanie menu

private:
    // Metody pomocnicze
    void testCorrectness();
    void testCorrectnessFile();
    void testCorrectnessGenerateYourSelf();
    void testForReport();
    void testSpecificScenario();

    // Metoda statyczna do wyboru nazwy pliku
    static std::string chooseFileName();

    // Metoda statyczna do pomiaru i zapisu czasu sortowania
    static void measureAndSaveSortingTime(int size, const std::string& type, const std::string& algorithmName, std::chrono::duration<double> elapsedTime);

    // Metoda statyczna do pobrania wyboru użytkownika
    static int getChoice();

    // Metoda dorozpoczęcia sortowania dla określonego scenariusza
    template<typename T>
    void beginSortingForSpecificScenario(const DynamicArray<T>& initialArray, const std::string& type, int size);

    // Metoda do generowania losowej tablicy
    template<typename T>
    DynamicArray<T> generateRandomArray(int size, int min, int max);

    // Metoda do wczytywania tablicy z pliku
    template<typename T>
    DynamicArray<T> loadArrayFromFile(const std::string& filename);

    // Metoda rozpoczęcia sortowania dla sprawdzania poprawności
    template<typename T>
    void beginSortingCorectness(const DynamicArray<T>& initialArray);

    // Metoda rozpoczęcia sortowania dla raportu
    template<typename T>
    void beginSortingForReport(const DynamicArray<T>& initialArray, const std::string& type, int size);

    // Metoda rozpoczęcia sortowania dla raportu z wykorzystaniem sortowania przez wstawianie
    template<typename T>
    void beginSortingForReportInsertion(const DynamicArray<T>& initialArray, const std::string& type, int size);

    // Metodasprawdzenia poprawności sortowania
    template<typename T>
    void sortingCheck(const DynamicArray<T>& initialArray);

    // Tablice przechowujące dane
    DynamicArray<int> intArray;
    DynamicArray<float> floatArray;
    DynamicArray<char> charArray;
};

#endif // MAINMENU_H
