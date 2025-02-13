#include <stdio.h>

int main() {
    int row1, col1, row2, col2;

    // Input dimensions of the first matrix
    printf("Enter rows and columns of the first matrix: ");
    scanf("%d %d", &row1, &col1);

    int matrix1[row1][col1];

    // Input elements of the first matrix
    printf("Enter elements of the first matrix:\n");
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Input dimensions of the second matrix
    printf("Enter rows and columns of the second matrix: ");
    scanf("%d %d", &row2, &col2);

    // Matrix multiplication is only possible if col1 == row2
    if (col1 != row2) {
        printf("Matrix multiplication is not possible. The number of columns of the first matrix must equal the number of rows of the second matrix.\n");
        return 0;
    }

    int matrix2[row2][col2], result[row1][col2];

    // Input elements of the second matrix
    printf("Enter elements of the second matrix:\n");
    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < col2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Initialize the result matrix to 0
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            result[i][j] = 0;
        }
    }

    // Matrix multiplication
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            for (int k = 0; k < col1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // Print the result matrix
    printf("Result of matrix multiplication:\n");
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
