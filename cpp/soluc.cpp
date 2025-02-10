#include <chrono>
#include <iostream>
#include <fstream>

using namespace std;
using namespace std::chrono;

#define SIZE 5000  // Large matrix size

// Recursive function to fill the matrix diagonally
void fillDiagonal(int** matrix, int i, int j, int& num) {
    if (i >= SIZE || j < 0) return; // Base case: Stop when out of bounds
    matrix[i][j] = num++;
    fillDiagonal(matrix, i + 1, j - 1, num); // Recursive step
}

int main() {
    // Allocate a 2D array dynamically
    int** matrix = new int*[SIZE];
    for (int i = 0; i < SIZE; i++)
        matrix[i] = new int[SIZE];

    int num = 1;

    // Start time measurement
    auto start = high_resolution_clock::now();

    // Fill the upper triangle of the matrix
    for (int col = 0; col < SIZE; col++)
        fillDiagonal(matrix, 0, col, num);

    // Fill the lower triangle of the matrix
    for (int row = 1; row < SIZE; row++)
        fillDiagonal(matrix, row, SIZE - 1, num);

    // End time measurement
    auto stop = high_resolution_clock::now();

    // Compute elapsed time in microseconds
    auto duration = duration_cast<microseconds>(stop - start);

    // Save execution time to file
    ofstream file("/app/output/time.txt");
    if (file.is_open()) {
        file << "cpp:" << duration.count() << " µs" << endl;
        file.close();
    }

    // Free allocated memory
    for (int i = 0; i < SIZE; i++)
        delete[] matrix[i];
    delete[] matrix;

    return 0;
}
