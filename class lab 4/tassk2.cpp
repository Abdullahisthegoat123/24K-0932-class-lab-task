#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void printArray(const vector<int>& arr) {
    for (int num : arr) cout << num << " ";
    cout << endl;
}

int bubbleSort(vector<int> arr) {
    int comparisons = 0;
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            comparisons++;
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }
    cout << "Bubble Sorted: ";
    printArray(arr);
    return comparisons;
}

int insertionSort(vector<int> arr) {
    int comparisons = 0;
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0) {
            comparisons++;
            if (arr[j] > key)
                arr[j+1] = arr[j];
            else
                break;
            j--;
        }
        arr[j+1] = key;
    }
    cout << "Insertion Sorted: ";
    printArray(arr);
    return comparisons;
}

int selectionSort(vector<int> arr) {
    int comparisons = 0;
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
    cout << "Selection Sorted: ";
    printArray(arr);
    return comparisons;
}

int shellSort(vector<int> arr) {
    int comparisons = 0;
    int n = arr.size();
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i], j;
            for (j = i; j >= gap; j -= gap) {
                comparisons++;
                if (arr[j-gap] > temp)
                    arr[j] = arr[j-gap];
                else
                    break;
            }
            arr[j] = temp;
        }
    }
    cout << "Shell Sorted: ";
    printArray(arr);
    return comparisons;
}

vector<int> generateRandomArray(int size) {
    vector<int> arr(size);
    for (int& num : arr)
        num = rand() % 100 + 1;
    return arr;
}

int main() {
    srand(time(0));
    int sizes[] = {20, 100};
    for (int sz : sizes) {
        cout << "\n--- Sorting " << sz << " random integers ---\n";
        vector<int> arr = generateRandomArray(sz);
        cout << "Original Array: ";
        printArray(arr);

        cout << "Comparisons:\n";
        cout << "Bubble Sort: " << bubbleSort(arr) << endl;
        cout << "Insertion Sort: " << insertionSort(arr) << endl;
        cout << "Selection Sort: " << selectionSort(arr) << endl;
        cout << "Shell Sort: " << shellSort(arr) << endl;
    }
    return 0;
}