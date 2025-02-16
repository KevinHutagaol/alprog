#include <stdio.h>
#include <stdlib.h>

int **multiply_matrix(size_t row1, size_t col1, int **matrix1, size_t row2, size_t col2, int **matrix2);

void print_matrix(size_t row, size_t col, int **matrix);

int **scan_matrix(size_t *rows, size_t *cols);

int main(void) {
    size_t rows1, cols1;
    int **matrix1 = scan_matrix(&rows1, &cols1);

    size_t rows2, cols2;
    int **matrix2 = scan_matrix(&rows2, &cols2);

    size_t rows_result = rows1;
    int **matrix_result = multiply_matrix(rows1, cols1, matrix1, rows2, cols2, matrix2);


    printf("Result:\n");
    print_matrix(rows1, cols2, matrix_result);

    for (size_t i = 0; i < rows1; ++i) {
        free(matrix1[i]);
    }
    free(matrix1);
    for (size_t i = 0; i < rows2; ++i) {
        free(matrix2[i]);
    }
    free(matrix2);
    for (size_t i = 0; i < rows_result; ++i) {
        free(matrix_result[i]);
    }
    free(matrix_result);

    return 0;
}

int **multiply_matrix(size_t row1, size_t col1, int **matrix1, size_t row2, size_t col2, int **matrix2) {
    if (col1 != row2) {
        fprintf(stderr, "Error: Invalid matrix dimensions, matrix 1 column: %zu, matrix 2 row: %zu\n", col1, row2);
        return NULL;
    }

    int **out_matrix = malloc(row1 * sizeof(int *));
    if (out_matrix == NULL) {
        fprintf(stderr, "Error: Unable to allocate memory for matrix\n");
        return NULL;
    }

    for (size_t i = 0; i < row1; i++) {
        out_matrix[i] = malloc(col2 * sizeof(int));
        if (out_matrix[i] == NULL) {
            fprintf(stderr, "Error: Unable to allocate memory for matrix row %zu\n", i);
            for (size_t j = 0; j < i; j++) {
                free(out_matrix[j]);
            }
            free(out_matrix);
            return NULL;
        }
    }

    for (size_t i = 0; i < row1; i++) {
        for (size_t j = 0; j < col2; j++) {
            int temp = 0;
            for (size_t k = 0; k < col1; k++) {
                temp += matrix1[i][k] * matrix2[k][j];
            }
            out_matrix[i][j] = temp;
        }
    }

    return out_matrix;
}

void print_matrix(size_t row, size_t col, int **matrix) {
    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int **scan_matrix(size_t *rows, size_t *cols) {
    size_t row_temp, col_temp;
    printf("Enter dimensions of matrix (ex: 2, 3):  ");
    if (scanf("%zu, %zu", &row_temp, &col_temp) != 2) {
        fprintf(stderr, "Error: Invalid matrix dimensions reading from stdin\n");
        return NULL;
    }

    int **out_matrix = malloc(row_temp * sizeof(int *));
    if (out_matrix == NULL) {
        fprintf(stderr, "Error: Unable to allocate memory for matrix\n");
        return NULL;
    }

    for (size_t i = 0; i < row_temp; i++) {
        out_matrix[i] = malloc(col_temp * sizeof(int));
        if (out_matrix[i] == NULL) {
            fprintf(stderr, "Error: Unable to allocate memory for matrix row %zu\n", i);
            for (size_t j = 0; j < i; j++) {
                free(out_matrix[j]);
            }
            free(out_matrix);
            return NULL;
        }
    }
    printf("Enter Matrix\n");

    for (int i = 0; i < row_temp; i++) {
        for (int j = 0; j < col_temp; j++) {
            scanf(" %d", &out_matrix[i][j]);
        }
    }

    *rows = row_temp;
    *cols = col_temp;

    return out_matrix;
}
