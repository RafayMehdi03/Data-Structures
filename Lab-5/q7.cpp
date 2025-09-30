#include <iostream>
#include <cmath>
using namespace std;

int board[20];

bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

void printSolution(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i] == j) cout << "Q ";
            else cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

void solveNQueens(int row, int n) {
    if (row == n) {
        printSolution(n);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            solveNQueens(row + 1, n);
        }
    }
}

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;
    solveNQueens(0, n);
    return 0;
}

