#include <iostream>
#include <string>
using namespace std;

class Order {
public:
    int orderID;
    string customerName;
    int totalPrice;
};

int partition(Order a[], int l, int r) {
    int p = a[r].totalPrice;
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (a[j].totalPrice < p) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}

void quicksort(Order a[], int l, int r) {
    if (l < r) {
        int pi = partition(a, l, r);
        quicksort(a, l, pi - 1);
        quicksort(a, pi + 1, r);
    }
}

int main() {
    Order o[6] = {
        {101, "Abdullah", 3500},
        {102, "Muhammed", 2200},
        {103, "Ahmed", 4100},
        {104, "Saad", 1800},
        {105, "Usman", 2900},
        {106, "Zaid", 3700}
    };

    quicksort(o, 0, 5);

    cout << "Orders sorted by total price (ascending):\n";
    for (int i = 0; i < 6; i++) {
        cout << o[i].orderID << " " << o[i].customerName << " " << o[i].totalPrice << endl;
    }

    return 0;
}
