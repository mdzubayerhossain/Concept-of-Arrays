#include <stdio.h>

int removeDuplicates(int arr[], int n) {
    if (n == 0 || n == 1)
        return n;

    int temp[n], i, j = 0;
    
    // Sort the array (Bubble Sort for simplicity)
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Remove duplicates
    for (i = 0; i < n - 1; i++) {
        if (arr[i] != arr[i + 1]) {
            temp[j++] = arr[i];
        }
    }
    temp[j++] = arr[n - 1]; // Store last element

    // Copy unique elements back to the original array
    for (i = 0; i < j; i++) {
        arr[i] = temp[i];
    }

    return j; // New size of array
}

int main() {
    int n, i;

    // Input array size
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input elements
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Remove duplicates
    n = removeDuplicates(arr, n);

    // Print unique elements
    printf("Array after removing duplicates: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
