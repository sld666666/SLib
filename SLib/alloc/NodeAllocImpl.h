#ifndef ALLOC_NODEALLOCIMPL_H
#define ALLOC_NODEALLOCIMPL_H
#include "AtomicFreeList.h"

enum MEMORY_ALIGN
{ 
	MA_ALIGN = 2 * sizeof(void*),
	MA_ALIGN_SHIFT = 2 + sizeof(void*) / 4 
};
#define STLP_NFREELISTS 16

class NodeAllocImpl
{
public:
	NodeAllocImpl();
	~NodeAllocImpl();

public:
	static inline size_t menoryRoundup(size_t size){
		//将 bytes ㆖调至 8 的倍数
		return return (((size) + (size_t)MA_ALIGN-1) & ~((size_t)MA_ALIGN - 1));
	}

	void*	allocate(size_t size);
	void*	deAllocate(void* buf, size_t size);

private:
	AtomicFreeList::Item*	reFill(size_t size);

private:
	static AtomicFreeList	freeList_[STLP_NFREELISTS];
	static AtomicFreeList	freeMemBlocks_;

};

NodeAllocImpl::freeList_[STLP_NFREELISTS]
	= {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

NodeAllocImpl::freeMemBlocks_;

#endif // ALLOC_NODEALLOCIMPL_H