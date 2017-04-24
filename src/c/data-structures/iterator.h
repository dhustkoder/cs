#ifndef CS_DATA_STRUCTURES_ITERATOR_H_
#define CS_DATA_STRUCTURES_ITERATOR_H_


typedef struct Iterator {
	union {
		int membsize;
		const void* ll;
	};
	unsigned char* ptr;
	int index;
} Iterator;


typedef struct ConstIterator {
	union {
		int membsize;
		const void* ll;
	};
	const unsigned char* ptr;
	int index;
} ConstIterator;


#endif

