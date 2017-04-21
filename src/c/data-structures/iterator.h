#ifndef CS_DATA_STRUCTURES_ITERATOR_H_
#define CS_DATA_STRUCTURES_ITERATOR_H_


typedef struct Iterator {
	const void* const ds;
	unsigned char* ptr;
	int index;
} Iterator;


typedef struct ConstIterator {
	const void* const ds;
	const unsigned char* ptr;
	int index;
} ConstIterator;


#endif

