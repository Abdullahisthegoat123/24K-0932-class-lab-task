#include <iostream>
using namespace std;

int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx) mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp) {
    int* output = new int[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        int idx = (arr[i] / exp) % 10;
        output[count[idx] - 1] = arr[i];
        count[idx]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    delete[] output;
}

void radixSort(int arr[], int n) {
    int maxVal = getMax(arr, n);
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
        cout << "\nAfter sorting by digit place " << exp << ":\n";
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << endl;
    }
}

int main() {
    int a[20] = {
        54321, 12345, 98765, 67890, 13579, 24680, 11111, 22222, 33333, 44444,
        55555, 66666, 77777, 88888, 99999, 11223, 22334, 33445, 44556, 55667
    };

    int n = 20;

    cout << "Before sorting:\n";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

    radixSort(a, n);

    cout << "\nAfter complete sorting:\n";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

    return 0;
}
