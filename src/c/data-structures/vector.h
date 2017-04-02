#ifndef CS_DATA_STRUCTURES_VECTOR_H_
#define CS_DATA_STRUCTURES_VECTOR_H_
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>


typedef struct Vector {
	void* data;
	int bytes;
	int membsize;
	int bidx;
} Vector;


static inline Vector* create_vector(const int nmemb, const int size)
{
	unsigned long long bytes = ((unsigned long long)nmemb) * size;

	if (bytes >= INT_MAX) {
		fprintf(stderr, "Failed to create vector, size in bytes must fit an int variable\n");
		return NULL;
	}

	Vector* const r = malloc(sizeof(Vector));

	if (r == NULL) {
		fprintf(stderr, "Couldn't allocate memory");
		return NULL;
	}

	r->data = malloc(bytes);

	if (r->data == NULL) {
		fprintf(stderr, "Couldn't allocate memory");
		return NULL;
	}

	r->membsize = size;
	r->bytes = bytes;
	r->bidx = 0;
	return r;
}


static inline void destroy_vector(Vector* const v)
{
	free(v->data);
	free(v);
}


static inline bool vector_resize(unsigned long long bytes, Vector* const v)
{
	unsigned long long newbytes = bytes + v->bytes;

	if (newbytes >= INT_MAX) {
		fprintf(stderr, "Couldn't resize vector.");
		return false;
	}

	v->data = realloc(v->data, newbytes);

	if (v->data == NULL) {
		fprintf(stderr, "Couldn't allocate memory");
		return false;
	}

	v->bytes = (int) newbytes;
	return true;
}


static inline bool vector_ensure_capacity(const int nelem, Vector* const v)
{
	const unsigned long long bidx = v->bidx;
	const unsigned long long membsize = v->membsize;
	const unsigned long long newidx = bidx + membsize * nelem;

	if (newidx > (unsigned long long) v->bytes)
		return vector_resize(newidx + ((bidx / membsize) / 2), v);

	return true;
}


static inline void vector_push_back(const void* const data, Vector* const v)
{
	if (!vector_ensure_capacity(1, v))
		return;

	char* const p = (char*) v->data;
	memcpy(&p[v->bidx], data, v->membsize);
	v->bidx += v->membsize;
}


static inline void vector_push_back_array(const void* const data, const int size, Vector* const v)
{
	if (!vector_ensure_capacity(size, v))
		return;

	char* const p = (char*) v->data;
	memcpy(&p[v->bidx], data, v->membsize * size);
	v->bidx += v->membsize * size;
}


static inline void vector_pop_back(Vector* const v)
{
	if (v->bidx > 0)
		v->bidx -= v->membsize;
}


#define push_back_array(data, size, dest) \
	_Generic((dest), Vector*: vector_push_back_array)(data, size, dest)

#define push_back(data, dest) \
	_Generic((dest), Vector*: vector_push_back)(data, dest)


#endif

