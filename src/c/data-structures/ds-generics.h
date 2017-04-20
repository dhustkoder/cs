#ifndef CS_DATA_STRUCTURES_DS_GENERICS_H_
#define CS_DATA_STRUCTURES_DS_GENERICS_H_
#include "vector.h"



#define push_back_array(data, size, ds)                 \
        _Generic((ds),                                  \
	Vector*: vector_push_back_array)(data, size, ds)


#define push_back(data, ds)                             \
        _Generic((ds),                                  \
        Vector*: vector_push_back)(data, ds)


#define pop_back(ds)                                    \
        _Generic((ds),                                  \
        Vector*: vector_pop_back)(ds)


#define begin(ds)                                       \
        _Generic((ds),                                  \
        Vector*: vector_begin,                          \
	const Vector*: vector_cbegin)(ds)


#define end(ds)                                         \
        _Generic((ds),                                  \
        Vector*: vector_end,                            \
	const Vector*: vector_cend)(ds)


#define cbegin(ds)                                       \
        _Generic((ds),                                   \
        Vector*: vector_cbegin,                          \
	const Vector*: vector_cbegin)(ds)


#define cend(ds)                                         \
        _Generic((ds),                                   \
        Vector*: vector_cend,                            \
	const Vector*: vector_cend)(ds)



#endif

