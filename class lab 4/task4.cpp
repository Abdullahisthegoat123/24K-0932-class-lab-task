#include <iostream>
#include <algorithm>
using namespace std;

int interpolationSearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    while (low <= high && x >= arr[low] && x <= arr[high]) {
        if (low == high) {
            if (arr[low] == x) return low;
            return -1;
        }

        int pos = low + static_cast<int>(((double)(high - low) / (arr[high] - arr[low])) * (x - arr[low]));
        if (arr[pos] == x)
            return pos;
        if (arr[pos] < x)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}

int main() {
    int n, x;
    cout << "Enter number of elements: ";
    cin >> n;
    int* arr = new int[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    cout << "Enter element to search: ";
    cin >> x;

    int index = interpolationSearch(arr, n, x);
    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found." << endl;
    
    delete[] arr;
}