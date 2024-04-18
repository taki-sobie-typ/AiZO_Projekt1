#include "../header/MainMenu.h"
int choice;

MainMenu::MainMenu() : intArray(0), floatArray(0), charArray(0) {
}

void MainMenu::startMenu() {
    std::cout << "Choose test type:" << std::endl;
    std::cout << "1. Algorithm correctness test" << std::endl;
    std::cout << "2. Test for report" << std::endl;
    std::cout << "3. Test for specific scenario" << std::endl;
    choice = getChoice();

    switch (choice) {
        case 1:
            testCorrectness(); // Wywołanie funkcji testującej poprawność algorytmu
            break;
        case 2:
            std::cout << "Report Test Procedure Starting!:" << std::endl;
            std::cout << "1: Continue" << std::endl;
            std::cout << "2: End" << std::endl;
            std::cin >> choice;

            if(choice == 1){
                testForReport(); // Wywołanie funkcji testującej raport
            }
            break;
        case 3:
            testSpecificScenario(); // Wywołanie funkcji testującej konkretny scenariusz tablicy
            break;
        default:
            std::cerr << "Invalid choice!" << std::endl;
            break;
    }
}

void MainMenu::testSpecificScenario() {
    int defaultSizeSS = 10000; // Domyślny rozmiar tablicy dla scenariusza specyficznego
    int size = defaultSizeSS; // Inicjalizacja rozmiaru tablicy

    // Generowanie losowej tablicy nieposortowanej
    DynamicArray<int> unsorted = generateRandomArray<int>(size, -1000, 1000);
    beginSortingForSpecificScenario(unsorted, "IntSpecificUnsorted", size);

    // Generowanie losowej tablicy posortowanej rosnąco
    DynamicArray<int> sortedAscending = generateRandomArray<int>(size, -1000, 1000);
    std::sort(sortedAscending.begin(), sortedAscending.end());
    beginSortingForSpecificScenario(sortedAscending, "IntSpecificSortedAscending", size);

    // Generowanie losowej tablicy posortowanej malejąco
    DynamicArray<int> sortedDescending = generateRandomArray<int>(size, -1000, 1000);
    std::reverse(sortedDescending.begin(), sortedDescending.end());
    beginSortingForSpecificScenario(sortedDescending, "IntSpecificSortedDescending", size);

    // Generowanie losowej tablicy częściowo posortowanej (jedna trzecia)
    DynamicArray<int> sortedPartiallyOneThird = generateRandomArray<int>(size, -1000, 1000);
    std::sort(sortedPartiallyOneThird.begin(), sortedPartiallyOneThird.begin() + size/3);
    beginSortingForSpecificScenario(sortedPartiallyOneThird, "IntSpecificSortedPartiallyOneThird", size);

    // Generowanie losowej tablicy częściowo posortowanej (dwie trzecie)
    DynamicArray<int> sortedPartiallyTwoThirds = generateRandomArray<int>(size, -1000, 1000);
    std::sort(sortedPartiallyTwoThirds.begin(), sortedPartiallyTwoThirds.begin() + (2 * size / 3));
    beginSortingForSpecificScenario(sortedPartiallyTwoThirds, "IntSpecificSortedPartiallyTwoThirds", size);
}



template<typename T>
void MainMenu::beginSortingForSpecificScenario(const DynamicArray<T>& initialArray, const std::string& type, int size) {
    int measuringCycles = 10;
    for(int i = 0 ; i < measuringCycles ; i++){
        // Utworzenie kopii początkowej tablicy
        DynamicArray<T> copyArray = initialArray;
        // Pomiar czasu sortowania dla sortowania przez wstawianie
        Sorter<T> sorter;
        std::chrono::high_resolution_clock::time_point startInsertion = std::chrono::high_resolution_clock::now();
        sorter.sortArray(copyArray, "InsertionSort");
        std::chrono::high_resolution_clock::time_point endInsertion = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsedInsertion = endInsertion - startInsertion;
        // Pomiar i zapis czasu sortowania
        measureAndSaveSortingTime(size, type, "InsertionSort", elapsedInsertion);
    }

    for(int i = 0 ; i < measuringCycles ; i++){
        // Utworzenie kopii początkowej tablicy
        DynamicArray<T> copyArray = initialArray;
        // Pomiar czasu sortowania dla sortowania przez wstawianie
        Sorter<T> sorter;
        std::chrono::high_resolution_clock::time_point startInsertion = std::chrono::high_resolution_clock::now();
        sorter.sortArray(copyArray, "BinaryInsertionSort");
        std::chrono::high_resolution_clock::time_point endInsertion = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsedInsertion = endInsertion - startInsertion;
        // Pomiar i zapis czasu sortowania
        measureAndSaveSortingTime(size, type, "BinaryInsertionSort", elapsedInsertion);
    }

    for(int i = 0 ; i < measuringCycles ; i++){
        // Utworzenie kopii początkowej tablicy
        DynamicArray<T> copyArray = initialArray;
        // Pomiar czasu sortowania dla sortowania przez wstawianie
        Sorter<T> sorter;
        std::chrono::high_resolution_clock::time_point startInsertion = std::chrono::high_resolution_clock::now();
        sorter.sortArray(copyArray, "HeapSort");
        std::chrono::high_resolution_clock::time_point endInsertion = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsedInsertion = endInsertion - startInsertion;
        // Pomiar i zapis czasu sortowania
        measureAndSaveSortingTime(size, type, "HeapSort", elapsedInsertion);
    }

    for(int i = 0 ; i < measuringCycles ; i++){
        // Utworzenie kopii początkowej tablicy
        DynamicArray<T> copyArray = initialArray;
        // Pomiar czasu sortowania dla sortowania przez wstawianie
        Sorter<T> sorter;
        std::chrono::high_resolution_clock::time_point startInsertion = std::chrono::high_resolution_clock::now();
        sorter.sortArray(copyArray, "QuickSort");
        std::chrono::high_resolution_clock::time_point endInsertion = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsedInsertion = endInsertion - startInsertion;
        // Pomiar i zapis czasu sortowania
        measureAndSaveSortingTime(size, type, "QuickSort", elapsedInsertion);
    }
}



void MainMenu::testCorrectness() {
    std::cout << "Choose:" << std::endl;
    std::cout << "1. Form File" << std::endl;
    std::cout << "2. Generate your self" << std::endl;
    choice = getChoice();

    switch (choice) {
        case 1:{
            testCorrectnessFile();
            break;
        }
        case 2:{
            testCorrectnessGenerateYourSelf();
            break;
        }
        default:
            std::cerr << "Invalid choice!" << std::endl;
            break;
    }
}


void MainMenu::testCorrectnessFile() {
    std::cout << "Choose array type:" << std::endl;
    std::cout << "1. int" << std::endl;
    std::cout << "2. float" << std::endl;
    std::cout << "3. char" << std::endl;
    choice = getChoice();

    std::string filename = chooseFileName();
    switch (choice) {
        case 1:{
            intArray = loadArrayFromFile<int>(filename); // Load array from file
            beginSortingCorectness(intArray);
            intArray.display();
            break;
        }
        case 2:{
            floatArray = loadArrayFromFile<float>(filename); // Load array from file
            beginSortingCorectness(floatArray);
            break;
        }
        case 3:{
            charArray = loadArrayFromFile<char>(filename); // Load array from file
            beginSortingCorectness(charArray);
            break;
        }
        default:
            std::cerr << "Invalid choice!" << std::endl;
            break;
    }

}


void MainMenu::testCorrectnessGenerateYourSelf() {
    std::cout << "Choose array type:" << std::endl;
    std::cout << "1. int" << std::endl;
    std::cout << "2. float" << std::endl;
    std::cout << "3. char" << std::endl;
    choice = getChoice();

    std::cout << "Choose array size:";
    int generateArraySize;
    std::cin >> generateArraySize;
    switch (choice) {
        case 1:{
            intArray = generateRandomArray<int>(generateArraySize, -1000, 1000);
            beginSortingCorectness(intArray);
            intArray.display();
            break;
        }
        case 2:{
            floatArray = generateRandomArray<float>(generateArraySize, -1000, 1000);
            beginSortingCorectness(floatArray);
            break;
        }
        case 3:{
            charArray = generateRandomArray<char>(generateArraySize, -1000, 1000);
            beginSortingCorectness(charArray);
            break;
        }
        default:
            std::cerr << "Invalid choice!" << std::endl;
            break;
    }

}

template<typename T>
DynamicArray<T> MainMenu::generateRandomArray(int size, int min, int max) {
    DynamicArray<T> arr(size);
    arr.fillRandom(min, max); // Wypełnienie tablicy losowymi liczbami z zakresu
    return arr;
}

template<typename T>
DynamicArray<T> MainMenu::loadArrayFromFile(const std::string& filename) {
    DynamicArray<T> arr(0);
    arr.readFromFile(filename); // Wczytanie tablicy z pliku
    return arr;
}

int MainMenu::getChoice() {
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    std::cout << "\n=------------=\n";
    return choice;
}

std::string MainMenu::chooseFileName(){
    std::string filename;
    std::cout << "Enter file name: ";
    std::cin >> filename;

    std::cout << "\n=------------=\n";
    return filename;
}

template<typename T>
void MainMenu::beginSortingCorectness(const DynamicArray<T>& initialArray){
    // Utworzenie kopii początkowej tablicy
    DynamicArray<T> copyArray = initialArray;

    // Prośba użytkownika o wybór algorytmu sortowania
    do {
        std::cout << "Choose sorting algo:" << std::endl;
        std::cout << "1: InsertionSort" << std::endl;
        std::cout << "2: BinaryInsertionSort" << std::endl;
        std::cout << "3: HeapSort" << std::endl;
        std::cout << "4: QuickSort" << std::endl;
        choice = getChoice();

        // Sortowanie kopii tablicy przy użyciu wybranego algorytmu
        copyArray.display();
        Sorter<T> sorter;
        switch (choice) {
            case 1:
                sorter.sortArray(copyArray, "InsertionSort");
                break;
            case 2:
                sorter.sortArray(copyArray, "BinaryInsertionSort");
                break;
            case 3:
                sorter.sortArray(copyArray, "HeapSort");
                break;
            case 4:
                sorter.sortArray(copyArray, "QuickSort");
                break;
            default:
                std::cerr << "Invalid choice!" << std::endl;
                continue; // Przejdź do kolejnej iteracji pętli
        }

        // Wyświetlenie posortowanej kopii tablicy
        copyArray.display();

        // Zapytanie czy użytkownik chce wypróbować inny algorytm sortowania
        std::cout << "Use a different algorithm?" << std::endl;
        std::cout << "1: Yes" << std::endl;
        std::cout << "0: No" << std::endl;
        getChoice();
        copyArray = initialArray;
    } while (choice == 1);
}

template<typename T>
void MainMenu::sortingCheck(const DynamicArray<T>& initialArray) {
    DynamicArray<T> copyArray = initialArray;

    Sorter<T> sorter;

    sorter.sortArray(copyArray, "InsertionSort");
    if (std::is_sorted(copyArray.begin(), copyArray.end())) {
        std::cout << "The array is sorted." << std::endl;
    } else {
        std::cout << "The array is not sorted." << std::endl;
    }

    sorter.sortArray(copyArray, "BinaryInsertionSort");
    if (std::is_sorted(copyArray.begin(), copyArray.end())) {
        std::cout << "The array is sorted." << std::endl;
    } else {
        std::cout << "The array is not sorted." << std::endl;
    }

    copyArray = initialArray;
    sorter.sortArray(copyArray, "HeapSort");
    if (std::is_sorted(copyArray.begin(), copyArray.end())) {
        std::cout << "The array is sorted." << std::endl;
    } else {
        std::cout << "The array is not sorted." << std::endl;
    }

    copyArray = initialArray;
    sorter.sortArray(copyArray, "QuickSort");
    if (std::is_sorted(copyArray.begin(), copyArray.end())) {
        std::cout << "The array is sorted." << std::endl;
    } else {
        std::cout << "The array is not sorted." << std::endl;
    }
}


void MainMenu::testForReport() {
    int defaultSize = 10000;
    int defaultSizeInsertion = 1000;
    int size = defaultSize;
    int sizeInsertion = defaultSizeInsertion;
    int measuringCycles = 80;
    int measuringCyclesInsertion = 30;
    int sizeIncreaseCycles = 7;
    //Sprawdzenie Sortowania
    intArray = generateRandomArray<int>(size, -1000, 1000);
    sortingCheck(intArray);
    floatArray = generateRandomArray<float>(size, -1000, 1000);
    sortingCheck(floatArray);
    charArray = generateRandomArray<char>(size, -128, 127);
    sortingCheck(charArray);

    // Testowanie wydajności sortowania dla różnych typów danych i różnych rozmiarów tablicy
    for(int i = 0; i < sizeIncreaseCycles; i++){
        for(int j = 0; j < measuringCyclesInsertion; j++){
            intArray = generateRandomArray<int>(sizeInsertion, -1000, 1000);
            beginSortingForReportInsertion(intArray, "Int", sizeInsertion);
        }

        for(int j = 0; j < measuringCycles; j++){
            intArray = generateRandomArray<int>(size, -1000, 1000);
            beginSortingForReport(intArray, "Int", size);
        }

        std::cout << "Sorting Int END" << std::endl;
        size*=2;
        sizeInsertion*=2;
    }

    size = defaultSize;
    sizeInsertion = defaultSizeInsertion;
    for(int i = 0; i < sizeIncreaseCycles; i++){
        for(int j = 0; j < measuringCyclesInsertion; j++){
            floatArray = generateRandomArray<float>(sizeInsertion, -1000, 1000);
            beginSortingForReportInsertion(floatArray, "Float", sizeInsertion);
        }

        for(int j = 0; j < measuringCycles; j++){
            floatArray = generateRandomArray<float>(size, -1000, 1000);
            beginSortingForReport(floatArray, "Float", size);
        }

        std::cout << "Sorting Float END" << std::endl;
        size*=2;
        sizeInsertion*=2;
    }

    size = defaultSize;
    sizeInsertion = defaultSizeInsertion;
    for(int i = 0; i < sizeIncreaseCycles; i++){
        for(int j = 0; j < measuringCyclesInsertion; j++){
            charArray = generateRandomArray<char>(sizeInsertion, -128, 127);
            beginSortingForReportInsertion(charArray, "Char", sizeInsertion);
        }

        for(int j = 0; j < measuringCycles; j++){
            charArray = generateRandomArray<char>(size, -128, 127);
            beginSortingForReport(charArray, "Char", size);
        }

        std::cout << "Sorting Char END" << std::endl;
        size*=2;
        sizeInsertion*=2;
    }

}

template<typename T>
void MainMenu::beginSortingForReportInsertion(const DynamicArray<T>& initialArray, const std::string& type, int size) {
    // Utworzenie kopii początkowej tablicy
    DynamicArray<T> copyArray = initialArray;

    // Utworzenie kopii początkowej tablicy
    Sorter<T> sorter;
    std::chrono::high_resolution_clock::time_point startInsertion = std::chrono::high_resolution_clock::now();
    sorter.sortArray(copyArray, "InsertionSort");
    std::chrono::high_resolution_clock::time_point endInsertion = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedInsertion = endInsertion - startInsertion;
    measureAndSaveSortingTime(size, type, "InsertionSort", elapsedInsertion);

    // Zresetowanie kopii tablicy
    copyArray = initialArray;

    // Pomiar czasu sortowania dla BinaryInsertionSort
    std::chrono::high_resolution_clock::time_point startBinaryInsertion = std::chrono::high_resolution_clock::now();
    sorter.sortArray(copyArray, "BinaryInsertionSort");
    std::chrono::high_resolution_clock::time_point endBinaryInsertion = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedBinaryInsertion = endBinaryInsertion - startBinaryInsertion;
    measureAndSaveSortingTime(size, type, "BinaryInsertionSort", elapsedBinaryInsertion);
}

template<typename T>
void MainMenu::beginSortingForReport(const DynamicArray<T>& initialArray, const std::string& type, int size) {
    // Utworzenie kopii początkowej tablicy
    DynamicArray<T> copyArray = initialArray;
    Sorter<T> sorter;

    // Pomiar czasu sortowania dla HeapSort
    std::chrono::high_resolution_clock::time_point startHeap = std::chrono::high_resolution_clock::now();
    sorter.sortArray(copyArray, "HeapSort");
    std::chrono::high_resolution_clock::time_point endHeap = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedHeap = endHeap - startHeap;
    measureAndSaveSortingTime(size, type, "HeapSort", elapsedHeap);

    // Zresetowanie kopii tablicy
    copyArray = initialArray;

    // Pomiar czasu sortowania dla QuickSort
    std::chrono::high_resolution_clock::time_point startQuick = std::chrono::high_resolution_clock::now();
    sorter.sortArray(copyArray, "QuickSort");
    std::chrono::high_resolution_clock::time_point endQuick = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedQuick = endQuick - startQuick;
    measureAndSaveSortingTime(size, type,"QuickSort", elapsedQuick);
}

void MainMenu::measureAndSaveSortingTime(int size, const std::string& type, const std::string& algorithmName, std::chrono::duration<double> elapsedTime) {
    std::ofstream file(type + "_"+ algorithmName + "Times.csv", std::ios_base::app);
    if (file.is_open()) { // Sprawdzenie czy plik został otwarty poprawnie
        file << elapsedTime.count()<< ";" << size << std::endl; // Zapis czasu sortowania oraz rozmiaru tablicy
        file.close(); // Zamknięcie pliku
    } else {
        std::cerr << "Unable to open file for writing." << std::endl; // Komunikat o niepowodzeniu otwarcia pliku
    }
}
