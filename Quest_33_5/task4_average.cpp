#include <iostream>
#include <typeinfo>
#include <limits>

using namespace std;

template<typename T>
void inputArray(T array[], int size) {
    cout << "Enter " << size << " numbers:\n";

    for (int i = 0; i < size; ++i) {
        cout << i + 1 << ": ";
        cin >> array[i];
    }
}

template<typename T>
double calculateAverage(T array[], int size) {
    if (size <= 0) {
        throw invalid_argument("Size must be > 0");
    }

    T sum = T();

    for (int i = 0; i < size; ++i) {
        sum += array[i];
    }

    return static_cast<double>(sum) / size;
}

template<typename T>
void printArray(T array[], int size) {
    cout << "Array: ";
    for (int i = 0; i < size; ++i) {
        cout << array[i];
        if (i < size - 1) cout << ", ";
    }
    cout << "\n";
}

template<typename T>
void testAverageCalculation() {
    const int SIZE = 5;
    T array[SIZE];

    inputArray(array, SIZE);
    printArray(array, SIZE);

    try {
        double average = calculateAverage(array, SIZE);
        cout << "Average: " << average << "\n";
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << "\n";
    }
}

void task4() {
    cout << "Average Calculator\n";

    int choice;
    do {
        cout << "\n1. int\n2. double\n3. float\n4. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            testAverageCalculation<int>();
            break;
        case 2:
            testAverageCalculation<double>();
            break;
        case 3:
            testAverageCalculation<float>();
            break;
        case 4:
            break;
        default:
            cout << "Invalid\n";
        }

    } while (choice != 4);
}