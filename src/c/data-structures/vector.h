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
	unsigned char* data;
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

	if (v == NULL)
		goto vec_fail;

	v->data = malloc(bytes);

	if (v->data == NULL)
		goto data_fail;

	v->membsize = size;
	v->bytes = bytes;
	v->bidx = 0;
	return v;

data_fail:
	free(v);
vec_fail:
	fprintf(stderr, "Couldn't allocate memory\n");
	return NULL;
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

	memcpy(v->data + v->bidx, data, v->membsize);
	v->bidx += v->membsize;
}


static inline void vector_push_back_array(const void* const data, const int size, Vector* const v)
{
	if (!vector_ensure_capacity(v->bidx + size * v->membsize, v))
		return;

	memcpy(v->data + v->bidx, data, v->membsize * size);
	v->bidx += v->membsize * size;
}


static inline void vector_pop_back(Vector* const v)
{
	if (v->bidx > 0)
		v->bidx -= v->membsize;
}


static inline ConstIterator vector_cbegin(const Vector* const v)
{
	const ConstIterator it = { .ds.membsize = v->membsize,
		v->data,
		0
	};
	return it;
}


static inline ConstIterator vector_cend(const Vector* const v)
{
	const ConstIterator it = { .ds.membsize =  v->membsize,
		v->data + v->bidx,
		v->bidx / v->membsize
	};
	return it;
}


static inline ConstIterator vector_cadvance(const ConstIterator it, const int n)
{
	const ConstIterator r = { it.ds, it.ptr + it.ds.membsize * n, it.index + n };
	return r;
}


static inline Iterator vector_begin(const Vector* const v)
{
	const ConstIterator cit = vector_cbegin(v);
	const Iterator it = { cit.ds, (void*)cit.ptr, cit.index };
	return it;
}


static inline Iterator vector_end(const Vector* const v)
{
	const ConstIterator cit = vector_cend(v);
	const Iterator it = { cit.ds, (void*)cit.ptr, cit.index };
	return it;
}


static inline Iterator vector_advance(const Iterator it, const int n)
{
	const ConstIterator ip = { it.ds, it.ptr, it.index };
	const ConstIterator ir = vector_cadvance(ip, n);
	const Iterator r = { ir.ds, (void*)ir.ptr, ir.index };
	return r;
}



#endif

