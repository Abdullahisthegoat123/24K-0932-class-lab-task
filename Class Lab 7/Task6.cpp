#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    string name;
    int id;
    int salary;
};

void merge(Employee arr[], int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;
    Employee* left = new Employee[n1];
    Employee* right = new Employee[n2];

    for (int i = 0; i < n1; i++) left[i] = arr[l + i];
    for (int j = 0; j < n2; j++) right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (left[i].salary >= right[j].salary)
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }
    while (i < n1) arr[k++] = left[i++];
    while (j < n2) arr[k++] = right[j++];

    delete[] left;
    delete[] right;
}

void mergeSort(Employee arr[], int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int main() {
    Employee e[12] = {
        {"Abdullah",1,95000},{"kabeer",2,75000},{"ali",3,65000},
        {"muhammed",4,88000},{"zaid",5,80000},{"arif",6,55000},
        {"bilal",7,72000},{"ahzam",8,84000},{"Fahad",9,60000},
        {"Ahmed",10,50000},{"muzammil",11,70000},{"usman",12,77000}
    };

    mergeSort(e, 0, 11);

    cout << "Top 3 highest-paid employees:\n";
    for (int i = 0; i < 3; i++) {
        cout << e[i].name << " " << e[i].id << " " << e[i].salary << endl;
    }

    return 0;
}
