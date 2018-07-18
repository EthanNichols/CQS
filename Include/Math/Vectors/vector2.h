#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
	float x;
	float y;
} vector2;

/// Malloc space for a new vector
static vector2* vector2_init(float _x, float _y) {
	vector2* newVector = malloc(sizeof(vector2));
	newVector->x = _x;
	newVector->y = _y;
	return newVector;
}

/// Copy the values of a vector and create a new one
static vector2* vector2_copy(const vector2 v) {
	vector2* newVector = vector2_init(v.x, v.y);
	return newVector;
}

static void vector2_free(vector2* v) {
	free(v);
}

/// Compare if two vectors are the same or not
static bool vector2_compare(const vector2 v1, const vector2 v2) {
	if (v1.x == v2.x &&
		v1.y == v2.y) {
		return true;
	}
	return false;
}

/// Normalize the values of a vector
static void vector2_normalize(vector2* v) {
	float length = v->x * v->y;
	v->x /= length;
	v->y /= length;
}

/// Get the normal values of a vector
static vector2* vector2_normal(const vector2 v) {
	vector2* newVector = vector2_init(v.x, v.y);
	vector2_normalize(newVector);
	return newVector;
}

static void vector2_multiply(vector2* v, float scale) {
	v->x *= scale;
	v->y *= scale;
}

static void vector2_add(vector2* v1, const vector2 v2) {
	v1->x += v2.x;
	v1->y += v2.y;
}

/// Print vector values as floats that are formatted
static void vector2_printFormat(const vector2 v, int format) {
	printf("{%.*f, %.*f}", format, v.x, format, v.y);
}

static void vector2_printFloat(const vector2 v) {
	printf("{%f, %f}", v.x, v.y);
}

/// Print vector values as ints (rounded down)
static void vector2_printInt(const vector2 v) {
	vector2_printFormat(v, 0);
}