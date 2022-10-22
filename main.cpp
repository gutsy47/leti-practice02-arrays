#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <chrono>


void bubbleSort(int arr[], int length) {
    for (int i = length - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}


void shakerSort(int arr[], int length) {
    for (int i = length - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
        for (int j = i - 1; j > length - i; j--) {
            if (arr[j] < arr[j - 1]) {
                std::swap(arr[j], arr[j - 1]);
            }
        }
    }
}


void combSort(int arr[], int length) {
    int gap = length;

    while (gap != 1) {
        gap /= 1.247;
        if (gap < 1) {
            gap = 1;
        }

        for (int i = 0; i < length - gap; i++) {
            if (arr[i] > arr[i + gap]) {
                std::swap(arr[i], arr[i + gap]);
            }
        }
    }
}


void insertSort(int arr[], int length) {
    for (int i = 1; i < length; i++) {
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
            std::swap(arr[j - 1], arr[j]);
        }
    }
}


void quickSort(int arr[], int length) {

}


void printArray(int arr[], int length) {
    // Just print array
    for (int i = 0; i < length; i++) {
        std::cout << arr[i] << ' ';
    }
    putchar('\n');
}


void fillArray(int arr[], int length) {
    // Fill array with pseudo-random nums in range [-99, 99]
    std::srand(time(NULL));
    for (int i = 0; i < length; i++) {
        arr[i] = -99 + (std::rand() % 199);
    }
}


int main() {

    std::cout.setf(std::ios::fixed);
    std::cout << "Enter 'h' to get list of commands\n";

    // Array initialization
    const int N = 100;
    int array[N], unsortedArray[N];
    bool isArraySorted = false;
    fillArray(array, N);
    std::copy(std::begin(array), std::end(array), std::begin(unsortedArray));

    // Main loop
    while (true) {

        // Get command from user
        char userAction;
        std::cout << "<< Action: \n>> ";
        std::cin.sync();
        std::cin >> userAction;

        // Exit
        if (userAction == '0') {
            break;
        }

        switch (userAction) {

            // Refill the array
            case '1': {
                fillArray(array, N);
                std::cout << "Array refilled successfully\n";
                isArraySorted = false;
                break;
            }

            // Sort the array
            case '2': {
                auto start = std::chrono::steady_clock::now();
                combSort(array, N);
                auto end = std::chrono::steady_clock::now();
                auto elapsed_us = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
                std::cout << "Array sorted. Elapsed time: " << elapsed_us << " ns\n";
                isArraySorted = true;
                break;
            }
            // Найти максимальный и минимальный элемент массива. Подсчитайте время поиска этих элементов в отсортированном массиве и неотсортированном, используя библиотеку chrono.
            // Find max & min elements in sorted/unsorted array
            case '3': {
                // UnsortedError
                if (!isArraySorted) {
                    std::cout << "Array isn't sorted. Use command '2' to sort it\n";
                    break;
                }

                int min = 100, max = -100;

                // Min & max in unsorted array
                auto start = std::chrono::steady_clock::now();
                for (int i = 0; i < N; i++) {
                    if (unsortedArray[i] < min) {
                        min = unsortedArray[i];
                    }
                    else if (unsortedArray[i] > max) {
                        max = unsortedArray[i];
                    }
                }
                auto end = std::chrono::steady_clock::now();
                auto elapsed_us = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
                std::cout << "Elements in unsorted array found. Elapsed time: " << elapsed_us << " ns\n";
                std::cout << "min = " << min << "\nmax = " << max << std::endl;

                // Min & max in sorted array
                start = std::chrono::steady_clock::now();
                min = array[0];
                max = array[N-1];
                end = std::chrono::steady_clock::now();
                elapsed_us = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
                std::cout << "Elements in sorted array found. Elapsed time: " << elapsed_us << " ns\n";
                std::cout << "min = " << min << "\nmax = " << max << std::endl;


                break;
            }

            // Display array elements
            case '9': {
                std::cout << "Unsorted array:\n";
                printArray(unsortedArray, N);
                std::cout << "Sorted array:\n";
                printArray(array, N);
                break;
            }

            // Help
            case 'h': {
                std::cout << "Available commands:\n";
                std::cout << std::setw(32) << std::setfill('-') << '\n';
                std::cout << "h: Help\n";
                std::cout << std::setw(32) << std::setfill('-') << '\n';
                std::cout << "1: Refill the array with random numbers in range [-99, 99]\n";
                std::cout << "9: Display array elements\n";
                std::cout << std::setw(32) << std::setfill('-') << '\n';
                std::cout << "0: Exit\n";
                std::cout << std::setw(32) << std::setfill('-') << '\n';
                std::cout << std::setfill(' ');
                break;
            }

            // Unknown command error
            default: {
                std::cout << "RuntimeError: unknown command\n";
            }
        }
    }

    return 0;
}
