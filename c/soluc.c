#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define SIZE 5000  // Large matrix size

// Recursive function to fill the matrix diagonally
void fillDiagonal(int** matrix, int i, int j, int* num) {
    if (i >= SIZE || j < 0) return; // Base case: Stop when out of bounds
    matrix[i][j] = (*num)++;
    fillDiagonal(matrix, i + 1, j - 1, num); // Recursive step
}

// Function to get current time in microseconds
long long getTimeInMicroseconds() {
    struct timeval time;
    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000000) + time.tv_usec;
}

int main() {
    // Allocate a 2D array dynamically
    int** matrix = (int**)malloc(SIZE * sizeof(int*));
    for (int i = 0; i < SIZE; i++)
        matrix[i] = (int*)malloc(SIZE * sizeof(int));

    int num = 1;

    // Start time measurement
    long long start_time = getTimeInMicroseconds();

    // Fill the upper triangle of the matrix
    for (int col = 0; col < SIZE; col++)
        fillDiagonal(matrix, 0, col, &num);

    // Fill the lower triangle of the matrix
    for (int row = 1; row < SIZE; row++)
        fillDiagonal(matrix, row, SIZE - 1, &num);

    // End time measurement
    long long end_time = getTimeInMicroseconds();
    long long time_taken = end_time - start_time;

    // Save execution time to file
    FILE* file = fopen("/app/output/time.txt", "w");
    if (file != NULL) {
        fprintf(file, "C: %lld µs\n", time_taken);
        fclose(file);
    }

    // Free allocated memory
    for (int i = 0; i < SIZE; i++)
        free(matrix[i]);
    free(matrix);

    return 0;
}
