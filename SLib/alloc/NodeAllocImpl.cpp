#include "NodeAllocImpl.h"

#define S_FREELIST_INDEX(__bytes) ((__bytes - size_t(1)) >> (int)MA_ALIGN_SHIFT)

NodeAllocImpl::NodeAllocImpl()
{
}

NodeAllocImpl::~NodeAllocImpl()
{
}


void* NodeAllocImpl::allocate(size_t size)
{
	size = menoryRoundup(size);
	AtomicFreeList::Item* top = freeList_[S_FREELIST_INDEX(size)]->pop();
	if (0 == top){
		top = reFill(size);
	}
}

void* NodeAllocImpl::deAllocate(void* buf, size_t size)
{
	
}

AtomicFreeList::Item* NodeAllocImpl::reFill(size_t size)
{

}