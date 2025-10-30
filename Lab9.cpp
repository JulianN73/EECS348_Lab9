#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

using Matrix = vector<vector<int>>;

void printMatrix(const Matrix& M) {
    int N = M.size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(4) << M[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void readMatrices(const string& filename, Matrix& A, Matrix& B) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Cannot open file " << filename << endl;
        exit(1);
    }
    int N;
    file >> N;
    A = Matrix(N, vector<int>(N));
    B = Matrix(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            file >> A[i][j];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            file >> B[i][j];
    file.close();
}

Matrix addMatrices(const Matrix& A, const Matrix& B) {
    int N = A.size();
    Matrix C(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

Matrix multiplyMatrices(const Matrix& A, const Matrix& B) {
    int N = A.size();
    Matrix C(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

void diagonalSums(const Matrix& M) {
    int N = M.size();
    int mainSum = 0, antiSum = 0;
    for (int i = 0; i < N; i++) {
        mainSum += M[i][i];
        antiSum += M[i][N-1-i];
    }
    cout << "Main diagonal sum: " << mainSum << endl;
    cout << "Anti-diagonal sum: " << antiSum << endl << endl;
}

Matrix swapRows(const Matrix& M, int r1, int r2) {
    int N = M.size();
    if (r1 < 0 || r1 >= N || r2 < 0 || r2 >= N) {
        cerr << "Invalid row index!" << endl;
        return M;
    }
    Matrix result = M;
    swap(result[r1], result[r2]);
    return result;
}

Matrix swapColumns(const Matrix& M, int c1, int c2) {
    int N = M.size();
    if (c1 < 0 || c1 >= N || c2 < 0 || c2 >= N) {
        cerr << "Invalid column index!" << endl;
        return M;
    }
    Matrix result = M;
    for (int i = 0; i < N; i++) {
        swap(result[i][c1], result[i][c2]);
    }
    return result;
}

Matrix updateElement(const Matrix& M, int row, int col, int value) {
    int N = M.size();
    if (row < 0 || row >= N || col < 0 || col >= N) {
        cerr << "Invalid position!" << endl;
        return M;
    }
    Matrix result = M;
    result[row][col] = value;
    return result;
}

int main() {
    Matrix A, B;
    readMatrices("input.txt", A, B);

    cout << "Matrix A:\n"; printMatrix(A);
    cout << "Matrix B:\n"; printMatrix(B);

    cout << "Task 2: A + B\n";
    printMatrix(addMatrices(A, B));

    cout << "Task 3: A * B\n";
    printMatrix(multiplyMatrices(A, B));

    cout << "Task 4: Diagonal sums of A\n";
    diagonalSums(A);

    cout << "Task 5: Swap rows 0 and 2 in A\n";
    printMatrix(swapRows(A, 0, 2));

    cout << "Task 6: Swap columns 1 and 3 in A\n";
    printMatrix(swapColumns(A, 1, 3));

    cout << "Task 7: Update A[1][1] = 99\n";
    printMatrix(updateElement(A, 1, 1, 99));

    return 0;
}