#include <iostream>

template<typename T>
void input(T arr[], int size) {
    for (int i = 0; i < size; ++i)
        std::cin >> arr[i];
}

template<typename T>
double average(T arr[], int size) {
    double sum = 0;
    for (int i = 0; i < size; ++i)
        sum += arr[i];
    return sum / size;
}

void task4_average() {
    const int SIZE = 8;
    double arr[SIZE];

    std::cout << "¬ведите 8 чисел:\n";
    input(arr, SIZE);

    std::cout << "—реднее: " << average(arr, SIZE) << std::endl;
}