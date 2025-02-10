const fs = require('fs');

const SIZE = 5000; // Large matrix size

// Create an empty matrix (2D array)
const matrix = Array.from({ length: SIZE }, () => Array(SIZE).fill(0));

/**
 * Recursive function to fill the matrix diagonally
 * @param {number[][]} matrix - The 2D array to be filled
 * @param {number} i - Current row index
 * @param {number} j - Current column index
 * @param {object} num - Number object to keep track of the counter (passed by reference)
 */
function fillDiagonal(matrix, i, j, num) {
    if (i >= SIZE || j < 0) return; // Base case: Stop when out of bounds
    matrix[i][j] = num.value++;
    fillDiagonal(matrix, i + 1, j - 1, num); // Recursive step
}

// Start time measurement
const startTime = process.hrtime.bigint();

let num = { value: 1 }; // Using an object to pass by reference

// Fill the upper triangle of the matrix
for (let col = 0; col < SIZE; col++) {
    fillDiagonal(matrix, 0, col, num);
}

// Fill the lower triangle of the matrix
for (let row = 1; row < SIZE; row++) {
    fillDiagonal(matrix, row, SIZE - 1, num);
}

// End time measurement
const endTime = process.hrtime.bigint();
const timeTaken = Number((endTime - startTime) / 1000n); // Convert nanoseconds to microseconds

// Save execution time to file
fs.writeFileSync('/app/output/time.txt', `nodejs: ${timeTaken} µs\n`, 'utf8');
