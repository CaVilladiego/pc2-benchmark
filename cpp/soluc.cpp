#include <chrono>
#include <iostream>
#include <fstream>

using namespace std;
using namespace std::chrono;

#define SIZE 5000  // Large matrix size

int main() {
    // Allocate a 2D array dynamically (avoid stack overflow)
    int** matrix = new int*[SIZE];
    for (int i = 0; i < SIZE; i++)
        matrix[i] = new int[SIZE];

    int num = 1;

    // Start time measurement
    auto start = high_resolution_clock::now();

    // Fill the matrix diagonally
    for (int col = 0; col < SIZE; col++) {
        int i = 0, j = col;
        while (i < SIZE && j >= 0) {
            matrix[i][j] = num++;
            i++;
            j--;
        }
    }

    for (int row = 1; row < SIZE; row++) {
        int i = row, j = SIZE - 1;
        while (i < SIZE && j >= 0) {
            matrix[i][j] = num++;
            i++;
            j--;
        }
    }

    // End time measurement
    auto stop = high_resolution_clock::now();

    // Compute elapsed time in microseconds
    auto duration = duration_cast<microseconds>(stop - start);

    // Save execution time to file
    ofstream file("/app/output/time.txt");
    if (file.is_open()) {
        file << duration.count() << " µs" << endl;
        file.close();
    }

    // Free allocated memory
    for (int i = 0; i < SIZE; i++)
        delete[] matrix[i];
    delete[] matrix;

    return 0;
}