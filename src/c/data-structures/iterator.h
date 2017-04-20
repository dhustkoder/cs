#ifndef CS_DATA_STRUCTURES_ITERATOR_H_
#define CS_DATA_STRUCTURES_ITERATOR_H_


typedef struct Iterator {
	const void* const ds;
	void* elem;
	int index;
} Iterator;


typedef struct ConstIterator {
	const void* const ds;
	const void* elem;
	int index;
} ConstIterator;


#endif

