#ifndef CS_DATA_STRUCTURES_VECTOR_H_
#define CS_DATA_STRUCTURES_VECTOR_H_
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#include "iterator.h"


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

	Vector* const v = malloc(sizeof(Vector));

	if (v == NULL) {
		fprintf(stderr, "Couldn't allocate memory");
		return NULL;
	}

	v->data = malloc(bytes);

	if (v->data == NULL) {
		fprintf(stderr, "Couldn't allocate memory");
		return NULL;
	}

	v->membsize = size;
	v->bytes = bytes;
	v->bidx = 0;
	return v;
}


static inline void destroy_vector(Vector* const v)
{
	free(v->data);
	free(v);
}


static inline bool vector_resize(unsigned long long bytes, Vector* const v)
{
	unsigned long long newbytes = bytes;

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


static inline bool vector_ensure_capacity(const unsigned long long bytes, Vector* const v)
{
	if (bytes > (unsigned long long) v->bytes)
		return vector_resize(bytes + (bytes / 2), v);

	return true;
}


static inline void vector_push_back(const void* const data, Vector* const v)
{
	if (!vector_ensure_capacity(v->bidx + v->membsize, v))
		return;

	char* const p = (char*) v->data;
	memcpy(&p[v->bidx], data, v->membsize);
	v->bidx += v->membsize;
}


static inline void vector_push_back_array(const void* const data, const int size, Vector* const v)
{
	if (!vector_ensure_capacity(v->bidx + size * v->membsize, v))
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


static inline ConstIterator vector_cbegin(const Vector* const v)
{
	ConstIterator it = {v, v->data, 0};
	return it;
}


static inline ConstIterator vector_cend(const Vector* const v)
{
	ConstIterator it = {v, ((char*)v->data) + v->bidx, v->bidx / v->membsize};
	return it;
}


static inline Iterator vector_begin(Vector* const v)
{
	ConstIterator cit = vector_cbegin(v);
	Iterator it = {cit.ds, (void*)cit.ptr, cit.index};
	return it;
}


static inline Iterator vector_end(Vector* const v)
{
	ConstIterator cit = vector_cend(v);
	Iterator it = {cit.ds, (void*)cit.ptr, cit.index};
	return it;
}


static inline void vector_cadvance(ConstIterator* const it, const int n)
{
	assert(n != 0);

	const Vector* const v = it->ds;
	it->ptr = ((char*)it->ptr) + v->membsize * n;

	if (((char*)it->ptr) > &((char*)v->data)[v->bidx]) {
		it->ptr = &((char*)v->data)[v->bidx];
		it->index = v->bidx / v->membsize;
	} else {
		it->index += n > 0 ? 1 : -1;
	}
}


static inline void vector_advance(Iterator* const it, const int n)
{
	ConstIterator cit = {it->ds, it->ptr, it->index};
	vector_cadvance(&cit, n);
	it->ptr = (void*) cit.ptr;
	it->index = cit.index;
}



#endif

