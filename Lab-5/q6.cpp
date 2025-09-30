#include <iostream>
using namespace std;

void printSolution(int n, int sol[10][10]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << sol[i][j] << " ";
        cout << endl;
    }
}

bool isSafe(int n, int maze[10][10], int x, int y, int sol[10][10]) {
    return (x >= 0 && x < n && y >= 0 && y < n &&
            maze[x][y] == 1 && sol[x][y] == 0);
}

bool solveMazeUtil(int n, int maze[10][10], int x, int y, int sol[10][10]) {
    if (x == n - 1 && y == n - 1) {
        sol[x][y] = 1;
        return true;
    }

    if (isSafe(n, maze, x, y, sol)) {
        sol[x][y] = 1;

        if (solveMazeUtil(n, maze, x + 1, y, sol)) return true;
        if (solveMazeUtil(n, maze, x, y + 1, sol)) return true;
        if (solveMazeUtil(n, maze, x - 1, y, sol)) return true;
        if (solveMazeUtil(n, maze, x, y - 1, sol)) return true;

        sol[x][y] = 0;
        return false;
    }

    return false;
}

void solveMaze(int n, int maze[10][10]) {
    int sol[10][10] = {0};

    if (!solveMazeUtil(n, maze, 0, 0, sol)) {
        cout << "No solution exists\n";
        return;
    }

    cout << "Path found:\n";
    printSolution(n, sol);
}

int main() {
    int n = 5;
    int maze[10][10] = {
        {1, 0, 0, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 1, 0, 1, 0},
        {1, 1, 1, 1, 0},
        {0, 0, 0, 1, 1}
    };

    solveMaze(n, maze);
    return 0;
}
