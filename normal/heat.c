#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000 // Adjust the grid size as needed

// Function to perform the heat benchmark
void heat_benchmark(double *grid, size_t size, int steps) {
    double *temp = (double *)malloc(size * size * sizeof(double));
    if (temp == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    // Initialize the grid with random values
    srand(time(NULL));
    for (size_t i = 0; i < size * size; i++) {
        grid[i] = (double)rand() / RAND_MAX;
    }

    // Perform the heat diffusion simulation
    for (int step = 0; step < steps; step++) {
        for (size_t i = 1; i < size - 1; i++) {
            for (size_t j = 1; j < size - 1; j++) {
                temp[i * size + j] = 0.25 * (grid[(i - 1) * size + j] +
                                             grid[(i + 1) * size + j] +
                                             grid[i * size + (j - 1)] +
                                             grid[i * size + (j + 1)]);
            }
        }

        // Update the grid
        double *swap = grid;
        grid = temp;
        temp = swap;
    }

    // Free temporary memory
    free(temp);
}

int main() {
    // Adjust the grid size and number of steps based on your needs
    size_t grid_size = N;
    int num_steps = 100000;

    double *grid = (double *)malloc(grid_size * grid_size * sizeof(double));
    if (grid == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    // Record the start time
    clock_t start_time = clock();

    // Perform the heat benchmark
    heat_benchmark(grid, grid_size, num_steps);

    // Record the end time
    clock_t end_time = clock();

    // Calculate the execution time
    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Heat benchmark with grid size %zu took %.2f seconds.\n", grid_size, execution_time);

    // Free allocated memory
    free(grid);

    return 0;
}
