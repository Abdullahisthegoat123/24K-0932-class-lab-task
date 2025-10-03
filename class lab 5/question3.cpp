#include <iostream>
using namespace std;

int N = 7;

void solution(int sol[7][7]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << sol[i][j] << " ";
        cout << endl;
    }
}

bool isSafe(int maze[7][7], int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

bool solveMaze(int maze[7][7], int x, int y, int sol[7][7]) {
    if (x == N - 1 && y == N - 1) {
        sol[x][y] = 1;
        return true;
    }
    if (isSafe(maze, x, y) && sol[x][y] == 0) {
        sol[x][y] = 1;
        if (solveMaze(maze, x, y + 1, sol))
            return true;
        if (solveMaze(maze, x + 1, y, sol))
            return true;
        if (solveMaze(maze, x, y - 1, sol))
            return true;
        if (solveMaze(maze, x - 1, y, sol))
            return true;
        sol[x][y] = 0;
        return false;
    }
    return false;
}

int main() {
    int maze[7][7] = {
        {1,0,1,1,1,0,1},
        {1,1,1,0,1,1,1},
        {0,1,0,1,0,1,0},
        {1,1,1,1,1,0,1},
        {0,0,0,0,1,1,1},
        {1,1,1,0,1,0,1},
        {0,0,1,1,1,1,1}
    };
    int sol[7][7] = { {0} };
    if (solveMaze(maze, 0, 0, sol)){
        solution(sol);
    }
    else{
        cout << "No path found!" << endl;
    }
    return 0;
}
