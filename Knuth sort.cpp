#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void knuth_shuffle(int arr[], int n) {
    for (int i=0; i<n; i++) {
        int j = rand() % (i);  // Generate a random index
        swap(&arr[i], &arr[j]);    // Swap elements
    }
}
// Function to print the array
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    srand(time(0));  // Seed the random number generator

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};  // Example array
    int n = sizeof(arr) / sizeof(arr[0]);  // Calculate number of elements in the array

    printf("Original array:\n");
    print_array(arr, n);  // Print the original array

    // Shuffle the array
    knuth_shuffle(arr, n);
    printf("Shuffled array:\n");
    print_array(arr, n);  // Print the shuffled array

    return 0;
}
