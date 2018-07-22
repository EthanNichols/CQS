#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#ifndef VECTOR4
#define VECTOR4
#endif // !vector4


/// vector4 struct
typedef struct
{
	float x;
	float y;
	float z;
	float w;
} vector4;

#pragma region vector4 constructors/destructor functions
/// Allocate and return a new vector
static vector4* vector4_init(float _x, float _y, float _z, float _w) {
	vector4* newVector = malloc(sizeof(vector4));
	newVector->x = _x;
	newVector->y = _y;
	newVector->z = _z;
	newVector->w = _w;
	return newVector;
}

static vector4 vector4_create(float _x, float _y, float _z, float _w) {
	vector4 vec = { _x, _y, _z, _w };
	return vec;
}

/// Allocate and return a new vector where w = 1
static vector4* vector4_v3init(float _x, float _y, float _z) {
	return vector4_init(_x, _y, _z, 1);
}

/// Allocate and return a new vector where w = 1
static vector4 vector4_v3create(float _x, float _y, float _z) {
	vector4 vec = { _x, _y, _z, 1 };
	return vec;
}

/// Copy the values of a vector and create a new one
static vector4* vector4_copy(const vector4 v) {
	vector4* newVector = vector4_init(v.x, v.y, v.z, v.w);
	return newVector;
}

/// Free a vector4 that was allocated
static void vector4_free(vector4* v) {
	free(v);
}
#pragma endregion

#pragma region vector4 math operator functions
/// Return the length of a vector
static float vector4_magnitude(const vector4 v) {
	return sqrtf((v.x * v.x) + (v.y * v.y) + (v.z * v.z) + (v.w * v.w));
}

/// Normalize the values of a vector
static void vector4_normalize(vector4* v) {
	float magnitude = vector4_magnitude(*v);
	v->x /= magnitude;
	v->y /= magnitude;
	v->z /= magnitude;
	v->w /= magnitude;
}

/// Get the normal values of a vector
static vector4 vector4_normal(const vector4 v) {
	vector4 newVector = vector4_create(v.x, v.y, v.z, v.w);
	vector4_normalize(&newVector);
	return newVector;
}

/// Add one vector to another vector to another vector
static void vector4_add(vector4* v1, const vector4 v2) {
	v1->x += v2.x;
	v1->y += v2.y;
	v1->z += v2.z;
	v1->w += v2.w;
}

/// Subtract a vector from another vector
static void vector4_subtract(vector4* v1, const vector4 v2) {
	v1->x -= v2.x;
	v1->y -= v2.y;
	v1->z -= v2.z;
	v1->w += v2.w;
}

/// Multiply a vector by a scalar value
static void vector4_multiply(vector4* v, float scale) {
	v->x *= scale;
	v->y *= scale;
	v->z *= scale;
	v->w *= scale;
}

/// Divide a vector by a scalar value
static void vector4_divide(vector4* v, float scale) {
	v->x /= scale;
	v->y /= scale;
	v->z /= scale;
	v->w *= scale;
}
#pragma endregion

#pragma region vector4 conditional functions
/// Compare if two vectors are the same or not
static bool vector4_compare(const vector4 v1, const vector4 v2) {
	if (v1.x == v2.x &&
		v1.y == v2.y &&
		v1.z == v2.z &&
		v1.w == v2.w) {
		return true;
	}
	return false;
}
#pragma endregion

#pragma region vector4 print functions
/// Print vector values as floats that are formatted
static void vector4_printFormat(const vector4 v, int format) {
	printf("{%.*f, %.*f, %.*f, %.*f}", format, v.x, format, v.y, format, v.z, format, v.w);
}

static void vector4_printFloat(const vector4 v) {
	printf("{%f, %f, %f, %f}", v.x, v.y, v.z, v.w);
}

/// Print vector values as ints (rounded down)
static void vector4_printInt(const vector4 v) {
	vector4_printFormat(v, 0);
}
#pragma endregion


#ifdef VECTOR2
static vector4 vector2_castVector4(const vector2 v) {
	return vector4_create(v.x, v.y, 0, 1);
}
#endif // VECTOR2

/// Functions that requre VECTOR2 to be defined
#ifdef VECTOR3
static vector4 vector3_castVector4(const vector3 v) {
	return vector4_create(v.x, v.y, v.z, 1);
}
#endif // VECTOR3
