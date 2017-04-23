#ifndef CS_DATA_STRUCTURES_DS_GENERICS_H_
#define CS_DATA_STRUCTURES_DS_GENERICS_H_
#include "vector.h"
#include "linked-list.h"


#define push_back_array(data, size, ds)                    \
        _Generic((ds),                                     \
	Vector*: vector_push_back_array)(data, size, ds)


#define push_back(data, ds)                                \
        _Generic((ds),                                     \
        Vector*: vector_push_back,                         \
        LinkedList*: linked_list_push_back)(data, ds)


#define pop_back(ds)                                       \
        _Generic((ds),                                     \
        Vector*: vector_pop_back,                          \
        LinkedList*: linked_list_pop_back)(ds)


#define begin(ds)                                          \
        _Generic((ds),                                     \
        Vector*: vector_begin,                             \
        const Vector*: vector_cbegin,                      \
	LinkedList*: linked_list_begin,                    \
	const LinkedList*: linked_list_cbegin)(ds)

#define end(ds)                                            \
        _Generic((ds),                                     \
        Vector*: vector_end,                               \
        const Vector*: vector_cend,                        \
	LinkedList*: linked_list_end,                      \
	const LinkedList*: linked_list_cend)(ds)


#define cbegin(ds)                                         \
        _Generic((ds),                                     \
        Vector*: vector_cbegin,                            \
        const Vector*: vector_cbegin,                      \
	LinkedList*: linked_list_cbegin,                   \
	const LinkedList*: linked_list_cbegin)(ds)


#define cend(ds)                                           \
        _Generic((ds),                                     \
        Vector*: vector_cend,                              \
        const Vector*: vector_cend,                        \
	LinkedList*: linked_list_cend,                     \
	const LinkedList*: linked_list_cend)(ds)

#endif

