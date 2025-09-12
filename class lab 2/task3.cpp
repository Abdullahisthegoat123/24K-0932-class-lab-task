#include <iostream>
using namespace std;

class JaggedArray {
public:
int* rowLengths;
int rowCount;
int** arrayData;

    JaggedArray(int rows, int* sizes) : rowCount(rows) {
        rowLengths = new int[rowCount];
        arrayData = new int*[rowCount];
        for (int i = 0; i < rowCount; ++i) {
            rowLengths[i] = sizes[i];
            arrayData[i] = new int[rowLengths[i]];
            for (int j = 0; j < rowLengths[i]; ++j)
                arrayData[i][j] = 0; 
        }
    }

    
    void print() const {
        for (int i = 0; i < rowCount; ++i) {
            cout << "Row " << i << ": ";
            for (int j = 0; j < rowLengths[i]; ++j) {
                cout << arrayData[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    
    int rowSum(int rowIndex) const {
        int total = 0;
        for (int j = 0; j < rowLengths[rowIndex]; ++j)
        total += arrayData[rowIndex][j];
        return total;
    }
    
    void storeValue(int rowIndex, int colIndex, int value) {
        if (rowIndex >= 0 && rowIndex < rowCount && colIndex >= 0 && colIndex < rowLengths[rowIndex]) {
            arrayData[rowIndex][colIndex] = value;
        }
    }
    ~JaggedArray() {
        for (int i = 0; i < rowCount; ++i)
            delete[] arrayData[i];
        delete[] arrayData;
        delete[] rowLengths;
    }
};

int main() {
    int* rowSizes = new int[3]{3, 1, 4};
    JaggedArray jagged(3, rowSizes);
    
    cout << "Initial jagged array:" << endl;
    jagged.print();

    jagged.storeValue(0, 0, 16);
    jagged.storeValue(0, 1, 23);
    jagged.storeValue(1, 0, 84);
    jagged.storeValue(2, 2, 94);

    cout << "Updated jagged array:" << endl;
    jagged.print();

    int rowCount = sizeof(rowSizes) / sizeof(rowSizes[0]);
    for (int i = 0; i <= rowCount; i++)
        cout << "Sum of row " << i << " is: " << jagged.rowSum(i) << endl;

    delete[] rowSizes;
    return 0;
}
