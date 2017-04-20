#ifndef CS_UNUSED_H_
#define CS_UNUSED_H_

#define UNUSED(x) ((void)x)


typedef int(*CmpFun)(const void*, const void*);
typedef void(*AdvanceFun)(Iterator*, int);
typedef void(*ConstAdvanceFun)(ConstIterator*, int);
typedef const void*(*SearchFun)(ConstIterator, ConstIterator, const void*, CmpFun, ConstAdvanceFun advance);
typedef void(*SortFun)(void*, int, int, CmpFun);


#endif

