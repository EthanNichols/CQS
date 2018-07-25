#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int rows;
	int columns;
	float* m;
} matrix;

/// Clear all of the matrix values to 0
static void matrix_clear(matrix* const m) {
	for (int c = 0; c < m->columns; c++) {
		for (int r = 0; r < m->rows; r++) {
			*(m->m + c * m->rows + r) = 0;
		}
	}
}

/// Set a matrix to be an identity version of the matrix
static void matrix_setIdentity(matrix* const m) {
	if (m->rows != m->columns) {
		return;
	}

	for (int c = 0; c < m->columns; c++) {
		for (int r = 0; r < m->rows; r++) {
			*(m->m + c * m->rows + r) = (c == r) ? 1 : 0;
		}
	}
}

/// Allocate a 2D matrix
static matrix* matrix_init(int rows, int columns) {
	matrix* newMat = malloc(sizeof(matrix));
	newMat->rows = rows;
	newMat->columns = columns;
	newMat->m = (float*)malloc(sizeof(float) * (rows * columns));
	matrix_clear(newMat);
	return newMat;
}

/// Free a allocated matrix
static void matrix_free(matrix* m) {
	free(m->m);
	free(m);
}

/// Print matrix values as floats that are formatted
static void matrix_printFormat(const matrix m, int format) {
	for (int c = 0; c < m.columns; c++) {
		printf("[ ");
		for (int r = 0; r < m.rows; r++) {
			printf("%.*f ", format, *(m.m + c * m.rows + r));
		}
		printf("]\n");
	}
}

/// Print matrix values as floats that aren't formatted
static void matrix_printFloat(const matrix m) {
	for (int c = 0; c < m.columns; c++) {
		printf("[");
		for (int r = 0; r < m.rows; r++) {
			printf("%f ", *(m.m + c * m.rows + r));
		}
		printf("]\n");
	}
}

/// Print matrix values as ints (rounded down)
static void matrix_printInt(const matrix m) {
	matrix_printFormat(m, 0);
}