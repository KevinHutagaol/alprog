#include <stdio.h>
#include <stdlib.h>

double **scan_matrix(size_t *dim);

void print_matrix(size_t row, size_t col, double **matrix);

double **multiply(size_t row1, size_t col1, double **matrix1);

double **add(size_t row1, size_t col1, double **matrix1);

double **subtract(size_t row1, size_t col1, double **matrix1);

double **transpose(size_t row1, size_t col1, double **matrix1);

int main(void) { 
    size_t dim1;
    double **matrix1 = scan_matrix(&dim1);

    double **after_add = add(dim1, dim1 , matrix1);
    // printf("after add\n");
    // print_matrix(dim1, dim1, after_add);
    // printf("\n");


    double **after_subtract = subtract(dim1, dim1, after_add);
    // printf("after sub\n");
    // print_matrix(dim1, dim1, after_subtract);
    // printf("\n");


    double **after_multiply = multiply(dim1, dim1, after_subtract);
    // printf("after mult\n");
    // print_matrix(dim1, dim1, after_multiply);
    // printf("\n");


    double **after_transpose = transpose(dim1, dim1, after_multiply);


    printf("\n");
    printf("Result of transpose(multiply(subtract(add(MATRIX1)))):\n");

    print_matrix(dim1, dim1, after_transpose);

    for (size_t i = 0; i < dim1; ++i) {
        free(matrix1[i]);
    }
    free(matrix1);

    for (size_t i = 0; i < dim1; ++i) {
        free(after_add[i]);
    }
    free(after_add);

    for (size_t i = 0; i < dim1; ++i) {
        free(after_subtract[i]);
    }
    free(after_subtract);

    for (size_t i = 0; i < dim1; ++i) {
        free(after_multiply[i]);
    }
    free(after_multiply);

    for (size_t i = 0; i < dim1; ++i) {
        free(after_transpose[i]);
    }
    free(after_transpose);

    return 0; 
}

double **scan_matrix(size_t *dim) {
    size_t dim_temp;
    printf("Enter dimensions of square matrix:  ");
    if (scanf("%zu", &dim_temp) != 1) {
        fprintf(stderr, "Error: Invalid matrix dimensions reading from stdin\n");
        return NULL;
    }

    double **out_matrix = malloc(dim_temp * sizeof(double *));
    if (out_matrix == NULL) {
        fprintf(stderr, "Error: Unable to allocate memory for matrix\n");
        return NULL;
    }

    for (size_t i = 0; i < dim_temp; i++) {
        out_matrix[i] = malloc(dim_temp * sizeof(double));
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

    for (int i = 0; i < dim_temp; i++) {
        for (int j = 0; j < dim_temp; j++) {
            scanf(" %lf", &out_matrix[i][j]);
        }
    }

    *dim = dim_temp;

    return out_matrix;
}

double **multiply(size_t row1, size_t col1, double **matrix1) { 
    double **out_matrix = malloc(row1 * sizeof(double *));
    if (out_matrix == NULL) {
        fprintf(stderr, "Error: Unable to allocate memory for matrix\n");
        return NULL;
    }

    for (size_t i = 0; i < row1; i++) {
        out_matrix[i] = malloc(row1 * sizeof(double));
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
        for (size_t j = 0; j < col1; j++) {
            if (i == j) {
                out_matrix[i][j] = 2*matrix1[i][j];
            } else { 
                out_matrix[i][j] = matrix1[i][j];
            }
        }
    }

    return out_matrix;
}

double **transpose(size_t row1, size_t col1, double **matrix1) { 
    double **out_matrix = malloc(row1 * sizeof(double *));
    if (out_matrix == NULL) {
        fprintf(stderr, "Error: Unable to allocate memory for matrix\n");
        return NULL;
    }

    for (size_t i = 0; i < row1; i++) {
        out_matrix[i] = malloc(row1 * sizeof(double));
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
        for (size_t j = 0; j < col1; j++) {
            out_matrix[i][j] = matrix1[j][i];
        }
    }

    return out_matrix;
}

double **add(size_t row1, size_t col1, double **matrix1) { 
    double **out_matrix = malloc(row1 * sizeof(double *));
    if (out_matrix == NULL) {
        fprintf(stderr, "Error: Unable to allocate memory for matrix\n");
        return NULL;
    }

    for (size_t i = 0; i < row1; i++) {
        out_matrix[i] = malloc(row1 * sizeof(double));
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
        for (size_t j = 0; j < col1; j++) {
            if (i < j) { 
                out_matrix[i][j] = matrix1[i][j] + 0.3; 
            } else { 
                out_matrix[i][j] = matrix1[i][j];
            }
        }
    }

    return out_matrix;
}

double **subtract(size_t row1, size_t col1, double **matrix1) { 
    double **out_matrix = malloc(row1 * sizeof(double *));
    if (out_matrix == NULL) {
        fprintf(stderr, "Error: Unable to allocate memory for matrix\n");
        return NULL;
    }

    for (size_t i = 0; i < row1; i++) {
        out_matrix[i] = malloc(row1 * sizeof(double));
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
        for (size_t j = 0; j < col1; j++) {
            if (i > j) { 
                out_matrix[i][j] = matrix1[i][j] - 0.2; 
            } else { 
                out_matrix[i][j] = matrix1[i][j];
            }
        }
    }

    return out_matrix;
}



void print_matrix(size_t row, size_t col, double **matrix) {
    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < col; j++) {
            printf("%.1lf ", matrix[i][j]);
        }
        printf("\n");
    }
}
