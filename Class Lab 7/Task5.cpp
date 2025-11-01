#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int cmp;

int median3(int a[], int l, int r) {
    int m = (l + r) / 2;
    if (a[l] > a[m]) swap(a[l], a[m]);
    if (a[m] > a[r]) swap(a[m], a[r]);
    if (a[l] > a[m]) swap(a[l], a[m]);
    return m;
}

int partition(int a[], int l, int r, int pivot) {
    swap(a[pivot], a[r]);
    int p = a[r];
    int i = l - 1;
    for (int j = l; j < r; j++) {
        cmp++;
        if (a[j] < p) swap(a[++i], a[j]);
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}

void quicksort(int a[], int l, int r, int type) {
    if (l >= r) return;
    int pivot;
    if (type == 1) pivot = l;
    else if (type == 2) pivot = l + rand() % (r - l + 1);
    else if (type == 3) pivot = (l + r) / 2;
    else pivot = median3(a, l, r);
    int pi = partition(a, l, r, pivot);
    quicksort(a, l, pi - 1, type);
    quicksort(a, pi + 1, r, type);
}

int main() {
    srand(time(0));
    int base[10] = {10, 7, 8, 9, 1, 5, 3, 6, 2, 4};
    int a[10];
    for (int t = 1; t <= 4; t++) {
        for (int i = 0; i < 10; i++) a[i] = base[i];
        cmp = 0;
        quicksort(a, 0, 9, t);
        cout << "Pivot type " << t << " comparisons: " << cmp << endl;
    }
    return 0;
}
