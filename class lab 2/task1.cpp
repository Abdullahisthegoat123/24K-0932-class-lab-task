#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* elements;
    int count;

public:
    DynamicArray() {
        elements = nullptr;
        count = 0;
    }

    void push_back(int value) {
        int* tempArray = new int[count + 1];
        for (int j = 0; j < count; ++j) {
            tempArray[j] = elements[j];
        }
        tempArray[count] = value;
        delete[] elements;
        elements = tempArray;
        count++;
    }

    void print() const {
        for (int k = 0; k < count; ++k) {
            cout << elements[k] << " ";
        }
        cout << endl;
    }

    ~DynamicArray() {
        delete[] elements;
    }
};

int main() {
    DynamicArray arr;
    
    cout << "Adding elements to dynamic array:" << endl;
    
    arr.push_back(5);
    arr.push_back(8);
    arr.push_back(9);
    
    cout << "Array after adding : ";
    arr.print();
    arr.push_back(6);
    
    cout << "Array after adding 6: ";
    arr.print();
    
}