#include <vector>
#include <iostream>

using namespace std;

void flipToOnes(vector<vector<int>> &matrix) {
    // Get the number of rows and columns in the matrix
    int m = matrix.size();
    int n = matrix[0].size();

    // Create a flag to store whether the first row or column should be set to 1
    bool firstRow = false;
    bool firstCol = false;

    // Iterate through the matrix and set the first row and column flags if necessary
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1) {
                if (i == 0) firstRow = true;
                if (j == 0) firstCol = true;
                matrix[0][j] = 1;
                matrix[i][0] = 1;
            }
        }
    }

    // Iterate through the matrix and set the rows and columns to 1 as necessary
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][0] == 1 || matrix[0][j] == 1) {
                matrix[i][j] = 1;
            }
        }
    }

    // Set the first row and column to 1 if necessary
    if (firstRow) {
        for (int j = 0; j < n; j++) {
            matrix[0][j] = 1;
        }
    }
    if (firstCol) {
        for (int i = 0; i < m; i++) {
            matrix[i][0] = 1;
        }
    }
}

int main() {
    // Example matrix
    vector<vector<int>> matrix = {{0, 0, 0, 0},
                                  {0, 0, 0, 0},
                                  {0, 0, 0, 0},
                                  {0, 0, 0, 0}};

    // Set the element at row 2, column 3 to 1
    matrix[1][2] = 1;

    // Set the row and column of the element with value 1 to 1
    flipToOnes(matrix);

    // Print the modified matrix
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}