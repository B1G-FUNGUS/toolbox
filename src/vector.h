#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

// example: vector(int) my_vector;
#define vec(type) \
	struct { \
		size_t length; \
		type *v; \
	} // name goes here

#define vinit(vec) \
	vec.length = 0; \
	vec.v = NULL;

// example: append(my_vector, 0);
#define append(vec, elem) \
	vec.v = (typeof(vec.v)) reallocarray(vec.v, ++(vec.length), \
		sizeof(*vec.v)); \
	if (vec.v == NULL) {  \
		printf("append: ran out of memory!"); \
		exit(1); \
	} else { \
		vec.v[vec.length-1] = elem; \
	}

#define getelem(vec, i) vec.v[i]

#define vfree(vec) free(vec.v)

// TODO add vectors with buffers

// TODO add alloca vectors?

// TODO add resizing macro

#endif
