#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void countingSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

int main() {
    srand(time(0));
    int scores[50];
    for (int i = 0; i < 50; i++)
        scores[i] = rand() % 101;

    cout << "Original Scores:\n";
    for (int i = 0; i < 50; i++)
        cout << scores[i] << " ";
    cout << "\n\n";

    radixSort(scores, 50);

    cout << "Scores with Ranks (Highest = Rank 1):\n";
    int rank = 1;
    for (int i = 49; i >= 0; i--)
        cout << "Rank " << rank++ << ": " << scores[i] << endl;

    return 0;
}
