#include <iostream>
#include <string>
using namespace std;

class runner {
    string name;
    int time;
public:
    runner(int t = 0, string n = "") : time(t), name(n) {}
    int getTime() const { return time; }
    string getName() const { return name; }
};

void merge(runner arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    runner L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].getTime() <= R[j].getTime()) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(runner arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    const int N = 10;
    runner arr[N];
    for (int i = 0; i < N; i++) {
        string name;
        int time;
        cout << "Enter name and finish time of runner " << i + 1 << ": ";
        cin >> name >> time;
        arr[i] = runner(time, name);
    }
    mergeSort(arr, 0, N - 1);
    cout << "\nRunners sorted by finish time:\n";
    for (int i = 0; i < N; i++)
        cout << arr[i].getName() << " " << arr[i].getTime() << endl;
    return 0;
}
