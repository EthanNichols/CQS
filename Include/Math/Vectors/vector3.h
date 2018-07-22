#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#ifndef VECTOR3
#define VECTOR3
#endif // !VECTOR3


/// vector3 struct
typedef struct
{
	float x;
	float y;
	float z;
} vector3;

#pragma region vector3 constructors/destructor functions
/// Allocate and return a new vector
static vector3* vector3_init(float _x, float _y, float _z) {
	vector3* newVector = malloc(sizeof(vector3));
	newVector->x = _x;
	newVector->y = _y;
	newVector->z = _z;
	return newVector;
}

static vector3 vector3_create(float _x, float _y, float _z) {
	vector3 vec = { _x, _y, _z };
	return vec;
}

/// Allocate and return a new vector where z = 1
static vector3* vector3_v2init(float _x, float _y) {
	return vector3_init(_x, _y, 1);
}

static vector3 vector3_v2create(float _x, float _y) {
	vector3 vec = { _x, _y, 1 };
	return vec;
}

/// Copy the values of a vector and create a new one
static vector3* vector3_copy(const vector3 v) {
	vector3* newVector = vector3_init(v.x, v.y, v.z);
	return newVector;
}

/// Free a vector3 that was allocated
static void vector3_free(vector3* v) {
	free(v);
}
#pragma endregion

#pragma region vector3 math operator functions
/// Return the length of a vector
static float vector3_magnitude(const vector3 v) {
	return sqrtf((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
}

/// Normalize the values of a vector
static void vector3_normalize(vector3* v) {
	float magnitude = vector3_magnitude(*v);
	v->x /= magnitude;
	v->y /= magnitude;
	v->z /= magnitude;
}

/// Get the normal values of a vector
static vector3* vector3_normal(const vector3 v) {
	vector3* newVector = vector3_init(v.x, v.y, v.z);
	vector3_normalize(newVector);
	return newVector;
}

/// Add one vector to another vector to another vector
static void vector3_add(vector3* v1, const vector3 v2) {
	v1->x += v2.x;
	v1->y += v2.y;
	v1->z += v2.z;
}

/// Subtract a vector from another vector
static void vector3_subtract(vector3* v1, const vector3 v2) {
	v1->x -= v2.x;
	v1->y -= v2.y;
	v1->z -= v2.z;
}

/// Multiply a vector by a scalar value
static void vector3_multiply(vector3* v, float scale) {
	v->x *= scale;
	v->y *= scale;
	v->z *= scale;
}

/// Divide a vector by a scalar value
static void vector3_divide(vector3* v, float scale) {
	v->x /= scale;
	v->y /= scale;
	v->z /= scale;
}
#pragma endregion

#pragma region vector3 conditional functions
/// Compare if two vectors are the same or not
static bool vector3_compare(const vector3 v1, const vector3 v2) {
	if (v1.x == v2.x &&
		v1.y == v2.y &&
		v1.z == v2.z) {
		return true;
	}
	return false;
}
#pragma endregion

#pragma region vector3 print functions
/// Print vector values as floats that are formatted
static void vector3_printFormat(const vector3 v, int format) {
	printf("{%.*f, %.*f, %.*f}", format, v.x, format, v.y, format, v.z);
}

static void vector3_printFloat(const vector3 v) {
	printf("{%f, %f, %f}", v.x, v.y, v.z);
}

/// Print vector values as ints (rounded down)
static void vector3_printInt(const vector3 v) {
	vector3_printFormat(v, 0);
}
#pragma endregion

/// Functions that requre VECTOR2 to be defined
#ifdef VECTOR2
static vector3 vector3_castvector2(const vector2 v) {
	return vector3_create(v.x, v.y, 1);
}
#endif // VECTOR2

#ifdef VECTOR4
static vector3 vector3_castvector4(const vector4 v) {
	return vector3_create(v.x, v.y, v.z);
}
#endif