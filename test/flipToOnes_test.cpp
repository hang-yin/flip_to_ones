#include <gtest/gtest.h>
#include <vector>

using namespace std;

void flipToOnes(vector<vector<int>> &matrix, int m, int n) {
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

TEST(FlipToOnesTest, ZeroMatrix) {
    // Create a matrix of all zeros
    vector<vector<int>> matrix = {{0, 0, 0, 0},
                                  {0, 0, 0, 0},
                                  {0, 0, 0, 0},
                                  {0, 0, 0, 0}};

    // Set the row and column of the element with value 1 to 1
    flipToOnes(matrix, 4, 4);

    // Check that the matrix is still all zeros
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            EXPECT_EQ(matrix[i][j], 0);
        }
    }
}

TEST(FlipToOnesTest, OneElement) {
    // Create a matrix with a single element set to 1
    vector<vector<int>> matrix = {{0, 0, 0, 0},
                                  {0, 0, 0, 0},
                                  {0, 0, 1, 0},
                                  {0, 0, 0, 0}};

    // Set the row and column of the element with value 1 to 1
    flipToOnes(matrix, 4, 4);

    // Check that the row and column of the element with value 1 are set to 1
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == 2 || j == 2) {
                EXPECT_EQ(matrix[i][j], 1);
            } else {
                EXPECT_EQ(matrix[i][j], 0);
            }
        }
    }
}

TEST(FlipToOnesTest, MultipleElements) {
    // Create a matrix with multiple elements set to 1
    vector<vector<int>> matrix = {{0, 0, 0, 0},
                                  {0, 0, 1, 0},
                                  {0, 0, 1, 0},
                                  {0, 1, 0, 0}};

    // Set the row and column of the element with value 1 to 1
    flipToOnes(matrix, 4, 4);

    // Create the resulting matrix
    vector<vector<int>> result = {{0, 1, 1, 0},
                                  {1, 1, 1, 1},
                                  {1, 1, 1, 1},
                                  {1, 1, 1, 1}};
    
    // Check that the matrix is set to the result
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            EXPECT_EQ(matrix[i][j], result[i][j]);
        }
    }
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

