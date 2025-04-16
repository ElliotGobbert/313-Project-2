#include <stdio.h>
#include <stdlib.h>

// Matrix struct
typedef struct {
    int rows;
    int cols;
    int** data;
} Matrix;

// Create a matrix
Matrix createMatrix(int rows, int cols) {
    Matrix m;
    m.rows = rows;
    m.cols = cols;

    if (rows <= 0 || cols <= 0) {
        m.data = NULL;
        printf("Invalid matrix size\n");
        return m;
    }

    m.data = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; ++i) {
        m.data[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; ++j) {
            m.data[i][j] = 0;
        }
    }
    return m;
}

// Free memory
void destroyMatrix(Matrix* m) {
    if (m->data != NULL) {
        for (int i = 0; i < m->rows; ++i) {
            free(m->data[i]);
        }
        free(m->data);
        m->data = NULL;
        m->rows = 0;
        m->cols = 0;
    }
}

// Fill matrix with a single value
void fillMatrix(Matrix* m, int value) {
    for (int i = 0; i < m->rows; ++i) {
        for (int j = 0; j < m->cols; ++j) {
            m->data[i][j] = value;
        }
    }
}

// Insert values from 1D array
void insertMatrix(Matrix* m, int* values) {
    for (int i = 0; i < m->rows; ++i) {
        for (int j = 0; j < m->cols; ++j) {
            m->data[i][j] = values[i * m->cols + j];
        }
    }
}

// Print matrix
void dumpMatrix(const Matrix* m, const char* name) {
    if (name != NULL && name[0] != '\0') {
        printf("%s:\n", name);
    }

    for (int i = 0; i < m->rows; ++i) {
        for (int j = 0; j < m->cols; ++j) {
            printf(" %d", m->data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Matrix addition (returns new matrix)
Matrix addMatrix(const Matrix* a, const Matrix* b) {
    if (a->rows != b->rows || a->cols != b->cols) {
        printf("Matrix size mismatch for addition\n");
        return createMatrix(0, 0);
    }

    Matrix result = createMatrix(a->rows, a->cols);
    for (int i = 0; i < a->rows; ++i) {
        for (int j = 0; j < a->cols; ++j) {
            result.data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
    return result;
}

// Matrix scalar addition
Matrix addScalar(const Matrix* m, int value) {
    Matrix result = createMatrix(m->rows, m->cols);
    for (int i = 0; i < m->rows; ++i) {
        for (int j = 0; j < m->cols; ++j) {
            result.data[i][j] = m->data[i][j] + value;
        }
    }
    return result;
}

// Matrix multiplication (dot product)
Matrix multiplyMatrix(const Matrix* a, const Matrix* b) {
    if (a->cols != b->rows) {
        printf("Matrix size mismatch for multiplication\n");
        return createMatrix(0, 0);
    }

    Matrix result = createMatrix(a->rows, b->cols);
    for (int i = 0; i < a->rows; ++i) {
        for (int j = 0; j < b->cols; ++j) {
            result.data[i][j] = 0;
            for (int k = 0; k < a->cols; ++k) {
                result.data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }
    return result;
}

// Matrix scalar multiplication
Matrix multiplyScalar(const Matrix* m, int value) {
    Matrix result = createMatrix(m->rows, m->cols);
    for (int i = 0; i < m->rows; ++i) {
        for (int j = 0; j < m->cols; ++j) {
            result.data[i][j] = m->data[i][j] * value;
        }
    }
    return result;
}

int main() {
    int a[] = { 6, 4, 8, 3 };
    int b[] = { 1, 2, 3, 4, 5, 6 };
    int c[] = { 2, 4, 6, 1, 3, 5 };

    Matrix A = createMatrix(2, 2);
    insertMatrix(&A, a);

    Matrix B = createMatrix(2, 3);
    insertMatrix(&B, b);

    Matrix C = createMatrix(2, 3);
    insertMatrix(&C, c);

    dumpMatrix(&A, "A");
    dumpMatrix(&B, "B");
    dumpMatrix(&C, "C");

    Matrix Bplus3 = addScalar(&B, 3);
    Matrix D1 = addMatrix(&A, &Bplus3); // Invalid sizes — will warn
    Matrix D2 = multiplyMatrix(&Bplus3, &C);
    dumpMatrix(&D2, "D");

    // Cleanup
    destroyMatrix(&A);
    destroyMatrix(&B);
    destroyMatrix(&C);
    destroyMatrix(&Bplus3);
    destroyMatrix(&D1);
    destroyMatrix(&D2);

    return 0;
}