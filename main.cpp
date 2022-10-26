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

            // Find round(avg(max, min)) and print indexes of elements equals to it
            case '4': {
                // In sorted & in unsorted? wdim?
                break;
            }

            // Find amount of elements which less than user_input in sorted array
            case '5': {
                // UnsortedError
                if (!isArraySorted) {
                    std::cout << "Array isn't sorted. Use command '2' to sort it\n";
                    break;
                }

                // User input
                int userInput;
                std::cout << "<< Enter an integer:\n>> ";
                std::cin >> userInput;
                std::cin.sync();
                if (std::cin.fail()) {
                    std::cout << "TypeError: invalid literal for int with base 10.\n";
                    std::cin.clear();
                    break;
                }

                // Search & display
                int amount = 0;
                for (int i = 0; i < N; i++) {
                    amount += array[i] < userInput ? 1 : 0;
                }
                std::cout << "Elements less than " << userInput << ": " << amount << std::endl;
                break;
            }

            // Find amount of elements which greater than user_input in sorted array
            case '6': {
                // UnsortedError
                if (!isArraySorted) {
                    std::cout << "Array isn't sorted. Use command '2' to sort it\n";
                    break;
                }

                // User input
                int userInput;
                std::cout << "<< Enter an integer:\n>> ";
                std::cin >> userInput;
                std::cin.sync();
                if (std::cin.fail()) {
                    std::cout << "TypeError: invalid literal for int with base 10.\n";
                    std::cin.clear();
                    break;
                }

                // Search & display
                int amount = 0;
                for (int i = N-1; i >= 0; i--) {
                    amount += array[i] > userInput ? 1 : 0;
                }
                std::cout << "Elements greater than " << userInput << ": " << amount << std::endl;
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
                std::cout << "2: Sort the array\n";
                std::cout << "3: Find min and max elements. Compare search in sorted and unsorted arrays\n";
                std::cout << "4: Find round average of max & min and print indexes of elements equals to it\n";
                std::cout << "5: Find amount of elements which are less than user input in sorted array\n";
                std::cout << "6: Find amount of elements which are greater than user input in sorted array\n";
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
