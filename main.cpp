#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

void fillArray(short arr[], int length) {
    /*
     * Fills array with pseudo-random nums in range [-99, 99]
     * :param arr: int [] - array to fill
     * :param length: int - length of array
     */
    std::srand(time(NULL));
    for (int i = 0; i < length; i++) {
        arr[i] = -99 + (std::rand() % 199);
    }
}


int main() {

    std::cout.setf(std::ios::fixed);
    std::cout << "Enter 'h' to get list of commands\n";

    // Array initialization
    const short N = 100;
    short array[N];
    fillArray(array, N);

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
                break;
            }

            // Display array elements
            case '9': {
                for (short element : array) {
                    std::cout << element << ' ';
                }
                std::cout << std::endl;
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
