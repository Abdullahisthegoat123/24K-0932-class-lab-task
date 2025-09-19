#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid; 
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; 
}

int main() {
    int n, value;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    cout << "Sorted array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    cout << "Enter value to search: ";
    cin >> value;

    int result = binarySearch(arr, value);
    if (result != -1)
        cout << "Value found at index " << result << " (0 sai index shurow hota hai)." << endl;
    else
        cout << "Value not found in the array." << endl;

    return 0;
}