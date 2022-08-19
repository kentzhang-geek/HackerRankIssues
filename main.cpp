#include <iostream>
#include <vector>

using namespace std;

void swapInt(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
    return;
}

bool checkMatrixRow(int rowNum, vector<vector<int>> &matrix) {
    size_t matrixSize = matrix.size();
    int sumLeft = 0;
    int sumRight = 0;
    for (size_t columnIdx = 0; columnIdx < matrixSize; columnIdx++) {
        if (columnIdx < (matrixSize / 2)) {
            sumLeft += matrix[rowNum][columnIdx];
        } else {
            sumRight += matrix[rowNum][columnIdx];
        }
    }
    return sumLeft > sumRight;
}

bool checkMatrixColumn(int colNum, vector<vector<int>> &matrix) {
    size_t matrixSize = matrix.size();
    int sumTop = 0;
    int sumBottom = 0;
    for (size_t rowIdx = 0; rowIdx < matrixSize; rowIdx++) {
        if (rowIdx < (matrixSize / 2)) {
            sumTop += matrix[rowIdx][colNum];
        } else {
            sumBottom += matrix[rowIdx][colNum];
        }
    }
    return sumTop > sumBottom;
}

void swapColumn(int colNum, vector<vector<int>> &matrix) {
    for (size_t i = 0; i < matrix.size() / 2; i++) {
        swap(matrix[i][colNum], matrix[matrix.size() - 1 - i][colNum]);
    }
}

void swapRow(int rowNum, vector<vector<int>> &matrix) {
    for (size_t i = 0; i < matrix.size() / 2; i++) {
        swap(matrix[rowNum][i], matrix[rowNum][matrix.size() - 1 - i]);
    }
}

int flippingMatrix(vector<vector<int>> matrix) {
    bool condition = true;
    bool check = false;
    while (condition) {
        condition = false;
        for (size_t i = 0; i < matrix.size(); i++) {
            check = !checkMatrixRow(i, matrix);
            if (check) {
                swapRow(i, matrix);
            }
            condition = condition || check;
        }
        for (int i = 0; i < matrix.size(); i++) {
            check = !checkMatrixColumn(i, matrix);
            if (check) {
                swapColumn(i, matrix);
            }
            condition = condition || check;
        }
    }
    long int sum = 0;
    for (int i = 0; i < matrix.size() / 2; i++) {
        for (int j = 0; j < matrix.size() / 2; j++) {
            sum += matrix[i][j];
        }
    }
    for (auto row : matrix) {
        for (auto cell : row) {
            std::cout << cell << ", ";
        }
        std::cout << std::endl;
    }
    return sum;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<vector<int>> matrix = {
            {112, 42,  83,  119},
            {56,  125, 56,  49},
            {15,  78,  101, 43},
            {62,  98,  114, 108},
    };
    int res = flippingMatrix(matrix);
    printf("%d\n", res);
    return 0;
}
