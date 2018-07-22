#pragma once

#include <stdio.h>

#ifndef MATRIX2x2
#define MATRIX2x2
#endif // !MATRIX2x2

typedef struct
{
	float m1_1;
	float m1_2;
	float m2_1;
	float m2_2;
} matrix2x2;

#pragma region Predfined matrix2x2s
const matrix2x2 matrix2x2_identity = {1, 0, 0, 1};
const matrix2x2 matrix2x2_one = {1, 1, 1, 1};
const matrix2x2 matrix2x2_zero = {0, 0, 0, 0};
#pragma endregion

static matrix2x2* matrix2x2_init(float m11, float m12, float m21, float m22) {
	matrix2x2* newMat = molloc(sizeof(matrix2x2));
	newMat->m1_1 = m11;
	newMat->m1_2 = m12;
	newMat->m2_1 = m21;
	newMat->m2_2 = m22;
	return newMat;
}

static matrix2x2 matrix2x2_create(float m11, float m12, float m21, float m22) {
	matrix2x2 mat = {m11, m12, m21, m22};
	return mat;
}

static void matrix2x2_printFormat(const matrix2x2 m, int format) {
	printf("{%.*f, %.*f}\n", format, m.m1_1, format, m.m1_2);
	printf("{%.*f, %.*f}", format, m.m2_1, format, m.m2_2);
}

static void matrix2x2_printFloat(const matrix2x2 m) {
	printf("{%f, %f}\n", m.m1_1, m.m1_2);
	printf("{%f, %f}", m.m2_1, m.m2_2);
}

static void matrix2x2_printInt(const matrix2x2 m) {
	matrix2x2_printFormat(m, 0);
}