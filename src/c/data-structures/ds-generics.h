#ifndef CS_DATA_STRUCTURES_DS_GENERICS_H_
#define CS_DATA_STRUCTURES_DS_GENERICS_H_
#include "vector.h"



#define push_back_array(data, size, dest)                 \
        _Generic((dest),                                  \
	Vector*: vector_push_back_array)(data, size, dest)

#define push_back(data, dest)                             \
        _Generic((dest),                                  \
        Vector*: vector_push_back)(data, dest)


#endif
