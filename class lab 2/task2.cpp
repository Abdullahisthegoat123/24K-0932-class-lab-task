#include <iostream>
using namespace std;

class Matrix {  
public:
    int rowCount, colCount;
    int** elements;

    Matrix(int row, int col, int initialValue = 0) : rowCount(row), colCount(col) {
        elements = new int*[rowCount];
        for (int i = 0; i < rowCount; ++i) {
            elements[i] = new int[colCount];
            for (int j = 0; j < colCount; ++j)
                elements[i][j] = initialValue;
        }
    }

    ~Matrix() {
        for (int i = 0; i < rowCount; ++i)
            delete[] elements[i];
        delete[] elements;
    }

    void resize(int newRowCount, int newColCount, int initialValue = 0) {
        int** newElements = new int*[newRowCount];
        for (int i = 0; i < newRowCount; ++i) {
            newElements[i] = new int[newColCount];
            for (int j = 0; j < newColCount; ++j) {
                newElements[i][j] = initialValue;
            }
        }
        for (int i = 0; i < rowCount; ++i)
            delete[] elements[i];
        delete[] elements;
        elements = newElements;
        rowCount = newRowCount;
        colCount = newColCount;
    }

    void transpose() {
        int** transposedMatrix = new int*[colCount];
        for (int i = 0; i < colCount; ++i) {
            transposedMatrix[i] = new int[rowCount];
            for (int j = 0; j < rowCount; ++j)
                transposedMatrix[i][j] = elements[j][i];
        }
        for (int i = 0; i < rowCount; ++i)
            delete[] elements[i];
        delete[] elements;
        elements = transposedMatrix;
        swap(rowCount, colCount);
    }

    void addToOddIndices(int value) {
    for (int i = 0; i < rowCount; ++i) {
        for (int j = 0; j < colCount; ++j) {
            if (i % 2 == 1 || j % 2 == 1) 
                elements[i][j] += value;
        }
    }
}

    void print() const {
        for (int i = 0; i < rowCount; ++i) {
            for (int j = 0; j < colCount; ++j)
                cout << elements[i][j] << " ";
            cout << endl;
        }
    }
};

int main() {
    cout << "Creating a 3x3 matrix with initial value 2:" << endl;
    Matrix matrix(3, 3, 2);
    matrix.print();

    cout << "\nResizing to 4x4 and filling with value 7:" << endl;
    matrix.resize(4, 4, 7);
    matrix.print();

    cout << "\nTransposing the matrix:" << endl;
    matrix.transpose();
    matrix.print();

    cout << "\nAdding 2 to elements at odd indices:" << endl;
    matrix.addToOddIndices(2);
    matrix.print();

    return 0;
}
