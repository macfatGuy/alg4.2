#include <iostream>
#include <vector>

// Function to print a dynamic array with underscore for unused space
void print_dynamic_array(int* arr, int logical_size, int actual_size) {
    for (int i = 0; i < actual_size; ++i) {
        if (i < logical_size) {
            std::cout << arr[i] << (i == logical_size - 1 ? "" : " ");
        }
        else {
            std::cout << "_" << (i == actual_size - 1 ? "" : " ");
        }
    }
    std::cout << std::endl;
}

// Function to append a new element to the dynamic array
void append_to_dynamic_array(int*& arr, int& logical_size, int& actual_size, int newElement) {
    if (logical_size < actual_size) {
        arr[logical_size++] = newElement;
    }
    else {
        int newActualSize = actual_size * 2;
        int* newArr = new int[newActualSize];
        for (int i = 0; i < logical_size; ++i) {
            newArr[i] = arr[i];
        }
        newArr[logical_size++] = newElement;
        delete[] arr;
        arr = newArr;
        actual_size = newActualSize;
    }
}

int main() {
    int actual_size, logical_size, newElement;

    std::cout << "Введите фактический размер массива: ";
    std::cin >> actual_size;
    std::cout << "Введите логический размер массива: ";
    std::cin >> logical_size;

    if (logical_size > actual_size) {
        std::cout << "Ошибка! Логический размер массива не может превышать фактический!" << std::endl;
        return 1;
    }

    int* arr = new int[actual_size];

    for (int i = 0; i < logical_size; ++i) {
        std::cout << "Введите arr[" << i << "]: ";
        std::cin >> arr[i];
    }

    std::cout << "Динамический массив: ";
    print_dynamic_array(arr, logical_size, actual_size);

    std::cout << "Введите элемент для добавления (0 для завершения): ";
    std::cin >> newElement;

    while (newElement != 0) {
        append_to_dynamic_array(arr, logical_size, actual_size, newElement);
        std::cout << "Динамический массив: ";
        print_dynamic_array(arr, logical_size, actual_size);
        std::cout << "Введите элемент для добавления (0 для завершения): ";
        std::cin >> newElement;
    }

    std::cout << "Спасибо! Ваш массив: ";
    print_dynamic_array(arr, logical_size, actual_size);
    delete[] arr;
    return 0;
}

