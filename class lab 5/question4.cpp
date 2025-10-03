#include <iostream>
using namespace std;

int totalSolutions = 0;
int firstSolution[15][15];
bool foundFirst = false;

bool isSafe(int board[15][15], int row, int col, int N) {
    for (int i = 0; i < row; i++)
        if (board[i][col]) return false;
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;
    for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++)
        if (board[i][j]) return false;
    return true;
}

void printBoard(int board[15][15], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j]) cout << "Q ";
            else cout << ". ";
        }
        cout << endl;
    }
}

void copyBoard(int src[15][15], int dest[15][15], int N) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            dest[i][j] = src[i][j];
}

void solve(int board[15][15], int row, int N) {
    if (row == N) {
        totalSolutions++;
        if (!foundFirst) {
            copyBoard(board, firstSolution, N);
            foundFirst = true;
        }
        return;
    }
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            board[row][col] = 1;
            solve(board, row + 1, N);
            board[row][col] = 0;
        }
    }
}

int main() {
    int N;
    cout << "Enter the value of N (size of the chessboard): ";
    cin >> N;
    int board[15][15] = {0};
    totalSolutions = 0;
    foundFirst = false;
    solve(board, 0, N);
    if (foundFirst) {
        cout << "\nOne valid board configuration:\n";
        printBoard(firstSolution, N);
    } else {
        cout << "No solution exists for N = " << N << endl;
    }
    cout << "\nTotal number of distinct solutions for N = " << N << " is: " << totalSolutions << endl;
    if (N != 4) {
        N = 4;
        for (int i = 0; i < 15; i++)
            for (int j = 0; j < 15; j++)
                board[i][j] = 0;
        totalSolutions = 0;
        foundFirst = false;
        solve(board, 0, N);
        cout << "\nDemonstrating with N = 4:\n";
        printBoard(firstSolution, N);
        cout << "\nTotal number of distinct solutions for N = 4 is: " << totalSolutions << endl;
    }
    return 0;
}