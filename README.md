# Matrix Operation: Flip to Ones

## Overview
This is a C++ program that for a given m by n matrix of 0's and 1's, if any element is 1, sets the entire row and column to 1 in place, for that element. 

## Assumptions
 - Input matrix is composed of 0 and 1.
 - Input matrix is two-dimensional and can have arbitrary number of rows and columns.

## File Organization
 - `src`: contains the main cpp file with the function `flipToOnes`
 - `test`: contains a test file `flipToOnes_test` with a number of test cases
 - `CMakeLists.txt`: contains a set of directives and instructions describing source files and targets

## Compilation Instructions
 - clone this repository `git clone https://github.com/hang-yin/flip_to_ones`
 - cd into this directory `cd flip_to_ones`
 - create a build directory `mkdir build`
 - cd into the empty build directory `cd build`
 - run `cmake ..`
 - run `make`
 - run `./flipToOnes` to execute the main function in `flipToOnes.cpp`
 - run `./flipToOnes_test` to execute the tests in `flipToOnes_test.cpp`

## Complexity Analysis
 - Time: O(m*n); Space: O(max(m,n))
   - an naive approach to this problem is to create two vectors and store the rows and columns that need to be set to 1's
   - with these two vectors, we can then loop through the matrix to set these rows and columns to 1's
   - since we need to loop through the vector, the time complexity would be O(m*n)
   - since we need to create the two vectors, the time complexity would be O(max(m, n))
 - Time: O(m*n); Space: O(1)
   - to improve the space complexity, we can perform a single pass through the matrix and use the first row and column as temporary storage
   - my implementation uses two flags to store whether the first row and column should be set to 1 and sets the rest accordingly
   - in the very end, we go back and set the first row and column
   - since we are still looping through the entire matrix, the time complexity would be O(m*n)
   - since we are not storing any data structure that would scale with the size of the matrix, the space complexity would be O(1)

## Example Output
![Screenshot from 2022-12-20 17-58-56](https://user-images.githubusercontent.com/60046203/208789546-d27d2c59-f108-4b20-babc-1f32ff09cfb3.png)
