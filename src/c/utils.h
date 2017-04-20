#ifndef CS_UNUSED_H_
#define CS_UNUSED_H_

#define UNUSED(x) ((void)x)


typedef int(*CmpFun)(const void*, const void*);
typedef void(*NextFun)(Iterator*, int);
typedef void(*PrevFun)(Iterator*, int);
typedef void(*ConstNextFun)(ConstIterator*, int);
typedef void(*ConstPrevFun)(ConstIterator*, int);
typedef const void*(*SearchFun)(ConstIterator, ConstIterator, const void*, CmpFun, ConstNextFun, ConstPrevFun);
typedef void(*SortFun)(void*, int, int, CmpFun);


#endif

