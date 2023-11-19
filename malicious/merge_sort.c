#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000  // Adjust the size as needed
#define NUM_ITERATIONS 1000000  // Adjust the size as needed


void merge(int arr[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Same as (left+right)/2, but avoids overflow for large left and right
        int middle = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // Merge the sorted halves
        merge(arr, left, middle, right);
    }
}

int main() {
    int *arr = malloc(ARRAY_SIZE * sizeof(int));

    // Seed the random number generator
    srand(time(NULL));

    // Generate a large random array
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        arr[i] = rand();
    }

    // Perform merge sort
    clock_t start_time = clock();
    for(int i=0; i<NUM_ITERATIONS; i++)
        mergeSort(arr, 0, ARRAY_SIZE - 1);
    clock_t end_time = clock();

    // Calculate and print the execution time
    double execution_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Merge sort took %.6f seconds\n", execution_time);

    free(arr);
    return 0;
}
