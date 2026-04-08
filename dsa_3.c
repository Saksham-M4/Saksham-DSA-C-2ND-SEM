#include <stdio.h>

int main() {
    int matrix[10][10], sparse[100][3];
    int i, j, rows, cols, k = 1;

    // Input rows and columns
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // Input matrix elements
    printf("Enter the matrix elements:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // First row of sparse matrix (metadata)
    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = 0; // count of non-zero elements (will update later)

    // Convert to sparse form
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            if(matrix[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    // Store total non-zero elements
    sparse[0][2] = k - 1;

    // Print sparse matrix
    printf("\nSparse Matrix Representation:\n");
    for(i = 0; i < k; i++) {
        printf("%d %d %d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }

    return 0;
}