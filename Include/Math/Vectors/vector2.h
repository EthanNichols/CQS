#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#ifndef VECTOR2
#define VECTOR2
#endif // !VECTOR2

/// Vector2 struct
typedef struct
{
	float x;
	float y;
} vector2;

#pragma region Vector2 constructors/destructor functions
/// Allocate and return a new vector
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

/// Free a vector2 that was allocated
static void vector2_free(vector2* v) {
	free(v);
}
#pragma endregion

#pragma region Vector2 calculation functions
/// Return the length of a vector
static float vector2_magnitude(const vector2 v) {
	return sqrtf((v.x * v.x) + (v.y * v.y));
}

/// Normalize the values of a vector
static void vector2_normalize(vector2* v) {
	float magnitude = vector2_magnitude(*v);
	v->x /= magnitude;
	v->y /= magnitude;
}

/// Get the normal values of a vector
static vector2* vector2_normal(const vector2 v) {
	vector2* newVector = vector2_init(v.x, v.y);
	vector2_normalize(newVector);
	return newVector;
}

/// Return the magnitude of two vectors
static float vector2_dotproduct(const vector2 v1, const vector2 v2) {
	return v1.x * v2.x + v1.y * v2.y;
}

/// Calculate and return the perpendicular vector to two vectors
static vector2* vector2_crossproduct(const vector2 v1, const vector2 v2) {
	float x = v1.y - v2.y;
	float y = v2.x - v1.x;
	return vector2_init(x, y);
}

/// Calculate and return the angle between two vectors
static float vector2_angle(const vector2 v1, const vector2 v2) {
	return acos(vector2_dotproduct(v1, v2) / (vector2_magnitude(v1) * vector2_magnitude(v2))) * 100;
}
#pragma endregion

#pragma region Vector2 math operator functions

/// Add one vector to another vector to another vector
static void vector2_add(vector2* v1, const vector2 v2) {
	v1->x += v2.x;
	v1->y += v2.y;
}

/// Subtract a vector from another vector
static void vector2_subtract(vector2* v1, const vector2 v2) {
	v1->x -= v2.x;
	v1->y -= v2.y;
}

/// Multiply a vector by a scalar value
static void vector2_multiply(vector2* v, float scale) {
	v->x *= scale;
	v->y *= scale;
}

/// Divide a vector by a scalar value
static void vector2_divide(vector2* v, float scale) {
	v->x /= scale;
	v->y /= scale;
}
#pragma endregion

#pragma region Vector2 conditional functions
/// Compare if two vectors are the same or not
static bool vector2_compare(const vector2 v1, const vector2 v2) {
	if (v1.x == v2.x &&
		v1.y == v2.y) {
		return true;
	}
	return false;
}
#pragma endregion

#pragma region Vector2 print functions
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
#pragma endregion