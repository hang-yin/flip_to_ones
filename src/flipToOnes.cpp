#include <vector>
#include <iostream>

using namespace std;

void FlipToOnes(vector<vector<int>> &matrix, int m, int n) {
    // Create a vector to store the row and column indices where 1 is found
    vector<int> rowIndices, colIndices;

    // Iterate through the matrix and store the indices where 1 is found
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1) {
                rowIndices.push_back(i);
                colIndices.push_back(j);
            }
        }
    }

    // Iterate through the row and column indices and set all the elements in the corresponding rows and columns to 1
    for (int i = 0; i < rowIndices.size(); i++) {
        int row = rowIndices[i];
        for (int j = 0; j < n; j++) {
            matrix[row][j] = 1;
        }
    }

    for (int i = 0; i < colIndices.size(); i++) {
        int col = colIndices[i];
        for (int j = 0; j < m; j++) {
            matrix[j][col] = 1;
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
    FlipToOnes(matrix, 4, 4);

    // Print the modified matrix
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}