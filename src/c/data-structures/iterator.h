#ifndef CS_DATA_STRUCTURES_ITERATOR_H_
#define CS_DATA_STRUCTURES_ITERATOR_H_


typedef union DataStructureInfo {
	int membsize; // vector
	const void* ll; // linked-list
} DataStructureInfo;


typedef struct Iterator {
	DataStructureInfo ds;
	unsigned char* ptr;
	int index;
} Iterator;


typedef struct ConstIterator {
	DataStructureInfo ds;
	const unsigned char* ptr;
	int index;
} ConstIterator;


#endif

