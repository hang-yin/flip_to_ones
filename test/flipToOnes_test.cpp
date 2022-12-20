#include <gtest/gtest.h>
#include <vector>

using namespace std;

void flipToOnes(vector<vector<int>> &matrix) {
    // If the matrix is empty, return
    if (matrix.size() == 0) return;

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

TEST(FlipToOnesTest, ExampleMatrix) {
    // Create a matrix of all zeros
    vector<vector<int>> matrix = {{1, 0, 0},
                                  {0, 0, 0},
                                  {0, 1, 0}};

    // Set the row and column of the element with value 1 to 1
    flipToOnes(matrix);

    // Check that the matrix is correct
    vector<vector<int>> expected = {{1, 1, 1},
                                    {1, 1, 0},
                                    {1, 1, 1}};
    EXPECT_EQ(matrix, expected);
}

TEST(FlipToOnesTest, ZeroMatrix) {
    // Create a matrix of all zeros
    vector<vector<int>> matrix = {{0, 0, 0, 0},
                                  {0, 0, 0, 0},
                                  {0, 0, 0, 0},
                                  {0, 0, 0, 0}};

    // Set the row and column of the element with value 1 to 1
    flipToOnes(matrix);

    // Check that the matrix is correct
    vector<vector<int>> expected = {{0, 0, 0, 0},
                                    {0, 0, 0, 0},
                                    {0, 0, 0, 0},
                                    {0, 0, 0, 0}};
    EXPECT_EQ(matrix, expected);
}

TEST(FlipToOnesTest, OneElement) {
    // Create a matrix with a single element set to 1
    vector<vector<int>> matrix = {{0, 0, 0, 0},
                                  {0, 0, 0, 0},
                                  {0, 0, 1, 0},
                                  {0, 0, 0, 0}};

    // Set the row and column of the element with value 1 to 1
    flipToOnes(matrix);

    // Create the resulting matrix
    vector<vector<int>> expected = {{0, 0, 1, 0},
                                    {0, 0, 1, 0},
                                    {1, 1, 1, 1},
                                    {0, 0, 1, 0}};
    
    // Check that the matrix is set to the result
    EXPECT_EQ(matrix, expected);
}

TEST(FlipToOnesTest, MultipleElements) {
    // Create a matrix with multiple elements set to 1
    vector<vector<int>> matrix = {{0, 0, 0, 0},
                                  {0, 0, 1, 0},
                                  {0, 0, 1, 0},
                                  {0, 1, 0, 0}};

    // Set the row and column of the element with value 1 to 1
    flipToOnes(matrix);

    // Create the resulting matrix
    vector<vector<int>> expected = {{0, 1, 1, 0},
                                    {1, 1, 1, 1},
                                    {1, 1, 1, 1},
                                    {1, 1, 1, 1}};
    
    EXPECT_EQ(matrix, expected);
}

TEST(FlipToOnesTest, DifferentDimensions) {
    // Create a matrix with multiple elements set to 1
    vector<vector<int>> matrix = {{0, 0, 0, 0, 0},
                                  {0, 0, 1, 0, 0},
                                  {0, 0, 1, 0, 0},
                                  {0, 1, 0, 0, 0}};
    
    // Set the row and column of the element with value 1 to 1
    flipToOnes(matrix);

    // Create the resulting matrix
    vector<vector<int>> result = {{0, 1, 1, 0, 0},
                                  {1, 1, 1, 1, 1},
                                  {1, 1, 1, 1, 1},
                                  {1, 1, 1, 1, 1}};
    
    // Check that the matrix is set to the result
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            EXPECT_EQ(matrix[i][j], result[i][j]);
        }
    }
}

TEST(FlipToOnesTest, OneRow) {
    // Create a matrix with a single row
    vector<vector<int>> matrix = {{0, 0, 0, 0, 0}};

    // Set the row and column of the element with value 1 to 1
    flipToOnes(matrix);

    // Check that the matrix is correct
    vector<vector<int>> expected = {{0, 0, 0, 0, 0}};
    EXPECT_EQ(matrix, expected);
}

TEST(FlipToOnesTest, OneColumn) {
    // Create a matrix with a single column
    vector<vector<int>> matrix = {{0},
                                  {0},
                                  {0},
                                  {0},
                                  {0}};

    // Set the row and column of the element with value 1 to 1
    flipToOnes(matrix);

    // Check that the matrix is correct
    vector<vector<int>> expected = {{0},
                                    {0},
                                    {0},
                                    {0},
                                    {0}};
    EXPECT_EQ(matrix, expected);
}

TEST(FlipToOnesTest, OneElementMatrix) {
    // Create a matrix with a single element
    vector<vector<int>> matrix = {{0}};

    // Set the row and column of the element with value 1 to 1
    flipToOnes(matrix);

    // Check that the matrix is correct
    vector<vector<int>> expected = {{0}};
    EXPECT_EQ(matrix, expected);
}

TEST(FlipToOnesTest, OneElementMatrixSetToOne) {
    // Create a matrix with a single element
    vector<vector<int>> matrix = {{1}};

    // Set the row and column of the element with value 1 to 1
    flipToOnes(matrix);

    // Check that the matrix is correct
    vector<vector<int>> expected = {{1}};
    EXPECT_EQ(matrix, expected);
}

TEST(FlipToOnesTest, AllOnes){
    // Create a matrix with all elements set to 1
    vector<vector<int>> matrix = {{1, 1, 1, 1, 1},
                                  {1, 1, 1, 1, 1},
                                  {1, 1, 1, 1, 1},
                                  {1, 1, 1, 1, 1}};

    // Set the row and column of the element with value 1 to 1
    flipToOnes(matrix);

    // Check that the matrix is correct
    vector<vector<int>> expected = {{1, 1, 1, 1, 1},
                                    {1, 1, 1, 1, 1},
                                    {1, 1, 1, 1, 1},
                                    {1, 1, 1, 1, 1}};
    EXPECT_EQ(matrix, expected);
}

TEST(FlipToOnesTest, EmptyMatrix) {
    // Create an empty matrix
    vector<vector<int>> matrix = {};

    // Set the row and column of the element with value 1 to 1
    flipToOnes(matrix);

    // Check that the matrix is correct
    vector<vector<int>> expected = {};
    EXPECT_EQ(matrix, expected);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

