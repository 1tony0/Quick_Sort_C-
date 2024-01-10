#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

// This function swaps two numbers
void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Now we will take the last element as pivot and place it at the right position
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);

    return i + 1;
}

// Main function that implements the quicksort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);



        //TAKE THIS OUT OF THE CODE WHEN YOU ARE CHECKING FOR EFFECIENCY
        // Print the array after each sorting step
        cout << "Array being sorted: ";
        for (int i = low; i <= high; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;


        //TAKE THIS OUT OF THE CODE WHEN YOU ARE CHECKING FOR EFFECIENCY
        // Pause until user input
        cin.ignore(); // Ignore any previous newline character
        cout << "Press enter to continue: ";
        cin.get();    // Wait for user input

    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "Please enter the size of the array: " << endl;
    int size;
    cin >> size;
    int arr[size];

    // Asking if user wants to manually input the array or make it random
    cout << "Would you like to manually input the array? [y or n]" << endl;
    string manual;
    cin >> manual;
    if (manual == "y") {
        cout << "Please enter the elements of the array: " << endl;
        for (int i = 0; i < size; i++)
            cin >> arr[i];
    } else {
        srand(time(NULL));
        for (int i = 0; i < size; i++) {
            arr[i] = rand() % 1000000000;
            while (cin.fail()) {
                cin.clear();
                cin.ignore(256, '\n');
                cout << "Please enter a number: " << endl;
                cin >> arr[i];
                cin.clear();
                cin.ignore(256, '\n');
                continue;
            }
        }
    }

    int n = sizeof(arr) / sizeof(arr[0]);

    // Tracking how much time it takes
    auto start = chrono::high_resolution_clock::now();
    quickSort(arr, 0, n - 1);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);

    cout << "Sorted array: " << endl;
    printArray(arr, n);
    cout << "Time taken: " << duration.count() << " nanoseconds" << endl;

    cout << "Would you like to go again? [y or n]" << endl;
    string again;
    cin >> again;
    if (again == "y") {
        main();
    } else {
        cout << "Thank you for using this program" << endl;
    }

    return 0;
}
