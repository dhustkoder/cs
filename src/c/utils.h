#ifndef CS_UNUSED_H_
#define CS_UNUSED_H_

#define UNUSED(x) ((void)x)


typedef int(*CmpFun)(const void*, const void*);
typedef void(*SwapFun)(void*, void*);
typedef Iterator(*AdvanceFun)(Iterator, int);
typedef ConstIterator(*ConstAdvanceFun)(ConstIterator, int);
typedef ConstIterator(*SearchFun)(ConstIterator, ConstIterator, const void*, CmpFun, ConstAdvanceFun);
typedef void(*SortFun)(Iterator, Iterator, SwapFun, CmpFun, AdvanceFun);


#endif

