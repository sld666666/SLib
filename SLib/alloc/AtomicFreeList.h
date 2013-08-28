#ifndef ALLOC_ATOMICFREELIST_H
#define ALLOC_ATOMICFREELIST_H
#include "winnt.h"

class AtomicFreeList
{
public:
	typedef SLIST_ENTRY Item;
	
public:
	AtomicFreeList(){
		InitializeSListHead(&slistHeaer_);
	}
	~AtomicFreeList(){}
	
	void push(Item* item){
		InterlockedPushEntrySList(&slistHeaer_, item);
	}

	Item* pop(){
		return InterlockedPopEntrySList(&slistHeaer_);
	}

	Item* clear(){
		return InterlockedFlushSList(&slistHeaer_);
	}
	
private:
	SLIST_HEADER slistHeaer_;
	
};

#endif // ALLOC_ATOMICFREELIST_H